#pragma once
#include<vector>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<net/if.h>

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
	vector<ConnectedClient*> connectedClients;

	unsigned int port;
	int serverFd, clientFd;
	sockaddr_in6 serverAddr, clientAddr;

	char buffer[256];
};

