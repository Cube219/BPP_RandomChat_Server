#include "Protocol.h"



Protocol::Protocol()
{
}


Protocol::~Protocol()
{
}

template<typename T>
char* Protocol::ToBinary(T message)
{
	return 0;
}

template<typename T>
T Protocol::ToMessage(char * data)
{
	return T();
}
