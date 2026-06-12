#include "gameFramework/GameApplication.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "framework/Actor.h"


ly::unique<ly::Application> GetApplication()
{
	return ly::unique<ly::Application>(new ly::GameApplication());
}

namespace ly
{
	GameApplication::GameApplication()
	{
		weak<World> new_world = Load_World<World>();
		new_world.lock()->Spawn_Actor<Actor>();
		actor_to_destroy = new_world.lock()->Spawn_Actor<Actor>();
		counter = 0;

	}
	void GameApplication::Tick(float delta_time)
	{
		counter += delta_time;
		if (counter > 2.f)
		{
			if (!actor_to_destroy.expired())
			{
				actor_to_destroy.lock()->Destroy();
			}
		}
	}
}