#include<iostream>
#include"MainServer.h"
#include"Protocol.h"

using namespace std;

int main()
{
	/*
	MainServer mainServer;
	mainServer.Init(8888);

	mainServer.Run();
	*/

	std::locale::global(std::locale("ko_KR.UTF-8"));

	Protocol_SendMessage s1, s2;
	s1.message = L"HI안뇽HI?";
	s1.session = "1234안뇽asdf";

	//wcout << s1.message << endl;
	cout << s1.session << endl;

	int ss;
	string s = Protocol_SendMessage::ToJson(s1, ss);
	cout << s << endl;

	s2 = Protocol_SendMessage::ToProtocol(s);
	//cout << s2.session << endl;
	//wcout << s2.message << endl;

    return 0;
}