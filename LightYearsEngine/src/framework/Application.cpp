#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "framework/AssetManager.h"

namespace ly
{

    Application::Application(u32 window_width, u32 window_height, const std::string& title, sf::Uint32 style)
        :m_window{ sf::VideoMode(window_width, window_height),title,style},
        m_target_frame_rate{ 60.f },
        m_tick_clock{},
        m_current_world{ nullptr },
        m_clean_cycle_clock{},
        m_clean_cycle_interval{2.f}
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

        if (m_current_world)
        {
            m_current_world->Tick_Internal(delta_time);
        }

        if (m_clean_cycle_clock.getElapsedTime().asSeconds() >= m_clean_cycle_interval)
        {
            m_clean_cycle_clock.restart();
            AssetManager::Get().Clean_Cycle();
        }
    }

    void Application::Render_Internal()
    {
        m_window.clear(sf::Color::Black);

        Render();

        m_window.display();
    }

    void Application::Render()
    {
        if (m_current_world)
        {
            m_current_world->Render(m_window);
        }
    }

    void Application::Tick(float delta_time)
    {
        
    }

   
}