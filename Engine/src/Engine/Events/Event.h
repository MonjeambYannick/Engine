#pragma once

#include "../Core.h"
#include <string>
#include <vector>
#include <functional>

namespace Engine
{

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	class Event
	{
	public:
		virtual EventType GetType() const = 0;
		bool m_Handled = false;
	};

	class EventQueue
	{
	public:
		std::vector<Event*> queue;
	};

	class EventDispatcher
	{

	};

}