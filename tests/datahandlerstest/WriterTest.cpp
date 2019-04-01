#include "Writer.h"
#include "TestHelpers.h"
#include "gtest/gtest.h"
#include <numeric>

TEST(WriterTest, streamWriter)
{
	std::ostringstream s;
	std::vector < std::pair <std::string, int> > v
	{
		{"Elie", 12},
		{"Mohammad", 13},
		{"Thomas", 19},
		{"Roland", 4},
		{"Abbas", 17},
		{"Jennifer", 14},
		{"Rouba", 11},
		{"Alexandre", 28},
		{"Guillaume", 8}
	};

    datahandler::writer::run(v.begin(), v.end(), s);
	std::string expectedResult = std::accumulate(v.begin(), v.end(), std::string(), datahandler::test::helper::addToString);
	EXPECT_EQ(expectedResult, s.str());
}


