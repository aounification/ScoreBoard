#include "Timer.h"
#include "gtest/gtest.h"

namespace
{
	void waitInMilliseconds(int milliseconds)
	{
		time_handler::Timer timer;
		std::chrono::milliseconds ms(milliseconds);

		while (timer.getDuration() < ms)
		{
		}
	}
}

TEST(TimerTest, compareDurationsAfter10MsWait)
{
	time_handler::Timer timer;
	const time_handler::Timer referenceTimer;
	::waitInMilliseconds(10);

	EXPECT_LE(referenceTimer.getDuration(), timer.getDuration());
}

TEST(TimerTest, compareDurationsAfter10MsWaitThenReset)
{
	time_handler::Timer timer;
	const time_handler::Timer referenceTimer;
	::waitInMilliseconds(10);
	timer.reset();
	EXPECT_GT(referenceTimer.getDuration(), timer.getDuration());
}

TEST(TimerTest, compareDurationsOfCopiedTimers)
{
	time_handler::Timer timer;
	const time_handler::Timer referenceTimer;
	::waitInMilliseconds(10);
	timer.reset();

	time_handler::Timer newTimer(referenceTimer);
	EXPECT_EQ(referenceTimer.getDuration(), newTimer.getDuration());
	EXPECT_LT(timer.getDuration(), newTimer.getDuration());

	newTimer = timer;
	EXPECT_GT(referenceTimer.getDuration(), newTimer.getDuration());
	EXPECT_EQ(timer.getDuration(), newTimer.getDuration());
}
