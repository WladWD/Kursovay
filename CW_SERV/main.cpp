#include <WinSock2.h>
#include <iostream>
#include <fstream>
using namespace std;
#define check_OK(mFlag) if(mFlag) \
					{WSACleanup(); \
					   return 0;}  

#define PORT 5522
#define mPlayer 2
int mPort;
SOCKET mSock;

uint32_t mPlayerCount;
SOCKET mClient[mPlayer];
sockaddr_in mClientAddr[mPlayer];
struct SendReciveStruct 
{
	int32_t x, y;
	int32_t player_number;//0 - first player, 1 - second player, 2 - first player win, 3 - second player win 
	bool full;
} mSendRecive;
int32_t mCurrentPlayer;

void GameCicle(void);

int main() 
{
	ifstream mf("port.txt");
	mf >> mPort;
	mf.close();

	WSADATA wd;
	int eror = WSAStartup(0x0202, &wd);

	check_OK(eror || wd.wVersion != 0x0202);
	mSock = socket(AF_INET, SOCK_STREAM, NULL);

	sockaddr_in mAddr;
	mAddr.sin_family = AF_INET;
	mAddr.sin_port = htons(mPort);
	mAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	check_OK(bind(mSock, (LPSOCKADDR)&mAddr, sizeof(mAddr)) == SOCKET_ERROR);
	check_OK(listen(mSock, 2) == SOCKET_ERROR);


	int32_t mClientAddrSize = sizeof(sockaddr_in);
	while (mPlayerCount < mPlayer) 
	{
		mClient[mPlayerCount] = accept(mSock, (sockaddr *)(mClientAddr + mPlayerCount), &mClientAddrSize);
		check_OK(mClient[mPlayerCount] == INVALID_SOCKET);

		mSendRecive.player_number = mPlayerCount;
		send(mClient[mPlayerCount], (const char *)&mSendRecive, sizeof(mSendRecive), 0);
		++mPlayerCount;
	}

	GameCicle();

	shutdown(mSock, SD_SEND);
	closesocket(mSock);
	WSACleanup();
	return 0;
}

void GameCicle(void) 
{
	while (mSendRecive.player_number < 2)
	{
		int mNeed = sizeof(mSendRecive);
		int mSize = recv(mClient[mCurrentPlayer], (char *)&mSendRecive, sizeof(mSendRecive), 0);//0
		mSize = send(mClient[mCurrentPlayer ^ 1], (char *)&mSendRecive, sizeof(mSendRecive), 0);//1

		mSize = recv(mClient[mCurrentPlayer ^ 1], (char *)&mSendRecive, sizeof(mSendRecive), 0);//1
		mSize = send(mClient[mCurrentPlayer], (char *)&mSendRecive, sizeof(mSendRecive), 0);//0
		
		if(!mSendRecive.full)
			mCurrentPlayer ^= 1;
	}
	//send(mClient[mCurrentPlayer], (char *)&mSendRecive, sizeof(mSendRecive), 0);//0
	/*while (mSendRecive.player_number < 2)
	{
		int mNeed = sizeof(mSendRecive);
		int mSize = recv(mClient[0], (char *)&mSendRecive, sizeof(mSendRecive), 0);//0
		mSize = send(mClient[0], (char *)&mSendRecive, sizeof(mSendRecive), 0);//1

		mSize = recv(mClient[0], (char *)&mSendRecive, sizeof(mSendRecive), 0);//1
		mSize = send(mClient[0], (char *)&mSendRecive, sizeof(mSendRecive), 0);//0
	}*/
}
