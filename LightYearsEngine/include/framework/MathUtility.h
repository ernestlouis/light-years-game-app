#pragma once
#include <SFML/Graphics.hpp>

namespace ly
{
	sf::Vector2f Rotation_To_Vector(float rotation);
	float Degrees_To_Radians(float degrees);
	float Radians_To_Degrees(float radians);

	template<typename T>
	float Get_Vector_Length(sf::Vector2<T> &vector);

	template<typename T>
	sf::Vector2<T> Scale_Vector(sf::Vector2<T> &vector_to_scale, float amt);

	template<typename T>
	sf::Vector2<T>& Normalize(sf::Vector2<T>& vector);
}

template<typename T>
float ly::Get_Vector_Length(sf::Vector2<T> &vector)
{
	return std::sqrt(vector.x * vector.x * vector.y * vector.y);
}

template<typename T>
sf::Vector2<T> ly::Scale_Vector(sf::Vector2<T> &vector_to_scale, float amt)
{
	vector_to_scale.x *= amt;
	vector_to_scale.y *= amt;
	return vector_to_scale;
}

template<typename T>
sf::Vector2<T>& ly::Normalize(sf::Vector2<T>& vector)
{
	float vector_length = Get_Vector_Length<T>(vector);
	if (vector_length == 0.f) return sf::Vector2<T>{};

	Scale_Vector(vector, 1.0/vector_length);

	return vector;
}
