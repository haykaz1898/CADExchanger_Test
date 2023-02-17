#pragma once
#ifdef _WIN32
#define SHAPES_DLL_API __declspec(dllexport)
#else
#define SHAPES_DLL_API
#endif
