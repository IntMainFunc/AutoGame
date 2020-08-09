#pragma once

#include "CoreEvents.h"

namespace Ag {

	class WindowResizeEvent : public Event
	{
	private:
		unsigned int m_Width, m_Height;

	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:m_Width(width), m_Height(height) { }

		~WindowResizeEvent() { }

		static EventType GetStaticEventType() { return EventType::WindowResize; }
		EventType GetEventType() const override { return GetStaticEventType(); }

		unsigned int GetWidth() const { return m_Width; }
		unsigned int GetHeight() const { return m_Height; }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: x:" << m_Width << " y:" << m_Height;
			return ss.str();
		}

	};

	class WindowCloseEvent : public Event
	{
	public:
		static EventType GetStaticEventType() { return EventType::WindowClose; }
		EventType GetEventType() const override { return GetStaticEventType(); }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "WindowCloseEvent: NULL";
			return ss.str();
		}

	};

	class WindowFocusEvent : public Event
	{
	public:
		static EventType GetStaticEventType() { return EventType::WindowFocus; }
		EventType GetEventType() const override { return GetStaticEventType(); }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "WindowFocusEvent: NULL";
			return ss.str();
		}

	};

	class WindowLostFocusEvent : public Event
	{
	public:
		static EventType GetStaticEventType() { return EventType::WindowLostFocus; }
		EventType GetEventType() const override { return GetStaticEventType(); }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "WindowLostFocusEvent: NULL";
			return ss.str();
		}

	};

}