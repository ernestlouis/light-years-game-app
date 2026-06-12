#pragma once
#include<framework/Application.h>
#include<framework/Core.h>

namespace ly
{
	class Actor;
	class GameApplication : public Application
	{
	public:
		GameApplication();
		virtual void Tick(float delta_time) override;

	private:
		float counter{};
		weak<Actor> actor_to_destroy;
	};
}