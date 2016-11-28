#pragma once
#include<netinet/in.h>

#include<thread>
#include<iostream>
#include<string>
using namespace std;

class ConnectedClient
{
public:
	ConnectedClient();
	~ConnectedClient();

	// �ʱ�ȭ �Լ�
	void Init(sockaddr_in6* addr);

	// ���� �Լ�
	void Run();

private:

	// Ŭ���̾�Ʈ ������ �޴� �Լ�
	void Receive();

	string session;
	sockaddr_in6* clientAddr;

	thread* t;
};

