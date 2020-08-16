#include "AgPch.h"
#include "AgWindow.h"
#include "Engine/Events/AgEvents.h"

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

		glfwSetKeyCallback(m_WindowID, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_RELEASE:
				data.m_Function(KeyReleaseEvent(key));
				break;
			case GLFW_PRESS:
				data.m_Function(KeyPressEvent(key, 0));
				break;
			case GLFW_REPEAT:
				data.m_Function(KeyPressEvent(key, 1));
				break;
			}
		});

		glfwSetMouseButtonCallback(m_WindowID, [](GLFWwindow* window, int key, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_RELEASE:
				data.m_Function(MouseReleaseEvent(key));
				break;
			case GLFW_PRESS:
				data.m_Function(MousePressEvent(key));
				break;
			}
		});

		glfwSetCursorPosCallback(m_WindowID, [](GLFWwindow* window, double x, double y)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			data.m_Function(MouseMoveEvent(x, y));
		});

		glfwSetScrollCallback(m_WindowID, [](GLFWwindow* window, double x, double y)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		
			data.m_Function(MouseScrollEvent(x, y));
		});

		glfwSetWindowSizeCallback(m_WindowID, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.m_Width = width;
			data.m_Height = height;

			data.m_Function(WindowResizeEvent(width, height));

		});

		glfwSetWindowCloseCallback(m_WindowID, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.m_Function(WindowCloseEvent());

		});

		glfwSetWindowFocusCallback(m_WindowID, [](GLFWwindow* window, int focused)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		
			if (focused)
			{
				data.m_Function(WindowFocusEvent());
			}
			else
			{
				data.m_Function(WindowLostFocusEvent());
			}
		});

	}

	Window::~Window()
	{
		AG_LOG("class(Window): Terminated.");
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

	void Window::SetPos(unsigned int x, unsigned int y)
	{
		glfwSetWindowPos(m_WindowID, (int)x, (int)y);
	}

}