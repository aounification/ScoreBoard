#ifndef TIME_HANDLER_CLOCK_HPP
#define TIME_HANDLER_CLOCK_HPP

#include "Timer.h"
#include "Helpers.h"

namespace timehandler
{
	class Clock
	{
	public:
		Clock() noexcept;
		~Clock() noexcept = default;
		Clock(const Clock &timer) noexcept = default;
		Clock(Clock &&) = delete;
		Clock &operator=(const Clock &timer) noexcept = default;
		Clock &operator=(Clock &&timer) = delete;

		template <class Duration>
		Duration getElapsedTime() const;

		template <class Duration>
		Duration getRemainingTime(Duration initialTime) const;

		void start();
		void stop();
		void reset();

	private:
		bool m_paused;
		std::chrono::milliseconds m_accumulatedTime;
		Timer m_timer;
	};

	template <class Duration>
	Duration Clock::getElapsedTime() const
	{
		static_assert(timehandler::helper::is_duration<Duration>::m_value, "Duration is not supported. Please use an std::chrono::duration type instead.");
		Duration duration = std::chrono::duration_cast<Duration> (m_accumulatedTime);
		if (!m_paused)
		{
			duration += std::chrono::duration_cast<Duration> (m_timer.getDuration());
		}
		return duration;
	}

	template <class Duration>
	Duration Clock::getRemainingTime(Duration initialTime) const
	{
		static_assert(timehandler::helper::is_duration<Duration>::m_value, "Duration is not supported. Please use an std::chrono::duration type instead.");
		return initialTime - getElapsedTime<Duration>();
	}
}

#endif
