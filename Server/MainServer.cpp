#include "MainServer.h"
#include<iostream>
#include<memory.h>

MainServer::MainServer()
{
}


MainServer::~MainServer()
{
}

// 설정을 초기화하는 함수
void MainServer::Init(unsigned int port)
{
	this->port = port;
}

// 서버를 실행하는 함수
bool MainServer::Run()
{
	cout << "Starting RandomChat server..." << endl;
	cout << endl;

	// 소켓을 염
	cout << "Opening socket(port : " << port << ")... ";
	serverFd = socket(PF_INET6, SOCK_STREAM, IPPROTO_TCP);
	if(serverFd == -1) { // 여는데 실패
		cout << "\nFail to open socket!!" << endl;
		return false;
	}
	cout << "Complete!" << endl;

	//serverAddr 셋팅
	serverAddr.sin6_family = AF_INET6;
	serverAddr.sin6_flowinfo = 0;
	serverAddr.sin6_port = htons(port);
	serverAddr.sin6_addr = in6addr_any;
	//serverAddr.sin6_scope_id = if_nametoindex("etho");

	// bind
	cout << "Starting to bind... ";
	if(bind(serverFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
		cout << "\nFail to binding!!" << endl;
		return false;
	}
	cout << "Complete!" << endl;

	// Listen
	cout << "Starting listen... ";
	if(listen(serverFd, 100) < 0) {
		cout << "\nFail to listen!!" << endl;
		return false;
	}
	cout << "Complete!" << endl;

	cout << "\nSuccessfuly open the server!" << endl;

	socklen_t len;
	// 클라이언트의 입력을 기다림
	while(1) {
		sockaddr_in6 clientAddr;
		len = sizeof(clientAddr);
		cout << "Current client Number : " << connectedClients.size() << endl;
		clientFd = accept(serverFd, (struct sockaddr*)&clientAddr, &len);
		
		if(clientFd < 0) { // 클라이언트와 연결 실패
			cout << "Fail to connect client!!" << endl;
			return false;
		}

		// connectedClients에 연결된 클라이언트 정보 넣어주고 실행
		char b[256];
		inet_ntop(AF_INET6, &clientAddr.sin6_addr, b, sizeof(b));
		cout << "Client connected (IP : " << b<<")" << endl;

		ConnectedClient* client = new ConnectedClient();
		client->Init(&clientAddr);
		client->Run();

		connectedClients.push_back(client);
	}
}