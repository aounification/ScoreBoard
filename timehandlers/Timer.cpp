#include "Timer.h"

namespace timehandler
{
	Timer::Timer() noexcept : m_startTime(std::chrono::system_clock::now())
	{
	}

	std::chrono::milliseconds Timer::getDuration() const
	{
		return std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::system_clock::now() - m_startTime);
	}

	void Timer::reset()
	{
		m_startTime = std::chrono::system_clock::now();
	}
}

