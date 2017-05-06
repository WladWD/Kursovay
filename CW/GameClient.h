#include <WinSock2.h>
#include "MainHeader.h"
#include <string>

#pragma once
namespace Battleship
{
	struct SendReciveStruct
	{
		int32_t x, y;
		int32_t player_number;//0 - first player, 1 - second player, 2 - first player win, 3 - second player win 
		bool full;
	};
#define check_OK(mFlag) if(mFlag) \
					{\
MessageBox(NULL, L"its OVER, No Connection!!!", L"Все пипец!!!", MB_OK);\
						throw 1000;\
					   }  
	//WSACleanup(); 
#define PORT 5522
#define FILENAME "resource\\serv_ip_port.txt"
	class GameClient
	{
		SOCKET mSock;
		sockaddr_in mAddr;

		SendReciveStruct mSendRecive;
	public:
		GameClient();
		~GameClient();

		bool Init(void);
		void Sending(int32_t x, int32_t y, bool full, int32_t winer = -1);
		SendReciveStruct Recive();
	};
}

