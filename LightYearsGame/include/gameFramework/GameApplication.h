#pragma once
#include<framework/Application.h>
#include<framework/Core.h>

namespace ly
{
	class Actor;
	class PlayerSpaceship;
	class GameApplication : public Application
	{
	public:
		GameApplication();
		virtual void Tick(float delta_time) override;

	private:
		float counter{};
		weak<PlayerSpaceship> test_player_spaceship;
	};
}