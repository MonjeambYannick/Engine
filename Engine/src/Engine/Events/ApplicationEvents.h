#pragma once

#include "Events/Event.h"

#include "Core.h"

namespace Engine 
{
	
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {};

		EventType GetType() const override { return EventType::WindowClose; }
	};

};