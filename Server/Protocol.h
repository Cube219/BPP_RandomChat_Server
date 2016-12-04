#include<string>
#include<bitset>
#include<iostream>
#include"json.hpp"
// 메시지들 정의

using json = nlohmann::json;

enum ResultCode
{
	Sucess = 1,
	Fail = 2,
	FailToParseJson = 98
};

// 1. 연결
struct Protocol_Connect
{
	static std::string ToJson(Protocol_Connect protocol, int& size)
	{
		json j;
		j["protocolType"] = "Protocol_Connect";

		j["data"] = "";

		return j.dump();
	}

	static Protocol_Connect ToProtocol(std::string data)
	{
		Protocol_Connect p;

		json j = json::parse(data);
		if(j["protocolType"] != "Protocol_Connect") {
			return p;
		}

		return p;
	}
};
// 2. 연결 결과
struct Protocol_ConnectResult
{
	ResultCode resultCode;
	std::string session;

	static std::string ToJson(Protocol_ConnectResult protocol, int& size)
	{
		json j;
		j["protocolType"] = "Protocol_ConnectResult";

		j["data"]["resultCode"] = static_cast<int>(protocol.resultCode);
		j["data"]["session"] = protocol.session;

		return j.dump();
	}

	static Protocol_ConnectResult ToProtocol(std::string data)
	{
		Protocol_ConnectResult p;

		json j = json::parse(data);
		if(j["protocolType"] != "Protocol_ConnectResult") {
			return p;
		}

		int c = j["data"]["resultCode"];
		p.resultCode = static_cast<ResultCode>(c);
		p.session = j["data"]["session"];

		return p;
	}
};

// 3. 유저를 찾음
struct Protocol_FindUser
{
	std::string session;

	static std::string ToJson(Protocol_FindUser protocol, int& size)
	{
		json j;
		j["protocolType"] = "Protocol_FindUser";

		j["data"]["session"] = protocol.session;

		return j.dump();
	}

	static Protocol_FindUser ToProtocol(std::string data)
	{
		Protocol_FindUser p;

		json j = json::parse(data);
		if(j["protocolType"] != "Protocol_FindUser") {
			return p;
		}

		p.session = j["data"]["session"];

		return p;
	}
};
// 4. 유저를 찾은 결과
struct Protocol_FindUserResult
{
	ResultCode resultCode;
	std::string userSession;

	static std::string ToJson(Protocol_FindUserResult protocol, int& size)
	{
		json j;
		j["protocolType"] = "Protocol_FindUserResult";

		j["data"]["resultCode"] = static_cast<int>(protocol.resultCode);
		j["data"]["userSession"] = protocol.userSession;

		return j.dump();
	}

	static Protocol_FindUserResult ToProtocol(std::string data)
	{
		Protocol_FindUserResult p;

		json j = json::parse(data);
		if(j["protocolType"] != "Protocol_FindUserResult") {
			return p;
		}

		int c = j["data"]["resultCode"];
		p.resultCode = static_cast<ResultCode>(c);
		p.userSession = j["data"]["userSession"];

		return p;
	}
};

// 5. 메시지를 보냄
struct Protocol_SendMessage
{
	std::string session;
	std::wstring message;

	static std::string ToJson(Protocol_SendMessage protocol, int& size)
	{
		json j;
		j["protocolType"] = "Protocol_SendMessage";

		j["data"]["session"] = protocol.session;
		j["data"]["message"] = protocol.message;

		return j.dump();
	}

	static Protocol_SendMessage ToProtocol(std::string data)
	{
		Protocol_SendMessage p;

		json j = json::parse(data);
		if(j["protocolType"] != "Protocol_SendMessage") {
			return p;
		}

		p.session = j["data"]["session"];
		std::wstring t = j["data"]["message"];
		p.message = t;

		return p;
	}
};
// 6. 메시지를 보낸 결과
struct Protocol_SendMessageResult
{
	ResultCode resultCode;

	static std::string ToJson(Protocol_SendMessageResult protocol, int& size)
	{
		json j;
		j["protocolType"] = "Protocol_SendMessageResult";

		j["data"]["resultCode"] = static_cast<int>(protocol.resultCode);

		return j.dump();
	}

	static Protocol_SendMessageResult ToProtocol(std::string data)
	{
		Protocol_SendMessageResult p;

		json j = json::parse(data);
		if(j["protocolType"] != "Protocol_SendMessageResult") {
			return p;
		}

		int c = j["data"]["resultCode"];
		p.resultCode = static_cast<ResultCode>(c);

		return p;
	}
};

// 7. 메시지를 받음
struct Protocol_GetMessage
{
	std::string sendUserSession;
	std::wstring message;

	static std::string ToJson(Protocol_GetMessage protocol, int& size)
	{
		json j;
		j["protocolType"] = "Protocol_GetMessage";

		j["data"]["sendUserSession"] = protocol.sendUserSession;
		j["data"]["message"] = protocol.message;

		return j.dump();
	}

	static Protocol_GetMessage ToProtocol(std::string data)
	{
		Protocol_GetMessage p;

		json j = json::parse(data);
		if(j["protocolType"] != "Protocol_GetMessage") {
			return p;
		}

		p.sendUserSession = j["data"]["sendUserSession"];
		std::wstring t = j["data"]["message"];
		p.message = t;

		return p;
	}
};

// 8. 방을 나감
struct Protocol_LeaveRoom
{
	std::string session;

	static std::string ToJson(Protocol_LeaveRoom protocol, int& size)
	{
		json j;
		j["protocolType"] = "Protocol_LeaveRoom";

		j["data"]["session"] = protocol.session;

		return j.dump();
	}

	static Protocol_LeaveRoom ToProtocol(std::string data)
	{
		Protocol_LeaveRoom p;

		json j = json::parse(data);
		if(j["protocolType"] != "Protocol_LeaveRoom") {
			return p;
		}

		p.session = j["data"]["session"];

		return p;
	}
};
// 9. 상대방이 방을 나감
struct Protocol_UserLeaved
{
	std::string leavedUserSession;

	static std::string ToJson(Protocol_UserLeaved protocol, int& size)
	{
		json j;
		j["protocolType"] = "Protocol_UserLeaved";

		j["data"]["leavedUserSession"] = protocol.leavedUserSession;

		return j.dump();
	}

	static Protocol_UserLeaved ToProtocol(std::string data)
	{
		Protocol_UserLeaved p;

		json j = json::parse(data);
		if(j["protocolType"] != "Protocol_UserLeaved") {
			return p;
		}

		p.leavedUserSession = j["data"]["leavedUserSession"];

		return p;
	}
};