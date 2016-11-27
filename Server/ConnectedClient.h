#pragma once
#include<netinet/in.h>

#include<thread>
#include<iostream>
using namespace std;

class ConnectedClient
{
public:
	ConnectedClient();
	~ConnectedClient();

	// 초기화 함수
	void Init(sockaddr_in6* addr);

	// 시작 함수
	void Run();

private:

	// 클라이언트 정보를 받는 함수
	void Receive();

	char session[256];
	sockaddr_in6* clientAddr;

	thread* t;
};

