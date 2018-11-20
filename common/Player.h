#ifndef COMMON_PLAYER_HPP
#define COMMON_PLAYER_HPP

#include <string>

namespace common
{
	class Player
	{
	public:
		Player() = default;
		Player(int jerseyNumber, const std::string &name);
		Player(const Player &) = default;
		Player(Player &&) = default;
		Player &operator=(const Player &) = default;
		Player &operator=(Player &&) = delete;
		~Player() = default;

		bool operator< (const Player &rhs) const;
		bool operator==(const Player &rhs) const;
		bool operator!=(const Player &rhs) const;

		std::string getName() const;
		int getJerseyNumber() const;

	private:
		std::pair <int, std::string> m_information;

	};
}

#endif