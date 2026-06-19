#include "gameFramework/GameApplication.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "spaceship/Spaceship.h"
#include "config.h"


ly::unique<ly::Application> GetApplication()
{
	return ly::unique<ly::Application>(new ly::GameApplication());
}

namespace ly
{
	GameApplication::GameApplication()
		:Application{600,900,"Light Years",sf::Style::Titlebar | sf::Style::Close}
	{
		weak<World> new_world = Load_World<World>();
		new_world.lock()->Spawn_Actor<Actor>();
		test_player_spaceship = new_world.lock()->Spawn_Actor<Spaceship>();
		test_player_spaceship.lock()->Set_Texture(Get_Resource_Dir() + "SpaceShooterRedux/PNG/playerShip1_blue.png");
		test_player_spaceship.lock()->Set_Actor_Location(sf::Vector2f(300.f, 450.f));
		test_player_spaceship.lock()->Set_Actor_Rotation(0.f);
		test_player_spaceship.lock()->Set_Velocity(sf::Vector2f(0.f, -200.f));
		counter = 0;
	}

	void GameApplication::Tick(float delta_time)
	{

	}
}