#include "weapon/Shooter.h"

namespace ly
{
	void Shooter::Shoot()
	{
		if (Can_Shoot() && !Is_On_Cooldown())
		{
			Shoot_Impl();
		}

	}
	bool Shooter::Can_Shoot() const
	{
		return true;
	}
	bool Shooter::Is_On_Cooldown() const
	{
		return false;
	}
	Actor* Shooter::Get_Owner() const
	{
		return m_owner;
	}
	Shooter::Shooter(Actor* owner)
		:m_owner{owner}
	{

	}
}