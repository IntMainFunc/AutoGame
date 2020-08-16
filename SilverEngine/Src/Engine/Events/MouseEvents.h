#pragma once

#include "CoreEvents.h"

namespace Ag {

	class MouseButtonEvent : public Event
	{
	protected:
		unsigned int m_Button;

		MouseButtonEvent(unsigned int button)
			:m_Button(button) { }

	public:

		virtual ~MouseButtonEvent() { }

		static EventType GetStaticEventType() { return EventType::Base; }
		virtual EventType GetEventType() const override { return GetStaticEventType(); }

		unsigned int GetButton() const { return m_Button; }

		virtual std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "event(MouseButtonEvent): " << m_Button;
			return ss.str();
		}

	};

	class MousePressEvent : public MouseButtonEvent
	{
	public:
		MousePressEvent(unsigned int button)
			:MouseButtonEvent(button) { }

		~MousePressEvent() { }

		static EventType GetStaticEventType() { return EventType::MousePress; }
		EventType GetEventType() const override { return GetStaticEventType(); }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "event(MousePressEvent): " << m_Button;
			return ss.str();
		}

	};

	class MouseReleaseEvent : public MouseButtonEvent
	{
	public:
		MouseReleaseEvent(unsigned int button)
			:MouseButtonEvent(button) { }

		~MouseReleaseEvent() { }

		static EventType GetStaticEventType() { return EventType::MouseRelease; }
		EventType GetEventType() const override { return GetStaticEventType(); }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "event(MouseReleaseEvent): " << m_Button;
			return ss.str();
		}

	};

	class MouseMoveEvent : public Event
	{
	private:
		float m_PositionX, m_PositionY;

	public:
		MouseMoveEvent(float positionX, float positionY)
			:m_PositionX(positionX), m_PositionY(positionY) { }

		~MouseMoveEvent() { }

		static EventType GetStaticEventType() { return EventType::MouseMove; }
		EventType GetEventType() const override { return GetStaticEventType(); }

		float GetPositionX() const { return m_PositionX; }
		float GetPositionY() const { return m_PositionY; }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "event(MouseReleaseEvent): x:" << m_PositionX << " y:" << m_PositionY;
			return ss.str();
		}

	};

	class MouseScrollEvent : public Event
	{
	private:
		float m_OffsetX, m_OffsetY;

	public:
		MouseScrollEvent(float positionX, float positionY)
			:m_OffsetX(positionX), m_OffsetY(positionY) { }

		~MouseScrollEvent() { }

		static EventType GetStaticEventType() { return EventType::MouseScroll; }
		EventType GetEventType() const override { return GetStaticEventType(); }

		float GetPositionX() const { return m_OffsetX; }
		float GetPositionY() const { return m_OffsetY; }

		std::string GetDebug() const override
		{
			std::stringstream ss;
			ss << "event(MouseScrollEvent): x:" << m_OffsetX << " y:" << m_OffsetY;
			return ss.str();
		}

	};

}