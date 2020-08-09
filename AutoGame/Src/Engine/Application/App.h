#pragma once

#include "AgPch.h"

namespace Ag {

	class App
	{
	private:
		bool m_IsRunning;

	public:
		App();
		~App();

		void Run();

		void OnUpdate();
	};

}