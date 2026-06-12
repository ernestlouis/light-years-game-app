#include "framework/World.h"
#include "framework/Core.h"

namespace ly
{
	World::World(Application* owning_app)
		: m_owning_app{owning_app},
		m_begin_play{false}
	{

	}

	void World::Begin_Play_Internal()
	{
		if (!m_begin_play)
		{
			m_begin_play = true;
			Begin_Play();
		}
	}

	void World::Tick_Internal(float delta_time)
	{
		Tick(delta_time);
	}

	World::~World()
	{

	}

	void World::Begin_Play()
	{
		LOG("begin play");
	}


	void World::Tick(float delta_time)
	{
		LOG("Ticking at framerate: %f", 1.f / delta_time);
	}




}