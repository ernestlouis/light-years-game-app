#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace ly
{
	class World;
	class Application
	{
	public:
		Application();
		virtual void Run();
		virtual ~Application() = default;

		template<typename World_Type>
		weak<World_Type> Load_World();

	private:
		void Tick_Internal(float delta_time);
		void Render_Internal();

		virtual void Render();
		virtual void Tick(float delta_time);

		sf::RenderWindow m_window;
		float m_target_frame_rate;
		sf::Clock m_tick_clock;
		
		shared<World> m_current_world;
	};

	template<typename World_Type>
	weak<World_Type> Application::Load_World()
	{
		shared<World_Type> new_world{ new World_Type{this} };  //makeshared not used becuse limits it to std library
		m_current_world = new_world;
		m_current_world->Begin_Play_Internal();
		return new_world;
	}
	

}