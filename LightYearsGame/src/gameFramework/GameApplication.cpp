#include "gameFramework/GameApplication.h"
#include "framework/Core.h"
#include "framework/World.h"


ly::unique<ly::Application> GetApplication()
{
	return ly::unique<ly::Application>(new ly::GameApplication());
}

namespace ly
{
	GameApplication::GameApplication()
	{
		Load_World<World>();
	}
}