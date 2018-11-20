#ifndef COMMON_TEAM_HPP
#define COMMON_TEAM_HPP

#include "Player.h"
#include <string>
#include <vector>

namespace common
{
	class Team
	{
	public:
		using Players = std::vector <Player>;

		Team() = delete;
		Team(const std::string &name);
		Team(const Team &) = default;
		Team(Team &&) = default;
		Team &operator=(const Team &) = default;
		Team &operator=(Team &&) = delete;
		~Team() = default;

		bool operator< (const Team &rhs) const;
		bool operator==(const Team &rhs) const;
		bool operator!=(const Team &rhs) const;

		const std::string &getName() const;
		void addPlayer(const Player &player);

		const Players &getPlayers() const;
		Players &getPlayers();

	private:
		const std::string m_name;
		Players m_players;
	};
}

#endif