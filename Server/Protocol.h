#pragma once
#include<string>

class Protocol
{
public:
	Protocol();
	~Protocol();

	template<typename T>
	char* ToBinary(T message);

	template<typename T>
	T ToMessage(char* data);
};

// �޽����� ����
struct Message_Connect
{
	char* ToBinardy(Message_Connect message)
	{
	}

	Message_Connect ToMessage(char* data)
	{
	}
};

struct Message_ConnectResult
{
	unsigned int resultCode;
	std::string session;
};