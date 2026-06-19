#pragma once
#include <SFML/Graphics.hpp>

namespace ly
{
	sf::Vector2f Rotation_To_Vector(float rotation);
	float Degrees_To_Radians(float degrees);
	float Radians_To_Degrees(float radians);
}