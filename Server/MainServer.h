#pragma once
#include<list>
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

	// 설정을 초기화하는 함수
	void Init(unsigned int port);

	// 서버를 실행하는 함수
	bool Run();

private:
	// 세션을 체크하는 함수
	void CheckSession();

	// Client의 접속이 종료되었음을 알리는 Callback 함수
	void EndConnection_Callback(ConnectedClient* client);

	// Client를 list에서 지우는 함수
	void RemoveClientFromList(ConnectedClient* client);

	list<unique_ptr<ConnectedClient>> connectedClients;
	thread* sessionCheckThread;

	unsigned int port;
	int serverFd, clientFd;
	sockaddr_in6 serverAddr;

	char buffer[256];
};

