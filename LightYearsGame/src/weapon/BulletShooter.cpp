#include "framework/Core.h"
#include "weapon/BulletShooter.h"

namespace ly
{
	BulletShooter::BulletShooter(Actor* owner, float cooldown_time)
		: Shooter{ owner }, 
		m_cooldown_clock{},
		m_cooldown_time{cooldown_time}
	{

	}

	bool BulletShooter::Is_On_Cooldown() const
	{
		if (m_cooldown_clock.getElapsedTime().asSeconds() > m_cooldown_time)
		{
			return false;
		}
		return true;
	}

	void BulletShooter::Shoot_Impl()
	{
		m_cooldown_clock.restart();
		LOG("Shooting!");
	}



}
