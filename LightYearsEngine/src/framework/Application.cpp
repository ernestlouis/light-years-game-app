#include "framework/Application.h"

namespace ly
{
	Application::Application()
		:m_window{ sf::VideoMode(800, 600),"MyWindow" }
	{
	}

	void Application::Run()
	{
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

            m_window.clear(sf::Color::Black);
            m_window.display();
        }
	}

}