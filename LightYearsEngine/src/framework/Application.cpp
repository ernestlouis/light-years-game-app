#include <iostream>
#include "framework/Application.h"

namespace ly
{
    Application::Application()
        :m_window{ sf::VideoMode(800, 600),"MyWindow" },
        m_target_frame_rate{ 60.f },
        m_tick_clock{}
	{
	}

	void Application::Run()
	{
        m_tick_clock.restart();
        float accumulated_time = 0.f;
        float target_delta_time = 1.f / m_target_frame_rate;

        while (m_window.isOpen())
        {
            sf::Event event;

            while (m_window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    m_window.close();
                }
            }

            

            accumulated_time += m_tick_clock.restart().asSeconds();
            while (accumulated_time > target_delta_time)
            {
                accumulated_time -= target_delta_time;
                Tick_Internal(target_delta_time);
                Render_Internal();
            }
        }
	}

    void Application::Tick_Internal(float delta_time)
    {
        Tick(delta_time);
    }

    void Application::Render_Internal()
    {
        m_window.clear(sf::Color::Black);

        Render();

        m_window.display();
    }

    void Application::Render()
    {
        sf::CircleShape circ{ 50 };
        circ.setFillColor(sf::Color::Green);
        circ.setOrigin(50, 50);
        circ.setPosition(m_window.getSize().x / 2.f, m_window.getSize().y / 2.f);

        m_window.draw(circ);
    }

    void Application::Tick(float delta_time)
    {
        std::cout << "Ticking at framerate: " << 1.f / delta_time << std::endl;
    }

   
}