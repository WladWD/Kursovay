#include "Engine.h"


Battleship::Engine::Engine(HWND hwnd) : wait_to_answ(false), hwnd(hwnd), mWait1(false), mWait2(false), mDataSave(false), cWinCounter(0)
{
	mTimer = new Timer::Timer();
	float ss = 2.0f;
	float lx = 0.0412f * ss, ly = 0.078f * ss;
	float bx = 0.04125f, by = 0.875;
	mDim = new Dimension(lx, ly);
	mShader = new Shader::ShaderDrawCell(new Resource::FileResource(0, 0));
	mDrawPole2 = new DrawPole(mShader, mDim, glm::vec2(bx, by),  2.8f, glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
	mDrawPole1 = new DrawPole(mShader, mDim, glm::vec2(bx + lx * 10 * 0.5f + bx * 2.0f , 0.875), 2.8f, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), true);

	mClient = new GameClient(hwnd);
	my_turn = tx = mClient->Init();
	//connect to server and take -> my_turn
}

Battleship::Engine::~Engine()
{
	delete mTimer;
	delete mDim;
	delete mDrawPole1;
	delete mDrawPole2;
	delete mShader;
	delete mClient;
}

void Battleship::Engine::Tick(void)
{
	mTimer->Tick();
}

void Battleship::Engine::Init(void)
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glDepthMask(GL_TRUE);
}

void Battleship::Engine::Pick2(int32_t x, int32_t y, bool full)
{
	mDrawPole1->Pick2(x, y, full);
}

void Battleship::Engine::SetDateSave(void)
{
	mDataSave = true;
}

void Battleship::Engine::Pick(int32_t x, int32_t y)
{
	//my_turn
	//if(!my_turn)
	//return;

	GLfloat mdata[4];
	glGetFloatv(GL_VIEWPORT, mdata);
	int32_t mx, my;
	bool full;
	bool mok = mDrawPole1->Pick1(glm::vec2(x / mdata[2], y / mdata[3]), mx, my, full, true);

	if (mok && my_turn && !mWait1)//mok && wait_to_answ
	{
		/*if (mDrawPole2->ItsOver())
		{
			mClient->Sending(mx, my, full, tx ? 4 : 3);
			//MessageBox(NULL, tx ? L"You Lose(((!!!" : L"You Win!!!", L"Game Over", MB_OK);
		}
		else*/

			mClient->Sending(mx, my, full);
			mWait1 = true;
		//SendReciveStruct mRecived = mClient->Recive();
		//mDrawPole1->Pick2(mRecived.x, mRecived.y, mRecived.full);

		//my_turn = !my_turn;---------
	}

		//send to  server(coord, full);
		//and wait for answ;
		//;
	//mDrawPole2->Pick2(5, 5, false);

	/*mClient->Sending(mx, my, full);
		SendReciveStruct mRecived = mClient->Recive();
		my_turn = !my_turn;
		mRecived = mClient->Recive();
		mDrawPole2->Pick2(mRecived.x, mRecived.y, mRecived.full);
		if (mDrawPole2->ItsOver()) 
		{
			mClient->Sending(mx, my, full, tx ? 3 : 4);
		}
		my_turn = !my_turn;*/
}

bool Battleship::Engine::CloseGame(void)
{
	return false;
}

void Battleship::Engine::Resize(uint32_t mX, uint32_t mY)
{
	glViewport(0, 0, mX, mY);
	glClearColor(0.8f, 0.5f, 0.99f, 1.0f);
	glClearDepthf(1.0f);
}

void Battleship::Engine::Draw(void)
{
	Tick();
	static bool once = true;
	float dt = mTimer->GetDeltaTime();
	float gt = mTimer->GetFullTime();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mDrawPole1->DrawGrid();
	mDrawPole1->DrawCell(dt, gt);

	mDrawPole2->DrawGrid();
	mDrawPole2->DrawCell(dt, gt);

	if (cWinCounter == 20 && once)
	{
		mClient->Sending(0, 0, 0, tx ? 3 : 4);
		MessageBox(NULL, L"You Win!!!", L"Game Over", MB_OK);
		once = false;
		DestroyWindow(hwnd);
	}
	else if (mDrawPole2->ItsOver() && once)
	{
		mClient->Sending(0, 0, 0, tx ? 4 : 3);
		MessageBox(NULL, L"You Lose(((!!!", L"Game Over", MB_OK);
		once = false;
		DestroyWindow(hwnd);
	}

	//if (!my_turn)//!ok && !my_turn)
	//{
	//	int32_t mx, my;
	//	bool full;

	//	SendReciveStruct mRecived = mClient->Recive();
	//	mRecived.full = mDrawPole2->Pick3(mRecived.x, mRecived.y);
	//	mClient->Sending(mRecived.x, mRecived.y, mRecived.full);

	//	/*if (mDrawPole2->ItsOver())
	//	{
	//		mClient->Sending(mx, my, full, tx ? 3 : 4);
	//	}*/
	//	if(!mRecived.full)////////
	//		my_turn = !my_turn;
	//}
	//else if (wait_to_answ && !my_turn)
	//{
	//	SendReciveStruct mRecived = mClient->Recive();
	//	mDrawPole1->Pick2(mRecived.x, mRecived.y, mRecived.full);
	//	//my_turn = !my_turn;
	//	wait_to_answ = false;

	//	if(mRecived.full)////////
	//		wait_to_answ = my_turn = true;
	//}
	//if(!my_turn)
	//take answ or continue draw;
	//if answ receive -> mDrawPole2->Pick2(coord, full);

	if (mWait1 && mDataSave)
	{
		SendReciveStruct mRecived = mClient->Recive();
		mDrawPole1->Pick2(mRecived.x, mRecived.y, mRecived.full);

		my_turn = mRecived.full;
		if (my_turn)
			++cWinCounter;

		mDataSave = false;
		mWait1 = false;
	}
	else if (!my_turn && mDataSave)//!ok && !my_turn)
	{
		int32_t mx, my;
		bool full;

		SendReciveStruct mRecived = mClient->Recive();
		mRecived.full = mDrawPole2->Pick3(mRecived.x, mRecived.y);

		mClient->Sending(mRecived.x, mRecived.y, mRecived.full);

		/*if (mDrawPole2->ItsOver())
		{
			mClient->Sending(mx, my, full, tx ? 3 : 4);
		}*/
		if(!mRecived.full)////////
			my_turn = !my_turn;

		mDataSave = false;
	}
}

/*
send-receive struct;
{
int32_t x, y;
int32_t player_number;
bool full;
}
*/