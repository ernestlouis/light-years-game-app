#pragma once
#include <SFML/Graphics.hpp>

namespace ly
{
	class Application
	{
	public:
		Application();
		virtual void Run();
		virtual ~Application() = default;

	private:
		void Tick_Internal(float delta_time);
		void Render_Internal();

		virtual void Render();
		virtual void Tick(float delta_time);

		sf::RenderWindow m_window;
		float m_target_frame_rate;
		sf::Clock m_tick_clock;
		
	};


	

}