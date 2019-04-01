#ifndef DATA_HANDLER_ASYNC_WRITER_HPP
#define DATA_HANDLER_ASYNC_WRITER_HPP

#include "Writer.h"
#include <vector>
#include <future>

namespace datahandler
{
	namespace asyncWriter
	{
		template <class DataType, class Stream>
		void run(std::vector <DataType> v, Stream &stream)
		{
			using Iterator = std::vector <DataType>::iterator;
			std::async(std::launch::async, [&](Iterator start, Iterator end) { datahandler::writer::run(start, end, stream); }, v.begin(), v.end());
		}
	}
}

#endif
