#pragma once
#include"PCH_ConnectedClient.h"

using namespace std;

class ConnectedClient
{
public:
	ConnectedClient();
	~ConnectedClient();

	// 초기화 함수
	void Init(int fd, sockaddr_in6* addr, std::function<void(ConnectedClient*)> endConnectionCallback);

	// 시작 함수
	void Run();

	// 클라이언트에게 데이터를 보내는 함수
	void Send(const char* data, int dataSize);
	void Send(const string& data);

	// 세션이 만료되었는지 확인하는 함수
	bool isSessionExpired();

private:

	// 클라이언트로부터 데이터를 받는 함수
	void Receive();
	// 내용을 분석하는 함수
	void Process(const char* buf, int bufSize);

	//void(MainServer::*endConnectionCallback)(ConnectedClient*);
	std::function<void(ConnectedClient*)> endConnectionCallback;

	string session;

	int clientFd;
	sockaddr_in6* clientAddr;

	thread* t;
};

