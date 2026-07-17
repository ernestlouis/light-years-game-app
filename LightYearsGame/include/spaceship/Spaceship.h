#pragma once
#include "framework/Actor.h"

namespace ly
{
	class Spaceship : public Actor
	{
	public:
		Spaceship(World* owning_world, const std::string& texture_path = " ");
		virtual void Tick(float delta_time) override;
		void Set_Velocity(const sf::Vector2f& new_velocity);
		sf::Vector2f Get_Velocity() const;
		virtual void Shoot();

	private:
		sf::Vector2f m_velocity;
	};
}