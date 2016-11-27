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

	// �ʱ�ȭ �Լ�
	void Init(sockaddr_in6* addr);

	// ���� �Լ�
	void Run();

private:

	// Ŭ���̾�Ʈ ������ �޴� �Լ�
	void Receive();

	char session[256];
	sockaddr_in6* clientAddr;

	thread* t;
};

