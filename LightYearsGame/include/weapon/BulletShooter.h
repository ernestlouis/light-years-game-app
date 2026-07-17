#pragma once
#include <SFML/System.hpp>
#include "weapon/Shooter.h"


namespace ly
{
	class BulletShooter : public Shooter
	{
	public:
		BulletShooter(Actor* owner, float cooldown_time = 0.5f);
		virtual bool Is_On_Cooldown() const override;

	private:
		virtual void Shoot_Impl() override;
		sf::Clock m_cooldown_clock;
		float m_cooldown_time;

	};
}