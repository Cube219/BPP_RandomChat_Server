#pragma once
#include<vector>
#include<thread>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<net/if.h>
#include<arpa/inet.h>

#include"ConnectedClient.h"

using namespace std;

class MainServer
{
public:
	MainServer();
	~MainServer();

	// ������ �ʱ�ȭ�ϴ� �Լ�
	void Init(unsigned int port);

	// ������ �����ϴ� �Լ�
	bool Run();

private:
	// ������ üũ�ϴ� �Լ�
	void CheckSession();

	vector<ConnectedClient*> connectedClients;
	thread* sessionCheckThread;

	unsigned int port;
	int serverFd, clientFd;
	sockaddr_in6 serverAddr;

	char buffer[256];
};

