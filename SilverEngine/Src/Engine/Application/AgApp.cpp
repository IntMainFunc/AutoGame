#include "AgPch.h"
#include "AgApp.h"

namespace Ag {

	App::App(Window* window)
		:m_IsRunning(true), m_Window(window)
	{
		AG_LOG("class(App): Started.");
		window->SetEventCallback(std::bind(&App::OnEvent, this, std::placeholders::_1));
	}

	App::~App()
	{
		AG_LOG("class(App): Terminated.");
		glfwTerminate();
	}

	void App::Run()
	{
		AG_LOG("class(App): Running.");
		while (m_IsRunning)
		{
			m_Window->OnUpdate();
		}
	}

	bool App::CloseApp(WindowCloseEvent event)
	{
		delete m_Window;
		m_IsRunning = false;
		return true;
	}

	void App::OnEvent(Event& event)
	{
		AG_LOG(event.GetDebug());

		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&App::CloseApp, this, std::placeholders::_1));

	}
}