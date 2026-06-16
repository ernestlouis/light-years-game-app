#pragma once
#include <SFML/Graphics.hpp>

#include "framework/Core.h"
#include "framework/Object.h"

namespace ly
{
	class World;
	class Actor : public Object
	{
	public:
		Actor(World* owning_world, const std::string& texture_path = " ");

		virtual ~Actor();

		void Begin_Play_Internal();
		void Tick_Internal(float delta_time);
		virtual void Begin_Play();
		virtual void Tick(float delta_time);
		void Set_Texture(const std::string& texture_path);
		void Render(sf::RenderWindow& window);

	private:
		World* m_owning_world;
		bool m_has_began_play;

		sf::Sprite m_sprite;
		shared<sf::Texture> m_texture;

	};
}
