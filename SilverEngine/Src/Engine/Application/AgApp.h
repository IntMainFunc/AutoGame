#pragma once

#include "AgPch.h"

namespace Ag {

	class AG_API App
	{
	private:

	public:
		App();
		virtual ~App();

		static void Terminate();
		static void Init();

	};
}