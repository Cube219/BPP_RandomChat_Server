#include "ConnectedClient.h"

#include<unistd.h>

ConnectedClient::ConnectedClient()
{
}


ConnectedClient::~ConnectedClient()
{
}

// �ʱ�ȭ �Լ�
void ConnectedClient::Init(sockaddr_in6* addr)
{
	clientAddr = addr;
}

// ���� �Լ�
void ConnectedClient::Run()
{
	// �ش� Ŭ���̾�Ʈ�� ������ ������ ����� ������ ����
	t = new thread(&ConnectedClient::Receive, this);
}
// Ŭ���̾�Ʈ ������ �޴� �Լ�
void ConnectedClient::Receive()
{
	while(1) {
		cout << clientAddr->sin6_port << endl;
		usleep(1000000);
	}
}