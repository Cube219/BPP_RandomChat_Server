#pragma once
#include<vector>

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

	// 설정을 초기화하는 함수
	void Init(unsigned int port);

	// 서버를 실행하는 함수
	bool Run();

private:
	vector<ConnectedClient*> connectedClients;

	unsigned int port;
	int serverFd, clientFd;
	sockaddr_in6 serverAddr;

	char buffer[256];
};

