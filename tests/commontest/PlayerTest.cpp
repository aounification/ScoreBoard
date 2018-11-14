#include "Player.h"
#include "gtest/gtest.h"

TEST(PlayerTest, EmptyPlayerInitializations)
{
	common::Player player;
	//EXPECT_EQ(std::array<char, 2>(), player.getJerseyNumber());
	EXPECT_EQ(std::string(), player.getName());
	EXPECT_EQ(common::Player(), player);
}

TEST(PlayerTest, PlayerInitializations)
{
	const int jerseyNumber{ 35 };
	const std::string playerName("Paul Aoun");
	common::Player player(jerseyNumber, playerName);

	EXPECT_EQ(jerseyNumber, player.getJerseyNumber());
	EXPECT_EQ(playerName, player.getName());
	EXPECT_EQ(common::Player(player), player);
}

TEST(PlayerTest, PlayerComparaison)
{
	const int jerseyNumber1{ 0 }, jerseyNumber2{ 5 };
	const std::string playerName1("Paul Aoun"), playerName2("Joe Chaaya");
	common::Player player1(jerseyNumber1, playerName1), player2(jerseyNumber1, playerName2), player3(jerseyNumber2, playerName1), player4(jerseyNumber2, playerName2);
	common::Player player5(jerseyNumber1, playerName1);

	EXPECT_EQ(player1, player1);
	EXPECT_FALSE(player1 < player1);
	EXPECT_EQ(player2, player2);
	EXPECT_FALSE(player2 < player2);
	EXPECT_EQ(player3, player3);
	EXPECT_FALSE(player3 < player3);
	EXPECT_EQ(player4, player4);
	EXPECT_FALSE(player4 < player4);
	EXPECT_EQ(player5, player5);
	EXPECT_FALSE(player5 < player5);

	EXPECT_EQ(player1, player5);
	EXPECT_EQ(player5, player1);
	EXPECT_FALSE(player1 < player5);
	EXPECT_FALSE(player5 < player1);
	EXPECT_TRUE(player1 == player5);
	EXPECT_TRUE(player5 == player1);

	EXPECT_NE(player1, player2);
	EXPECT_NE(player2, player1);
	EXPECT_FALSE((player1 < player2) && (player2 < player1));
	EXPECT_TRUE((player1 < player2) || (player2 < player1));
	EXPECT_FALSE((player1 == player2) || (player2 == player1));


	EXPECT_NE(player1, player3);
	EXPECT_NE(player3, player1);
	EXPECT_FALSE((player1 < player3) && (player3 < player1));
	EXPECT_TRUE((player1 < player3) || (player3 < player1));
	EXPECT_FALSE((player1 == player3) || (player3 == player1));

	EXPECT_NE(player1, player4);
	EXPECT_NE(player4, player1);
	EXPECT_FALSE((player1 < player4) && (player4 < player1));
	EXPECT_TRUE((player1 < player4) || (player4 < player1));
	EXPECT_FALSE((player1 == player4) || (player4 == player1));

	EXPECT_NE(player2, player3);
	EXPECT_NE(player3, player2);
	EXPECT_FALSE((player2 < player3) && (player3 < player2));
	EXPECT_TRUE((player2 < player3) || (player3 < player2));
	EXPECT_FALSE((player2 == player3) || (player3 == player2));

	EXPECT_NE(player2, player4);
	EXPECT_NE(player4, player2);
	EXPECT_FALSE((player2 < player4) && (player4 < player2));
	EXPECT_TRUE((player2 < player4) || (player4 < player2));
	EXPECT_FALSE((player2 == player4) || (player4 == player2));

	EXPECT_NE(player3, player4);
	EXPECT_NE(player4, player3);
	EXPECT_FALSE((player3 < player4) && (player4 < player3));
	EXPECT_TRUE((player3 < player4) || (player4 < player3));
	EXPECT_FALSE((player3 == player4) || (player4 == player3));
}

TEST(PlayerTest, PlayerCopy)
{
	const int jerseyNumber1{ 0 }, jerseyNumber2{ 7 };
	const std::string playerName1("Paul Aoun"), playerName2("Joe Chaaya");
	common::Player player1(jerseyNumber1, playerName1), player2(jerseyNumber2, playerName2);
	common::Player player(player1);
	EXPECT_EQ(player1, player);
	EXPECT_NE(player2, player);
	EXPECT_TRUE(player1 == player);
	EXPECT_FALSE(player2 == player);
	EXPECT_FALSE(player1 < player || player < player1); 
	EXPECT_FALSE(player2 < player && player < player2);
	EXPECT_TRUE(player2 < player || player < player2);

	player = player2;
	EXPECT_NE(player1, player);
	EXPECT_EQ(player2, player);
	EXPECT_FALSE(player1 == player);
	EXPECT_TRUE(player2 == player);
	EXPECT_FALSE(player2 < player || player < player2);
	EXPECT_FALSE(player1 < player && player < player1);
	EXPECT_TRUE(player1 < player || player < player1);
}
