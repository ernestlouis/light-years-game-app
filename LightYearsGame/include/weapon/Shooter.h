#pragma once

namespace ly
{
	class Actor;
	class Shooter
	{
	public:
		void Shoot();

		virtual bool Can_Shoot() const;

		virtual bool Is_On_Cooldown() const;

		Actor* Get_Owner() const;

	protected:
		Shooter(Actor* owner);

	private:

		virtual void Shoot_Impl() = 0;
		Actor* m_owner;
	};
}