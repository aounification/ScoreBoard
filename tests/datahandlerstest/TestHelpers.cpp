#include "TestHelpers.h"
#include "Helper.h"
#include <sstream>

namespace datahandler
{
	namespace helper
	{
		template <>
		std::string to_string< std::pair <std::string, int> >(const std::pair <std::string, int> &value)
		{
			constexpr char semiColumn = ';';
			std::ostringstream s;
			s << value.first << semiColumn << value.second;
			return s.str();
		}
	}

	namespace test
	{
		namespace helper
		{
			std::string addToString(const std::string &v, const std::pair <std::string, int> &item)
			{
				std::ostringstream result;
				result << v << ::datahandler::helper::to_string(item) << std::endl;
				return result.str();
			}
		}
	}
}


