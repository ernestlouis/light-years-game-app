#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

#include <SFML/Graphics.hpp>


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
		
		for (auto iter = m_actors.begin(); iter != m_actors.end();)
		{
			if (iter->get()->Is_Pending_Destroy())
			{
				iter = m_actors.erase(iter);
			}
			else
			{
				iter->get()->Tick_Internal(delta_time);
				++iter;
			}
		
		}

		Tick(delta_time);
	}

	void World::Render(sf::RenderWindow& window)
	{
		for (auto& actor : m_actors)
		{
			actor->Render(window);
		}
	}

	World::~World()
	{

	}

	void World::Begin_Play()
	{

	}


	void World::Tick(float delta_time)
	{

	}




}