#include "ConnectedClient.h"


ConnectedClient::ConnectedClient()
{
}


ConnectedClient::~ConnectedClient()
{
}

// 초기화 함수
void ConnectedClient::Init(int fd, sockaddr_in6* addr, std::function<void(ConnectedClient*)> endConnectionCallback)
{
	clientFd = fd;
	clientAddr = addr;
	this->endConnectionCallback = endConnectionCallback;

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
// 클라이언트로부터 데이터를 받는 함수
void ConnectedClient::Receive()
{
	char buffer[256];
	while(1) {
		// recv함수로 클라이언트로부터 오는 데이터 받음
		int receiveSize = recv(clientFd, buffer, sizeof(buffer), 0);

		if(receiveSize <= 0) { // Connection 종료됨
			std::cout << "End connection. (" << session << ")" << endl;
			break;
		}

		// 받은 내용을 분석
		Process(buffer, receiveSize);
	}

	// 소켓 닫음
	close(clientFd);
	// 연결 종료 Callback함수 호출
	endConnectionCallback(this);
}

// 내용을 분석하는 함수
void ConnectedClient::Process(char* buf, int bufSize)
{
	std::cout << buf << endl;
}

// 클라이언트에게 데이터를 보내는 함수
void ConnectedClient::Send()
{

}

// 세션이 만료되었는가?
bool ConnectedClient::isSessionExpired()
{
	return false;
}