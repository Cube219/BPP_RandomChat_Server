#include "ConnectedClient.h"

#include<unistd.h>

ConnectedClient::ConnectedClient()
{
}


ConnectedClient::~ConnectedClient()
{
}

// 초기화 함수
void ConnectedClient::Init(sockaddr_in6* addr)
{
	clientAddr = addr;
}

// 시작 함수
void ConnectedClient::Run()
{
	// 해당 클라이언트의 데이터 접속을 담당할 스레드 생성
	t = new thread(&ConnectedClient::Receive, this);
}
// 클라이언트 정보를 받는 함수
void ConnectedClient::Receive()
{
	while(1) {
		cout << clientAddr->sin6_port << endl;
		usleep(1000000);
	}
}