#include "framework/Object.h"
#include "framework/Core.h"

namespace ly
{
	Object::Object()
		: m_is_pending_destroy{false}
	{

	}

	Object::~Object()
	{
		LOG("Object Destroyed");
	}

	void Object::Destroy()
	{
		m_is_pending_destroy = true;
	}

	bool Object::Is_Pending_Destroy() const
	{
		return m_is_pending_destroy;
	}

	


}

