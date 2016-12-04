#include "MainServer.h"
#include<iostream>
#include<memory.h>
#include<unistd.h>

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

	// 세션을 체크하는 스레드 생성
	sessionCheckThread = new thread(&MainServer::CheckSession, this);

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

		shared_ptr<ConnectedClient> client(new ConnectedClient());
		client->Init(clientFd, &clientAddr, std::bind(&MainServer::EndConnection_Callback, this, std::placeholders::_1));
		client->Run();
		
		connectedClients.push_back(client);
	}
}

// 세션을 체크하는 함수
void MainServer::CheckSession()
{
	while(1) {
		cout << "Checking Session..." << endl;

		bool isExpiredAnyOfThem = false;

		// 만료된 세션 제거
		for(auto it = connectedClients.begin(); it != connectedClients.end(); it++) {
			if(it->get()->isSessionExpired() == true) {
				RemoveClientFromList(it->get());
				isExpiredAnyOfThem = true;
				break;
			}
		}

		// 만약 만료된 것이 없으면 10초 뒤에 다시 체크
		if(isExpiredAnyOfThem == false) {
			usleep(10000000);
		}
	}
}

// Client의 접속이 종료되었음을 알리는 Callback 함수
void MainServer::EndConnection_Callback(ConnectedClient* client)
{
	RemoveClientFromList(client);
}

// Client를 list에서 지우는 함수
void MainServer::RemoveClientFromList(ConnectedClient* client)
{
	// 해당 클라이언트 connectedClients에서 제거
	for(auto it = connectedClients.begin(); it != connectedClients.end(); it++) {
		if(it->get() == client) {
			connectedClients.erase(it);
			break;
		}
	}

	cout << "Current client Number : " << connectedClients.size() << endl;
}