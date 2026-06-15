#pragma once
#include <string>

inline std::string Get_Resource_Dir()
{
	#ifdef NDEBUG //release build
		return "assets/";
	#else 
		return "C:/dev/light-years-game-app/LightYearsGame/assets/";
	#endif
}
