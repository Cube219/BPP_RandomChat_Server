#include "MainServer.h"
#include<iostream>
#include<memory.h>

MainServer::MainServer()
{
}


MainServer::~MainServer()
{
}

// ������ �ʱ�ȭ�ϴ� �Լ�
void MainServer::Init(unsigned int port)
{
	this->port = port;
}

// ������ �����ϴ� �Լ�
bool MainServer::Run()
{
	cout << "Starting RandomChat server..." << endl;
	cout << endl;

	// ������ ��
	cout << "Opening socket(port : " << port << ")... ";
	serverFd = socket(PF_INET6, SOCK_STREAM, 0);
	if(serverFd == -1) { // ���µ� ����
		cout << "\nFail to open socket!!" << endl;
		return false;
	}
	cout << "Complete!" << endl;

	//serverAddr ����
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

	cout << "Successfuly open the server!" << endl;

	socklen_t len;
	len = sizeof(clientAddr);
	// Ŭ���̾�Ʈ�� �Է��� ��ٸ�
	while(1) {
		cout << "Current client Number : " << connectedClients.size() << endl;
		clientFd = accept(serverFd, (struct sockaddr*)&clientAddr, &len);

		if(clientFd < 0) { // Ŭ���̾�Ʈ�� ���� ����
			cout << "Fail to connect client!!" << endl;
			return false;
		}

		// connectedClients�� ����� Ŭ���̾�Ʈ ���� �־��ְ� ����
		cout << "Client connected (IP : " << ")" << endl;
	}
}