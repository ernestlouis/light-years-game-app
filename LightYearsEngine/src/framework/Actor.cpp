#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{
	Actor::Actor(World* owning_world)
		:m_owning_world{ owning_world },
		m_has_began_play{false}
	{

	}

	Actor::~Actor()
	{
		LOG("Actor destroyed");
	}

	void Actor::Begin_Play_Internal()
	{
		if (!m_has_began_play)
		{
			m_has_began_play = true;
			Begin_Play();
		}
	}

	void Actor::Begin_Play()
	{
		LOG("Actor begin play");
	}

	void Actor::Tick(float delta_time)
	{
		LOG("Actor Ticking");
	}

}