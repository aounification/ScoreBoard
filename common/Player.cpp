#include "Player.h"

namespace common
{
	Player::Player(int jerseyNumber, const std::string &name)
		: m_information(std::make_pair (jerseyNumber, name))
	{}

	bool Player::operator< (const Player &rhs) const
	{
		return m_information < rhs.m_information;
	}

	bool Player::operator==(const Player &rhs) const
	{
		return m_information == rhs.m_information;
	}

	bool Player::operator!=(const Player &rhs) const
	{
		return !(m_information == rhs.m_information);
	}

	std::string Player::getName() const
	{
		return m_information.second;
	}

	int Player::getJerseyNumber() const
	{
		return m_information.first;
	}
}
