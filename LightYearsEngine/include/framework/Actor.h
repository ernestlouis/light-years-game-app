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

		void Set_Actor_Location(const sf::Vector2f& new_location);
		void Set_Actor_Rotation(float new_rotation);
		void Add_Actor_Location_Offset(const sf::Vector2f& offset_amount);
		void Add_Actor_Rotation_Offset(float offset_amount);
		sf::Vector2f Get_Actor_Location() const;
		float Get_Actor_Rotation() const;
		sf::Vector2f Get_Actor_Forward_Direction() const;
		sf::Vector2f Get_Actor_Right_Direction() const;

	private:
		void Center_Pivot();

		World* m_owning_world;
		bool m_has_began_play;

		sf::Sprite m_sprite;
		shared<sf::Texture> m_texture;

	};
}
