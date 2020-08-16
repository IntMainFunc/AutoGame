#pragma once
#include <iostream>

namespace Ag {

	class Logger
	{
	public:

		template<typename T>
		static void Log(T massage)
		{
			std::cout << massage << std::endl;
		}

		template<typename T, typename ... Ts>
		static void Log(T massage, Ts ... massages)
		{
			std::cout << massage;
			Log(massages ...);
		}

	};

}

#ifdef AG_BUILD_DEBUG
	#define AG_LOG(...)\
	std::cout << "[Log]: ";\
	Ag::Logger::Log(__VA_ARGS__)

	#define AG_ASSERT(x, ...)\
	if (x)\
	{std::cout << "[Log]: ";\
	Ag::Logger::Log(__VA_ARGS__);}

#else
	#define AG_LOG(...)
	#define AG_ASSERT(x, ...)

#endif // AG_BUILD_DEBUG