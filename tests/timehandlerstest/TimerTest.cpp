#include "Timer.h"
#include "TestHelpers.h"
#include "gtest/gtest.h"

TEST(TimerTest, compareDurationsAfter10MsWait)
{
	timehandler::Timer timer;
	const timehandler::Timer referenceTimer;
	timehandler::test::helper::wait(std::chrono::milliseconds(10));

	EXPECT_EQ(referenceTimer.getDuration(), timer.getDuration());
}

TEST(TimerTest, compareDurationsAfter10MsWaitThenReset)
{
	timehandler::Timer timer;
	const timehandler::Timer referenceTimer;
	timehandler::test::helper::wait(std::chrono::milliseconds(10));
	timer.reset();
	EXPECT_GT(referenceTimer.getDuration(), timer.getDuration());
}

TEST(TimerTest, compareDurationsOfCopiedTimers)
{
	timehandler::Timer timer;
	const timehandler::Timer referenceTimer;
	timehandler::test::helper::wait(std::chrono::milliseconds(10));
	timer.reset();

	timehandler::Timer newTimer(referenceTimer);
	EXPECT_EQ(referenceTimer.getDuration(), newTimer.getDuration());
	EXPECT_LT(timer.getDuration(), newTimer.getDuration());

	newTimer = timer;
	EXPECT_GT(referenceTimer.getDuration(), newTimer.getDuration());
	EXPECT_EQ(timer.getDuration(), newTimer.getDuration());
}
