#include "AgPch.h"
#include "AgApp.h"

namespace Ag {

	App::App()
	{

	}

	App::~App()
	{
		glfwTerminate();
	}

	void App::Terminate()
	{
		glfwTerminate();
	}

	void App::Init()
	{

	}

}