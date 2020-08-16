#pragma once

#include "AgPch.h"
#include "Engine/Events/AgEvents.h" 
#include "AgWindow.h"

namespace Ag {

	class App
	{
	private:
		bool m_IsRunning;
		Window* m_Window;

		bool CloseApp(WindowCloseEvent event);

	public:
		App(Window* window = new Window());
		~App();

		void Run();
		void OnEvent(Event& event);

	};

}