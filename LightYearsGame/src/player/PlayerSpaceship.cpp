#include "player/PlayerSpaceship.h"
#include "SFML/System.hpp"
#include "framework/MathUtility.h"
#include "weapon/BulletShooter.h"

namespace ly
{
	PlayerSpaceship::PlayerSpaceship(World* owning_world, const std::string& path)
		:Spaceship{ owning_world, path },
		m_move_input{},
		m_speed{200.f},
		m_shooter{ new BulletShooter{this}}
	{

	}

	void PlayerSpaceship::Tick(float delta_time)
	{
		Spaceship::Tick(delta_time);
		Handle_Input();
		Consume_Input(delta_time);
	}

	void PlayerSpaceship::Set_Speed(float new_speed)
	{
		m_speed = new_speed;
	}

	float PlayerSpaceship::Get_Speed() const
	{
		return m_speed;
	}

	void PlayerSpaceship::Shoot()
	{
		if (m_shooter)
		{
			m_shooter->Shoot();
		}
	}

	void PlayerSpaceship::Handle_Input()
	{
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
		{
			m_move_input.y = -1.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_move_input.y = 1.f;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
		{
			m_move_input.x = -1.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
		{
			m_move_input.x = 1.f;
		}

		Clamp_Input_On_Edge();
		Normalize_Input();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			Shoot();
		}
	}

	void PlayerSpaceship::Normalize_Input()
	{
		Normalize(m_move_input);
	}
	//sf::Vector2f(300.f, 450.f)
	void PlayerSpaceship::Clamp_Input_On_Edge()
	{
		sf::Vector2f actor_location = Get_Actor_Location();
		if (actor_location.x < 0.f && m_move_input.x == -1.f)
		{
			m_move_input.x = 0.f;
		}

		if (actor_location.x > Get_Window_Size().x && m_move_input.x == 1.f)
		{
			m_move_input.x = 0.f;
		}

		if (actor_location.y < 0.f && m_move_input.y == -1.f)
		{
			m_move_input.y = 0.f;
		}

		if (actor_location.y > Get_Window_Size().y && m_move_input.y == 1.f)
		{
			m_move_input.y = 0.f;
		}

	}

	void PlayerSpaceship::Consume_Input(float delta_time)
	{
		Set_Velocity(m_move_input * m_speed);
		m_move_input.x = m_move_input.y = 0.f;
	}

}


