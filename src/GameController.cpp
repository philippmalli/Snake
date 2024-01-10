#include "GameController.h"

void GameController::Run()
{
  KeyboardInputHandler inputHandler(snake, action);
  SpawnFruit();

  auto screen = ftxui::ScreenInteractive::FitComponent();

  auto renderer = ftxui::Renderer([&] { return currentView; });

  renderer |= ftxui::CatchEvent(
    [&](ftxui::Event event)
    {
      inputHandler.ProcessInput(event);
      return true;
    });

  std::thread myThread([&]() { screen.Loop(renderer); });

  while (action == GameAction::Continue)// && !loop.HasQuitted() )
  {
    const auto timerStart = std::chrono::high_resolution_clock::now();

    snake.UpdatePosition();
    HandleCollision();
    Draw(screen);

    screen.PostEvent(ftxui::Event::Custom);

    turnsSinceFruitSpawn++;

    const auto timerEnd = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(timerEnd - timerStart);

    std::this_thread::sleep_for(std::chrono::milliseconds(200) - duration);
  }

  DrawGameOverScreen(screen);
  screen.PostEvent(ftxui::Event::Custom);

  std::this_thread::sleep_for(std::chrono::milliseconds(3000));

  screen.Exit();
  myThread.join();

  return;
}

void GameController::SpawnFruit()
{
  bool success{ false };
  while (!success)
  {
    Position position{ .x = rngDistX(rngEngine), .y = rngDistY(rngEngine) };
    if (DetectCollison(position, snake.GetTail()) == CollisionResult::NoCollision)
    {
      fruits.push_back(std::move(position));
      success = true;
    }
  }

  turnsSinceFruitSpawn = 0;
}

void GameController::HandleCollision()
{
  if (snake.ColllidedWithEdge())
  {
    action = GameAction::ExitGame;
    return;
  }

  const auto playerPosition = snake.GetHeadPosition();
  HandleCollisionFruit(playerPosition);

  const auto tailCollision = DetectCollison(playerPosition, snake.GetTailCollider());
  if (tailCollision == CollisionResult::Collision) { action = GameAction::ExitGame; }
}

void GameController::HandleCollisionFruit(const Position &playerPosition)
{
  const auto fruitIterator =
    std::find_if(fruits.begin(), fruits.end(), [playerPosition](auto position) { return playerPosition == position; });

  if (fruitIterator != std::end(fruits))
  {
    snake.shouldAddSegment = true;
    score += CalculateScoreIncrement();
    fruits.erase(fruitIterator);
    SpawnFruit();
  }
}

CollisionResult GameController::DetectCollison(const Position &playerPosition,
  const std::vector<Position> &colliders) const
{
  if (colliders.empty()) { return CollisionResult::NoCollision; }
  const auto colliderIterator = std::find_if(colliders.begin(),
    colliders.end(),
    [playerPosition](auto colliderPosition) { return playerPosition == colliderPosition; });

  if (colliderIterator != std::end(colliders)) { return CollisionResult::Collision; }
  return CollisionResult::NoCollision;
}

void GameController::Draw(Screen &screen)
{
  canvas.Clear();
  canvas.SetBorder();
  canvas.AddTail(snake.GetTail());
  canvas.AddPlayer(snake.GetHeadPosition());
  canvas.AddFruit(fruits);
  canvas.SetScore(score);

  currentView = canvas.CreateView();
  screen.PostEvent(ftxui::Event::Custom);
}

void GameController::DrawGameOverScreen(Screen &screen)
{
  currentView = canvas.CreateGameOverScreen();
  screen.PostEvent(ftxui::Event::Custom);
}

int GameController::CalculateScoreIncrement()
{
  if (turnsSinceFruitSpawn > 99) { turnsSinceFruitSpawn = 99; }
  return 10 - (turnsSinceFruitSpawn / 10);
}