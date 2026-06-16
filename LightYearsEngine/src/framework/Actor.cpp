#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"

namespace ly
{
	Actor::Actor(World* owning_world, const std::string& texture_path)
		:m_owning_world{ owning_world },
		m_has_began_play{false},
		m_sprite{},
		m_texture{}
	{
		Set_Texture(texture_path);
	}

	Actor::~Actor()
	{
		LOG("Actor destroyed");
	}

	void Actor::Begin_Play_Internal()
	{
		if (!m_has_began_play)
		{
			m_has_began_play = true;
			Begin_Play();
		}
	}

	void Actor::Tick_Internal(float delta_time)
	{
		if (!Is_Pending_Destroy())
		{

		}
	}

	void Actor::Begin_Play()
	{
		LOG("Actor begin play");
	}

	void Actor::Tick(float delta_time)
	{

	}

	void Actor::Set_Texture(const std::string& texture_path)
	{

		m_texture = AssetManager::Get().Load_Texture(texture_path);
		if (!m_texture)
			return;

		m_sprite.setTexture(*m_texture);


		int texture_width = m_texture->getSize().x;
		int texture_height = m_texture->getSize().y;
		m_sprite.setTextureRect(sf::IntRect{ sf::Vector2i{}, sf::Vector2i{ texture_width,texture_height } });


	}

	void Actor::Render(sf::RenderWindow& window)
	{
		if (Is_Pending_Destroy())
			return;

		window.draw(m_sprite);
	}

}