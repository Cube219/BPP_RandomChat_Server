#include<string>
#include<bitset>
#include<iostream>
#include"json/json.h"
// �޽����� ����

enum ResultCode
{
	Sucess = 1,
	Fail = 2,
	FailToParseJson = 98
};

// 1. ����
struct Protocol_Connect
{
	static std::string ToJson(Protocol_Connect protocol, int& size)
	{
		char* b = new char[1];
		size = 1;

		return b;
	}

	static Protocol_Connect ToProtocol(std::string data)
	{
		Protocol_Connect p;
		return p;
	}
};
// 2. ���� ���
struct Protocol_ConnectResult
{
	ResultCode resultCode;
	std::string session;

	static std::string ToJson(Protocol_ConnectResult protocol, int& size)
	{

	}

	static Protocol_ConnectResult ToProtocol(std::string data)
	{

	}
};

// 3. ������ ã��
struct Protocol_FindUser
{
	std::string session;

	static std::string ToJson(Protocol_FindUser protocol, int& size)
	{

	}

	static Protocol_FindUser ToProtocol(std::string data)
	{

	}
};
// 4. ������ ã�� ���
struct Protocol_FindUserResult
{
	ResultCode resultCode;
	std::string userSession;

	static std::string ToJson(Protocol_FindUserResult protocol, int& size)
	{

	}

	static Protocol_FindUserResult ToProtocol(std::string data)
	{

	}
};

// 5. �޽����� ����
struct Protocol_SendMessage
{
	std::string session;
	std::wstring message;

	static std::string ToJson(Protocol_SendMessage protocol, int& size)
	{

	}

	static Protocol_SendMessage ToProtocol(std::string data)
	{

	}
};
// 6. �޽����� ���� ���
struct Protocol_SendMessageResult
{
	ResultCode resultCode;

	static std::string ToJson(Protocol_SendMessageResult protocol, int& size)
	{

	}

	static Protocol_SendMessageResult ToProtocol(std::string data)
	{

	}
};

// 7. �޽����� ����
struct Protocol_GetMessage
{
	std::string sendUserSession;
	std::wstring message;

	static std::string ToJson(Protocol_GetMessage protocol, int& size)
	{

	}

	static Protocol_GetMessage ToProtocol(std::string data)
	{

	}
};

// 8. ���� ����
struct Protocol_LeaveRoom
{
	std::string session;

	static std::string ToJson(Protocol_LeaveRoom protocol, int& size)
	{

	}

	static Protocol_LeaveRoom ToProtocol(std::string data)
	{

	}
};
// 9. ������ ���� ����
struct Protocol_UserLeaved
{
	std::string leavedUserSession;

	static std::string ToJson(Protocol_UserLeaved protocol, int& size)
	{

	}

	static Protocol_UserLeaved ToProtocol(std::string data)
	{

	}
};