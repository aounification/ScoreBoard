#ifndef TIME_HANDLER_TIMER_HPP
#define TIME_HANDLER_TIMER_HPP

#include <chrono>

namespace time_handler
{
	class Timer
	{
	public:
		Timer() noexcept;
		~Timer() noexcept = default;
		Timer(const Timer &timer) noexcept = default;
		Timer(Timer &&) = delete;
		Timer &operator=(const Timer &timer) noexcept = default;
		Timer &operator=(Timer &&timer) = delete;

		std::chrono::milliseconds getDuration() const;
		void reset();

	private:
		std::chrono::system_clock::time_point m_startTime;
	};
}

#endif
