#pragma once

namespace ly
{
	class Object
	{
		public:
			Object();
			virtual ~Object();

			void Destroy();
			bool Is_Pending_Destroy() const;
		private:
			bool m_is_pending_destroy;
	};
}