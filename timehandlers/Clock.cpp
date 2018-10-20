#include "Clock.h"
#include <cassert>

namespace timehandler
{
	Clock::Clock() noexcept : m_paused(true), m_accumulatedTime(std::chrono::milliseconds::zero()), m_timer()
	{}

	void Clock::start()
	{
		assert(m_paused);
		if (m_paused == true)
		{
			m_timer.reset();
			m_paused = false;
		}
	}

	void Clock::stop()
	{
		assert(!m_paused);
		if (m_paused == false)
		{
			m_accumulatedTime += m_timer.getDuration();
			m_paused = true;
		}
	}

	void Clock::reset()
	{
		m_paused = true;
		m_accumulatedTime = std::chrono::milliseconds::zero();
	}
}


