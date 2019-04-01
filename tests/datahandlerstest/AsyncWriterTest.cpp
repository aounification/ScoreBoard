#include "AsyncWriter.h"
#include "TestHelpers.h"
#include "gtest/gtest.h"
#include <numeric>
#include <chrono>

TEST(AsyncWriterTest, singleStreamWriter)
{
	std::ostringstream s;
	std::vector < std::pair <std::string, int> > v
	{
		{ "Elie", 12 },
		{ "Mohammad", 13 },
		{ "Thomas", 19 },
		{ "Roland", 4 },
		{ "Abbas", 17 },
		{ "Jennifer", 14 },
		{ "Rouba", 11 },
		{ "Alexandre", 28 },
		{ "Guillaume", 8 }
	};

	std::string expectedResult = std::accumulate(v.begin(), v.end(), std::string(), datahandler::test::helper::addToString);

   auto startTime = std::chrono::system_clock::now();
	datahandler::asyncWriter::run(std::move(v), s);
   auto elapsedTime = std::chrono::system_clock::now() - startTime;
   std::cout << "ElapsedTime singleStreamWriter = " << elapsedTime.count() <<std::endl;
	EXPECT_EQ(expectedResult, s.str());
	EXPECT_TRUE(v.empty());
}

TEST(AsyncWriterTest, doubleStreamWriter)
{
	std::ostringstream s;
	std::vector < std::pair <std::string, int> > v1
	{
		{ "Elie", 12 },
	{ "Mohammad", 13 },
	{ "Thomas", 19 },
	{ "Roland", 4 },
	{ "Abbas", 17 },
	{ "Jennifer", 14 },
	{ "Rouba", 11 },
	{ "Alexandre", 28 },
	{ "Guillaume", 8 }
	};

	std::vector < std::pair <std::string, int> > v2
	{
		{ "Elie", 11 },
	{ "Mohammad", 23 },
	{ "Thomas", 43 },
	{ "Roland", 31 },
	{ "Abbas", 18 },
	{ "Jennifer", 20 },
	{ "Rouba", 33 },
	{ "Alexandre", 8 },
	{ "Guillaume", 16 }
	};

	std::string expectedResult = std::accumulate(v1.begin(), v1.end(), std::string(), datahandler::test::helper::addToString);
	expectedResult = std::accumulate(v2.begin(), v2.end(), expectedResult, datahandler::test::helper::addToString);

   auto startTime = std::chrono::system_clock::now();
   datahandler::asyncWriter::run(std::move(v1), s);
   datahandler::asyncWriter::run(std::move(v2), s);
   auto elapsedTime = std::chrono::system_clock::now() - startTime;
   std::cout << "ElapsedTime doubleStreamWriter = " << elapsedTime.count() << std::endl;


	EXPECT_EQ(expectedResult, s.str());
	EXPECT_TRUE(v1.empty());
	EXPECT_TRUE(v2.empty());
}
