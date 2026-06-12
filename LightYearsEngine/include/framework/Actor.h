#pragma once
#include "framework/Object.h"

namespace ly
{
	class World;
	class Actor : public Object
	{
	public:
		Actor(World* owning_world);

		virtual ~Actor();

		void Begin_Play_Internal();
		virtual void Begin_Play();
		virtual void Tick(float delta_time);

	private:
		World* m_owning_world;
		bool m_has_began_play;
	};
}