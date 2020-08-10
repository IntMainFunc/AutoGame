#include "AgPch.h"
#include "AgApp.h"

#include "AgWindow.h"

namespace Ag {

	App::App(Window* window)
		:m_IsRunning(true), m_Window(window)
	{
		AG_LOG("class(App): Started.");
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

	void App::OnUpdate()
	{

	}
}