#pragma once

#include <string>
#include "ftxui/component/event.hpp"
// #include "cpp-terminal/key.hpp"

/// <summary>
/// define possble actions on keys
/// </summary>
enum class KeyAction {Up, Down, Left, Right, Exit, Any};

/// <summary>
/// get key from the entered character
/// </summary>
/// <param name="enteredCharacter"></param>
/// <returns></returns>
KeyAction getKeyFromChar(char enteredCharacter);

KeyAction getKeyActionFromEvent(ftxui::Event event);

// KeyAction getActionFromKey(Term::Key key);

/// <summary>
///
///  /// </summary>/// <param name="key"></param>/// <returns></returns>
std::string keyToString(KeyAction key);