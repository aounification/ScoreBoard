#ifndef TIME_HANDLER_TIMER_HPP
#define TIME_HANDLER_TIMER_HPP

#include <chrono>
#include "Config.h"

namespace time_handler
{
	class TIME_HANDLERS_EXPORT Timer
	{
	public:
		Timer();
		~Timer() = default;
		Timer(const Timer &timer) = default;
		Timer(Timer &&) = delete;
		Timer &operator=(const Timer &timer) = default;
		Timer &operator=(Timer &&timer) = delete;

		std::chrono::milliseconds getDuration() const;
		void reset();

	private:
		std::chrono::system_clock::time_point m_startTime;
	};
}

#endif
