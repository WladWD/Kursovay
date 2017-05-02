#include "CellBufferLine.h"




Battleship::CellBufferLine::CellBufferLine(Shader::ShaderDrawCell *mShader, float mWidth, glm::vec4 mColor) : mShader(mShader), mWidth(mWidth), mColor(mColor)
{
	Init();
}

Battleship::CellBufferLine::~CellBufferLine()
{
}

void Battleship::CellBufferLine::Init(void)
{
}

void Battleship::CellBufferLine::Draw(glm::vec2 mStart, glm::vec2 mEnd)
{
	glLineWidth(mWidth);

	struct ms 
	{
		glm::vec2 mPos;
		glm::vec4 mCol;
	}x[2] = { {mStart, mColor} , {mEnd, mColor} };

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(ms), x);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(ms), ((float *)x) + 2);

	glUseProgram(mShader->GetProgram());

	mShader->SetWorld(glm::mat4(1.0f));
	glDrawArrays(GL_LINES, 0, 2);

	mShader->ResetProgram();
	glUseProgram(0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
