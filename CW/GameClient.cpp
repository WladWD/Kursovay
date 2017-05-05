#include "GameClient.h"


Battleship::GameClient::GameClient()
{
	std::ifstream mf(FILENAME);
	std::string mstrIP;
	mf >> mstrIP;

	WSADATA wd;
	int eror = WSAStartup(0x0202, &wd);

	check_OK(eror || wd.wVersion != 0x0202);
	mSock = socket(AF_INET, SOCK_STREAM, NULL);

	sockaddr_in mAddr;
	mAddr.sin_family = AF_INET;
	mAddr.sin_port = htons(PORT);
	
	check_OK(inet_addr(mstrIP.c_str()) == INADDR_NONE);
	mAddr.sin_addr.S_un.S_addr = inet_addr(mstrIP.c_str());

	check_OK(connect(mSock, (LPSOCKADDR)&mAddr, sizeof(mAddr)));

	recv(mSock, (char *)&mSendRecive, sizeof(mSendRecive), 0);

	mf.close();
}

Battleship::GameClient::~GameClient()
{
	shutdown(mSock, SD_SEND);
	closesocket(mSock);
	WSACleanup();
}

bool Battleship::GameClient::Init(void)
{
	return mSendRecive.player_number == 0;
}

void Battleship::GameClient::Sending(int32_t x, int32_t y, bool full, int32_t winer)
{
	mSendRecive.full = full;
	mSendRecive.x = x;
	mSendRecive.y = y;
	mSendRecive.player_number = winer != -1 ? winer : mSendRecive.player_number;

	send(mSock, (const char *)&mSendRecive, sizeof(mSendRecive), 0);
}

Battleship::SendReciveStruct Battleship::GameClient::Recive()
{
	recv(mSock, (char *)&mSendRecive, sizeof(mSendRecive), 0);
	return mSendRecive;
}
