#ifndef DATA_HANDLER_WRITER_HPP
#define DATA_HANDLER_WRITER_HPP

#include "Helper.h"
#include <algorithm>

namespace datahandler
{
	namespace writer
	{
	   template <class Iterator, class Stream>
	   void run(Iterator start, Iterator end, Stream &stream)
	   {
		   std::for_each(start, end, [&](const auto &value) { stream << ::datahandler::helper::to_string(value) << std::endl; });
	   }
   }
}

#endif
