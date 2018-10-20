#include "Clock.h"
#include "TestHelpers.h"
#include "gtest/gtest.h"

TEST(ClockTest, clockResultsAfter2sWait)
{
	timehandler::Clock clock;
	clock.start();
	timehandler::test::helper::wait(std::chrono::seconds(2));
	clock.stop();
	EXPECT_EQ(std::chrono::seconds(2), clock.getElapsedTime<std::chrono::seconds>());
	EXPECT_EQ(std::chrono::seconds(2), clock.getRemainingTime(std::chrono::seconds(4)));
}

TEST(ClockTest, clockResultsDoNotChangeWhenStoppedAfter1sWait)
{
	timehandler::Clock clock;
	clock.start();
	timehandler::test::helper::wait(std::chrono::seconds(2));
	clock.stop();
	timehandler::test::helper::wait(std::chrono::seconds(1));
	EXPECT_EQ(std::chrono::seconds(2), clock.getElapsedTime<std::chrono::seconds>());
	EXPECT_EQ(std::chrono::seconds(2), clock.getRemainingTime(std::chrono::seconds(4)));
}

TEST(ClockTest, clockResultsStackWhenRanAndNotWhenStopped)
{
	timehandler::Clock clock;
	clock.start();
	timehandler::test::helper::wait(std::chrono::seconds(2));
	clock.stop();
	timehandler::test::helper::wait(std::chrono::seconds(1));
	clock.start();
	timehandler::test::helper::wait(std::chrono::seconds(1));
	clock.stop();
	EXPECT_EQ(std::chrono::seconds(3), clock.getElapsedTime<std::chrono::seconds>());
	EXPECT_EQ(std::chrono::seconds(1), clock.getRemainingTime(std::chrono::seconds(4)));
}

TEST(ClockTest, clockCopyWorksWell)
{
	timehandler::Clock clock;
	clock.start();
	timehandler::test::helper::wait(std::chrono::seconds(2));
	clock.stop();
	timehandler::Clock clock2(clock);
	EXPECT_EQ(clock.getElapsedTime<std::chrono::seconds>(), clock2.getElapsedTime<std::chrono::seconds>());
	EXPECT_EQ(clock.getRemainingTime(std::chrono::seconds(4)), clock2.getRemainingTime(std::chrono::seconds(4)));
	clock.start();
	timehandler::test::helper::wait(std::chrono::seconds(1));
	timehandler::Clock clock3(clock);
	clock.stop();
	clock3.stop();
	clock2 = clock;
	EXPECT_EQ(clock.getElapsedTime<std::chrono::seconds>(), clock2.getElapsedTime<std::chrono::seconds>());
	EXPECT_EQ(clock.getRemainingTime(std::chrono::seconds(4)), clock2.getRemainingTime(std::chrono::seconds(4)));
	EXPECT_EQ(clock.getElapsedTime<std::chrono::seconds>(), clock3.getElapsedTime<std::chrono::seconds>());
	EXPECT_EQ(clock.getRemainingTime(std::chrono::seconds(4)), clock3.getRemainingTime(std::chrono::seconds(4)));
}

