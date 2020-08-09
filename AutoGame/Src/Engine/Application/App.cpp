#include "App.h"

namespace Ag {

	App::App()
		:m_IsRunning(true)
	{

	}

	App::~App()
	{

	}

	void App::Run()
	{
		while (m_IsRunning)
		{
			OnUpdate();
			break;
		}
	}

	void App::OnUpdate()
	{

	}

}