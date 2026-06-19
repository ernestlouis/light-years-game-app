#include "framework/MathUtility.h"

namespace ly
{
	const float PI = 3.1415926535;

	sf::Vector2f Rotation_To_Vector(float rotation)
	{
		float radians = Degrees_To_Radians(rotation);
		return sf::Vector2f(std::cos(radians), std::sin(radians));
	}

	float Degrees_To_Radians(float degrees)
	{
		return degrees * (PI / 180.f);
	}

	float Radians_To_Degrees(float radians)
	{
		return radians * (180.f/PI);
	}

}