#include "gameFramework/GameApplication.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "framework/Actor.h"
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
		actor_to_destroy = new_world.lock()->Spawn_Actor<Actor>();
		actor_to_destroy.lock()->Set_Texture(Get_Resource_Dir() + "SpaceShooterRedux/PNG/playerShip1_blue.png");
		actor_to_destroy.lock()->Set_Actor_Location(sf::Vector2f(300.f, 450.f));
		actor_to_destroy.lock()->Set_Actor_Rotation(90.f);
		counter = 0;
	}

	void GameApplication::Tick(float delta_time)
	{

	}
}