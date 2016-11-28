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

// 초기화 함수
void ConnectedClient::Init(sockaddr_in6* addr)
{
	clientAddr = addr;

	// 세션 id 생성 (uuid로 관리)
	boost::uuids::uuid u = boost::uuids::random_generator()();
	session = boost::uuids::to_string(u);
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
		cout << session << endl;
		usleep(1000000);
	}
}