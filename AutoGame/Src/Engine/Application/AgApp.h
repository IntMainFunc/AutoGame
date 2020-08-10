#pragma once

#include "AgPch.h"
#include "AgWindow.h"

namespace Ag {

	class App
	{
	private:
		bool m_IsRunning;
		Window* m_Window;

	public:
		App(Window* window = new Window());
		~App();

		const Window* GetWindow() const { return m_Window; }


		virtual void Run();
		virtual void OnUpdate();

	};

}