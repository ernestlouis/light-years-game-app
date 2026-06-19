#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"
#include "framework/MathUtility.h"

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
			Tick(delta_time);
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
		Center_Pivot();
	}

	void Actor::Render(sf::RenderWindow& window)
	{
		if (Is_Pending_Destroy())
			return;

		window.draw(m_sprite);
	}

	void Actor::Set_Actor_Location(const sf::Vector2f& new_location)
	{
		m_sprite.setPosition(new_location);
	}

	void Actor::Set_Actor_Rotation(float new_rotation)
	{
		m_sprite.setRotation(new_rotation);
	}

	void Actor::Add_Actor_Location_Offset(const sf::Vector2f& offset_amount)
	{
		Set_Actor_Location(Get_Actor_Location() + offset_amount);
	}

	void Actor::Add_Actor_Rotation_Offset(float offset_amount)
	{
		Set_Actor_Rotation(Get_Actor_Rotation() + offset_amount);
	}

	sf::Vector2f Actor::Get_Actor_Location() const
	{
		return m_sprite.getPosition();
	}

	float Actor::Get_Actor_Rotation() const
	{
		return m_sprite.getRotation();
	}

	sf::Vector2f Actor::Get_Actor_Forward_Direction() const
	{
		return Rotation_To_Vector(Get_Actor_Rotation());
	}

	sf::Vector2f Actor::Get_Actor_Right_Direction() const
	{
		return Rotation_To_Vector(Get_Actor_Rotation() + 90.f);
	}

	void Actor::Center_Pivot()
	{
		sf::FloatRect bound = m_sprite.getLocalBounds();
		m_sprite.setOrigin(
			bound.width / 2.f, 
			bound.height / 2.f
		);

	}

}