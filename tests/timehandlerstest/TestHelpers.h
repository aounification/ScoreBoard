#ifndef TIME_HANDLER_TESTS_TEST_HELPERS_H
#define TIME_HANDLER_TESTS_TEST_HELPERS_H

#include "Timer.h"
#include "Helpers.h"

namespace timehandler
{
	namespace test
	{
		namespace helper
		{
			template <class Duration>
			void wait(Duration duration)
			{
				static_assert(timehandler::helper::is_duration<Duration>::m_value, "Duration is not supported. Please use an std::chrono::duration type instead.");
				timehandler::Timer timer;

				while (timer.getDuration() < duration)
				{
				}
			}
		}
	}
}

#endif
