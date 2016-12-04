#include<iostream>
#include"MainServer.h"
#include"Protocol.h"

using namespace std;

int main()
{
	MainServer mainServer;
	mainServer.Init(8888);

	mainServer.Run();

    return 0;
}