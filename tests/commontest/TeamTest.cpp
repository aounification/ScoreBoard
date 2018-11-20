#include "Team.h"
#include <algorithm>
#include "gtest/gtest.h"

namespace
{
	const std::string teamName("Inmaa Damour");
	const std::vector <std::pair <int, std::string> > players
	{
		std::make_pair(1, std::string("Abi Abdallah Simon")),
		std::make_pair(2, std::string("Andraous Rodrigue")),
		std::make_pair(3, std::string("Aoun Paul")),
		std::make_pair(4, std::string("Aoun Roland")),
		std::make_pair(5, std::string("Azzi Maroun")),
		std::make_pair(6, std::string("Boustani Roudy")),
		std::make_pair(7, std::string("Chaaya Johnny")),
		std::make_pair(8, std::string("Chahine Charbel")),
		std::make_pair(9, std::string("Chaker Elie")),
		std::make_pair(10, std::string("Dagher Elie")),
		std::make_pair(11, std::string("Eid Elio")),
		std::make_pair(12, std::string("Ghorayeb Michel")),
		std::make_pair(13, std::string("Mansour Peter")),
		std::make_pair(14, std::string("Sarkis Louis")),
		std::make_pair(15, std::string("Youssef Michel"))
	};
	common::Team createTeam(const std::string &name)
	{
		common::Team team(name);
		std::for_each(players.begin(), players.end(), [&](const auto &player)
		{ team.addPlayer(common::Player(player.first, player.second)); });
		return std::move(team);
	}
}

TEST(TeamTest, TeamCreation)
{
	common::Team team = createTeam(teamName);
	
	EXPECT_EQ(teamName, team.getName());
	EXPECT_TRUE(teamName == team.getName());
	
	const common::Team::Players &teamPlayers = team.getPlayers();
	EXPECT_EQ(players.size(), teamPlayers.size());
	EXPECT_TRUE(std::equal(players.begin(), players.end(), teamPlayers.begin(), teamPlayers.end(),
		[](const auto &player, const auto &teamPlayer) -> bool { return common::Player(player.first, player.second) == teamPlayer; }));
}

TEST(TeamTest, TeamComparaison)
{
	common::Team team1 = createTeam(teamName);
	common::Team team2 = createTeam("MyTeam");
	

	EXPECT_EQ(team1, team1);
	EXPECT_FALSE(team1 < team1);
	EXPECT_EQ(team2, team2);
	EXPECT_FALSE(team2 < team2);

	EXPECT_NE(team1, team2);
	EXPECT_TRUE((team1 < team2) || (team2 < team1));
	EXPECT_FALSE(team1 == team2);
	EXPECT_FALSE(team2 == team1);
}

TEST(TeamTest, TeamCopy)
{
	common::Team team1 = createTeam(teamName);
	common::Team team2(team1);
	common::Team team3 = team2;

	EXPECT_EQ(team1, team2);
	EXPECT_EQ(team2, team1);
	EXPECT_FALSE(team1 < team2);
	EXPECT_FALSE(team2 < team1);
	EXPECT_TRUE(team1 == team2);
	EXPECT_TRUE(team2 == team1);
}
