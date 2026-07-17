#pragma once
#include "spaceship/Spaceship.h"
//#include "weapon/BulletShooter.h"

namespace ly
{
	class BulletShooter;
	class PlayerSpaceship : public Spaceship
	{
		public:
			PlayerSpaceship(World* owning_world, const std::string & path = "SpaceShooterRedux/PNG/playerShip1_blue.png");

			virtual void Tick(float delta_time) override;
			void Set_Speed(float new_speed);
			float Get_Speed() const;
			virtual void Shoot() override;
		private:
			void Handle_Input();
			void Normalize_Input();
			void Clamp_Input_On_Edge();
			void Consume_Input(float delta_time);
			sf::Vector2f m_move_input;
			float m_speed;

			unique<BulletShooter> m_shooter;
	};
}