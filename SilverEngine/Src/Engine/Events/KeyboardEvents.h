#pragma once

#include "CoreEvents.h"

namespace Ag {

	class AG_API KeyEvent : public Event
	{
	protected:
		unsigned int m_KeyCode;
		
		KeyEvent(unsigned int keyCode)
			:m_KeyCode(keyCode) { }

	public:
		virtual ~KeyEvent() { }

		static EventType GetStaticEventType() { return EventType::Base;  }
		virtual EventType GetEventType() const override { return GetStaticEventType(); }

		unsigned int GetKeyCode() const { return m_KeyCode; }

		virtual std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "event(KeyEvent): " << m_KeyCode;
			return ss.str();
		}

	};

	class AG_API KeyPressEvent : public KeyEvent
	{
	private:
		unsigned int m_RepeatCount;

	public:
		KeyPressEvent(unsigned int keyCode, unsigned int repeatCount)
			:KeyEvent(keyCode), m_RepeatCount(repeatCount) { }

		~KeyPressEvent() { }

		static EventType GetStaticEventType() { return EventType::KeyPress; }
		EventType GetEventType() const override { return GetStaticEventType(); }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			if (!m_RepeatCount)
				ss << "event(KeyPressEvent(Press)): " << m_KeyCode;
			else
				ss << "event(KeyPressEvent(Repeat)): " << m_KeyCode;
			return ss.str();
		}

	};

	class AG_API KeyReleaseEvent : public KeyEvent
	{
	public:
		KeyReleaseEvent(unsigned int keyCode)
			:KeyEvent(keyCode) { }

		~KeyReleaseEvent() { }

		static EventType GetStaticEventType() { return EventType::KeyRelease; }
		EventType GetEventType() const override { return GetStaticEventType(); }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "event(KeyReleaseEvent): " << m_KeyCode;
			return ss.str();
		}

	};

}