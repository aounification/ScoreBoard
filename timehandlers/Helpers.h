#ifndef TIME_HANDLER_HELPERS_HPP
#define TIME_HANDLER_HELPERS_HPP

#include <chrono>

namespace timehandler
{
	namespace helper
	{
		template <typename T>
		struct is_duration
		{
			static constexpr bool m_value = false;
		};

		template <typename Rep, typename Period>
		struct is_duration< std::chrono::duration<Rep, Period> >
		{
			static constexpr bool m_value = true;
		};
	}
}

#endif
