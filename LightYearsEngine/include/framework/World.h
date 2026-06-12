#pragma once

namespace ly
{
	class Application;
	class World
	{
		public:
			World(Application* owning_app);

			void Begin_Play_Internal();
			void Tick_Internal(float delta_time);

			virtual ~World();

		private:
			void Begin_Play();
			void Tick(float delta_time);
			Application* m_owning_app;
			bool m_begin_play;

	};
}
