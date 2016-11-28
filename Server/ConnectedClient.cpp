#include "ConnectedClient.h"

#include<unistd.h>
#include<boost/uuid/uuid.hpp>
#include<boost/uuid/uuid_generators.hpp>
#include<boost/uuid/uuid_io.hpp>

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

	// ���� id ���� (uuid�� ����)
	boost::uuids::uuid u = boost::uuids::random_generator()();
	session = boost::uuids::to_string(u);
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
		cout << session << endl;
		usleep(1000000);
	}
}