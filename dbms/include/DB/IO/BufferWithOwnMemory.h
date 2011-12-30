#pragma once

#include <vector>

#define DBMS_DEFAULT_BUFFER_SIZE 1048576ULL


namespace DB
{


/** Буфер, который сам владеет своим куском памяти для работы.
  * Аргумент шаблона - ReadBuffer или WriteBuffer
  */
template <typename Base>
class BufferWithOwnMemory : public Base
{
protected:
	std::vector<char> memory;
public:
	BufferWithOwnMemory(size_t size = DBMS_DEFAULT_BUFFER_SIZE) : Base(NULL, 0), memory(size)
	{
		Base::set(&memory[0], size);
	}
};


}
