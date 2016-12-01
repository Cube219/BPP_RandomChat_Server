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

	Protocol p;
	Message_Connect mc;
	Message_ConnectResult mcr;
	mcr.resultCode = 1;
	mcr.session = "HI";

    return 0;
}