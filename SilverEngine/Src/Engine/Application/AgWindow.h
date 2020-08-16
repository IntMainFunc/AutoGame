#pragma once

#include "AgPch.h"
#include "Engine/Events/CoreEvents.h"

namespace Ag {

	class Window
	{
	private:
		using EventCallbackFunc = std::function<void(Event&)>;

		struct WindowData
		{
			std::string m_Title;
			unsigned int m_Width, m_Height;
			bool m_IsVSynced;

			EventCallbackFunc m_Function;
		};

		GLFWwindow* m_WindowID;
		WindowData m_Data;

		void Init(const std::string& title, unsigned int width, unsigned int height);

	public:

		Window(const std::string& title = "SilverEngine", unsigned int width = 1280, unsigned int height = 720);

		~Window();

		void OnUpdate();

		unsigned int GetWidth() const { return m_Data.m_Width; }
		unsigned int GetHeight() const { return m_Data.m_Height; }

		bool GetVSync() const { return m_Data.m_IsVSynced; }
		void SetVSync(bool enabled);

		void SetPos(unsigned int x, unsigned int y);

		void SetEventCallback(const EventCallbackFunc& callbackFunc) { m_Data.m_Function = callbackFunc; }
	};

}