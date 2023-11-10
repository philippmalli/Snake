#pragma once
#include <cstdint>

/// <summary>
/// define the boundary of the playing field
/// </summary>
struct Boundary
{
	uint16_t xMin;
	uint16_t xMax;
	uint16_t yMin;
	uint16_t yMax;
};