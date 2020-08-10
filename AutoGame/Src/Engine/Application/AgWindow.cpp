#include "AgPch.h"
#include "AgWindow.h"

namespace Ag {

	static bool s_IsGlfwInit = false;

	Window::Window(const std::string& title, unsigned int width, unsigned int height)
	{
		AG_LOG("class(Window): ", title, " x:", width, " y:", height);

		Init(title, width, height);

	}

	void Window::Init(const std::string& title, unsigned int width, unsigned int height)
	{
		m_Data.m_Title = title;
		m_Data.m_Width = width;
		m_Data.m_Height = height;
		m_Data.m_IsVSynced = true;

		if (!s_IsGlfwInit)
		{
			int isGlfwInitSucc = glfwInit();
			AG_ASSERT(!isGlfwInitSucc, "error(class(Window)): GLFW initialization failed.");
			AG_ASSERT(isGlfwInitSucc, "class(Window): GLFW initialization successful.");

			s_IsGlfwInit = true;
		}

		m_WindowID = glfwCreateWindow((int)width, (int)height, title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(m_WindowID);
		glfwSetWindowUserPointer(m_WindowID, &m_Data);
		SetVSync(m_Data.m_IsVSynced);

	}

	Window::~Window()
	{
		glfwDestroyWindow(m_WindowID);

	}

	void Window::OnUpdate()
	{
		glfwSwapBuffers(m_WindowID);
		glfwPollEvents();

	}

	void Window::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_Data.m_IsVSynced = enabled;

	}

}