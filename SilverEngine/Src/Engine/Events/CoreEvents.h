#pragma once

#include "AgPch.h"

namespace Ag{

	enum class EventType
	{
		None = -1, Base = 0,
		KeyPress, KeyRelease,
		MousePress, MouseRelease, MouseMove, MouseScroll,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus
	};


	class AG_API Event
	{
	private:
		friend class EventDispatcher;

	protected:
		bool m_IsHandled;

		Event()
			:m_IsHandled(false) { }

	public:
		virtual ~Event() { }

		virtual EventType GetEventType() const = 0;
		virtual std::string GetDebug() const = 0;

	};

	class AG_API EventDispatcher
	{
	private:
		Event& m_Event;

		template<typename T>
		using EventFunc = std::function<bool(T&)>;
	
	public:
		EventDispatcher(Event& event)
			:m_Event(event) { }

		template<typename T>
		bool Dispatch(EventFunc<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticEventType())
			{
				m_Event.m_IsHandled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	};

}