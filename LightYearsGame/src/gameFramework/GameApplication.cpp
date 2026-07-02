#include "gameFramework/GameApplication.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "framework/AssetManager.h"
#include "player/PlayerSpaceship.h"
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

		AssetManager::Get().Set_Asset_Root_Directory(Get_Resource_Dir());
		weak<World> new_world = Load_World<World>();
		new_world.lock()->Spawn_Actor<Actor>();
		test_player_spaceship = new_world.lock()->Spawn_Actor<PlayerSpaceship>();
		test_player_spaceship.lock()->Set_Actor_Location(sf::Vector2f(300.f, 450.f));
		test_player_spaceship.lock()->Set_Actor_Rotation(0.f);

		

	}

	void GameApplication::Tick(float delta_time)
	{

	}
}