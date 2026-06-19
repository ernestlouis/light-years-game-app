#include "spaceship/Spaceship.h"

namespace ly
{
	Spaceship::Spaceship(World* owning_world, const std::string& texture_path)
		:Actor{ owning_world, texture_path }, m_velocity{}
	{

	}
	void Spaceship::Tick(float delta_time)
	{
		Actor::Tick(delta_time);
		Add_Actor_Location_Offset(Get_Velocity() * delta_time);
	}
	void Spaceship::Set_Velocity(const sf::Vector2f& new_velocity)
	{
		m_velocity = new_velocity;
	}
	sf::Vector2f Spaceship::Get_Velocity() const
	{
		return m_velocity;
	}
}