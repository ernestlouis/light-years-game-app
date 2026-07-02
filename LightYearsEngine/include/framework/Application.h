#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace ly
{
	class World;
	class Application
	{
	public:
		Application(u32 window_width, u32 window_height, const std::string& title, sf::Uint32 style );
		virtual void Run();
		virtual ~Application() = default;

		template<typename World_Type>
		weak<World_Type> Load_World();

	sf::Vector2u Get_Window_Size() const;

	private:
		void Tick_Internal(float delta_time);
		void Render_Internal();

		virtual void Render();
		virtual void Tick(float delta_time);

		sf::RenderWindow m_window;
		float m_target_frame_rate;
		sf::Clock m_tick_clock;
		
		shared<World> m_current_world;
		sf::Clock m_clean_cycle_clock;
		float m_clean_cycle_interval;
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