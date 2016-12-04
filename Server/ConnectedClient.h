#pragma once
#include<netinet/in.h>

#include<thread>
#include<iostream>
#include<string>
#include<functional>

using namespace std;

class MainServer;

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
	void Send();

private:

	// 클라이언트로부터 데이터를 받는 함수
	void Receive();
	// 내용을 분석하는 함수
	void Process(char* buf, int bufSize);

	//void(MainServer::*endConnectionCallback)(ConnectedClient*);
	std::function<void(ConnectedClient*)> endConnectionCallback;

	string session;

	int clientFd;
	sockaddr_in6* clientAddr;

	thread* t;
};

