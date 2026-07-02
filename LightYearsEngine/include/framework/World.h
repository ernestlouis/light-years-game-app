#pragma once
#include <SFML/Graphics.hpp>

#include "framework/Core.h"

namespace ly
{
	class Actor;
	class Application;
	class World
	{
		public:
			World(Application* owning_app);

			void Begin_Play_Internal();
			void Tick_Internal(float delta_time);
			void Render(sf::RenderWindow& window);

			virtual ~World();

			template<typename Actor_Type>
			weak<Actor_Type> Spawn_Actor();

			sf::Vector2u Get_Window_Size() const;

		private:
			void Begin_Play();
			void Tick(float delta_time);
			Application* m_owning_app;
			bool m_begin_play;

			List<shared<Actor>> m_actors;
			List<shared<Actor>> m_pending_actors;



	};

	template<typename Actor_Type>
	weak<Actor_Type> World::Spawn_Actor()
	{
		shared<Actor_Type> new_actor{ new Actor_Type{this} };
		m_pending_actors.push_back(new_actor);
		return new_actor;
	}
}
