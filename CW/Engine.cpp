#include "Engine.h"


Battleship::Engine::Engine()
{
	mTimer = new Timer::Timer();
	float ss = 2.0f;
	float lx = 0.0412f * ss, ly = 0.078f * ss;
	float bx = 0.04125f, by = 0.875;
	mDim = new Dimension(lx, ly);
	mShader = new Shader::ShaderDrawCell(new Resource::FileResource(0, 0));
	mDrawPole1 = new DrawPole(mShader, mDim, glm::vec2(bx, by),  2.8f, glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
	mDrawPole2 = new DrawPole(mShader, mDim, glm::vec2(bx + lx * 10 * 0.5f + bx * 2.0f , 0.875), 2.8f, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), true);

	//connect to server and take -> my_turn
}

Battleship::Engine::~Engine()
{
	delete mTimer;
	delete mDim;
	delete mDrawPole1;
	delete mDrawPole2;
	delete mShader;
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

void Battleship::Engine::Pick(int32_t x, int32_t y)
{
	//my_turn
	//if(!my_turn)
	//return;

	GLfloat mdata[4];
	glGetFloatv(GL_VIEWPORT, mdata);
	bool ok = mDrawPole1->Pick1(glm::vec2(x / mdata[2], y / mdata[3]));

	if (ok)
		//send to  server(coord, full);
		//and wait for answ;
		;
	//mDrawPole2->Pick2(5, 5, false);
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

	float dt = mTimer->GetDeltaTime();
	float gt = mTimer->GetFullTime();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mDrawPole1->DrawGrid();
	mDrawPole1->DrawCell(dt, gt);

	mDrawPole2->DrawGrid();
	mDrawPole2->DrawCell(dt, gt);

	//if(!my_turn)
	//take answ or continue draw;
	//if answ receive -> mDrawPole2->Pick2(coord, full);
}

/*
send-receive struct;
{
int32_t x, y;
int32_t player_number;
bool full;
}
*/