#include "player/PlayerSpaceship.h"
#include "SFML/System.hpp"

namespace ly
{
	PlayerSpaceship::PlayerSpaceship(World* owning_world, const std::string& path)
		:Spaceship{ owning_world, path },
		m_move_input{},
		m_speed{200.f}
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

	void PlayerSpaceship::Handle_Input()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			m_move_input.y = -1.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_move_input.y = 1.f;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_move_input.x = -1.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_move_input.x = 1.f;
		}

	}

	void PlayerSpaceship::Consume_Input(float delta_time)
	{
		Set_Velocity(m_move_input * m_speed);
		m_move_input.x = m_move_input.y = 0.f;
	}

}