#pragma once
#include "spaceship/Spaceship.h"

namespace ly
{
	class PlayerSpaceship : public Spaceship
	{
		public:
			PlayerSpaceship(World* owning_world, const std::string & path = "SpaceShooterRedux/PNG/playerShip1_blue.png");

			virtual void Tick(float delta_time) override;
			void Set_Speed(float new_speed);
			float Get_Speed() const;
		private:
			void Handle_Input();
			void Consume_Input(float delta_time);
			sf::Vector2f m_move_input;
			float m_speed;
	};
}