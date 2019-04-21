#pragma once

#include <Windows.h>

#include "../Core.h"

namespace Engine
{

	class E_API Timer
	{
	private:
		LARGE_INTEGER m_Start;
		double m_Frequency;
	public:
		Timer()
		{
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			m_Frequency = 1.0f / frequency.QuadPart;
			QueryPerformanceCounter(&m_Start);
		};

		void reset()
		{
			QueryPerformanceCounter(&m_Start);
		};

		float elapsed()
		{
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned __int64 cycles = current.QuadPart - m_Start.QuadPart;
			return (float)(cycles * m_Frequency);
		};
	};

};