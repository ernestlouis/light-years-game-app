#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace ly
{
	World::World(Application* owning_app)
		: m_owning_app{owning_app},
		m_begin_play{false},
		m_actors{},
		m_pending_actors{}
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
		for (shared<Actor> actor : m_pending_actors)
		{
			m_actors.push_back(actor);
			actor->Begin_Play_Internal();
		}

		m_pending_actors.clear();
		
		for (shared<Actor> actor : m_actors)
		{
			actor->Tick(delta_time);
		}

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