#pragma once

#ifdef E_PLATFORM_WINDOWS

#ifdef E_CORE_DLL
#define E_API __declspec(dllexport)	
#else
#define E_API __declspec(dllimport)
#endif

#endif  

#define BIT(x) (1 << x)
