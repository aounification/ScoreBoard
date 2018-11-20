#include "Team.h"

namespace common
{
	Team::Team(const std::string &name)
		: m_name(name), m_players()
	{}

	bool Team::operator< (const Team &rhs) const
	{
		return m_name < rhs.m_name;
	}

	bool Team::operator==(const Team &rhs) const
	{
		return m_name == rhs.m_name;
	}

	bool Team::operator!=(const Team &rhs) const
	{
		return m_name != rhs.m_name;
	}

	const std::string &Team::getName() const
	{
		return m_name;
	}

	void Team::addPlayer(const Player &player)
	{
		m_players.push_back(player);
	}

	const Team::Players &Team::getPlayers() const
	{
		return m_players;
	}

	Team::Players &Team::getPlayers()
	{
		return m_players;
	}
}
