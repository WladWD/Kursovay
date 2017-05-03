#include "CellBufferPoly.h"


Battleship::CellBufferPoly::CellBufferPoly(Shader::ShaderDrawCell * mShader, glm::vec4 mColor) : mShader(mShader), mColor(mColor)
{
	Init();
}

Battleship::CellBufferPoly::~CellBufferPoly()
{
}

void Battleship::CellBufferPoly::Init(void)
{
}

void Battleship::CellBufferPoly::Draw(glm::vec2 mPos, glm::vec2 mScale)
{
	struct ms
	{
		glm::vec2 mPos;
		glm::vec4 mCol;
	}x[4]; /*= { { mStart, mColor }, { mEnd, mColor } };*/

	for (register int i = 0; i < 4; ++i)
		x[i] = {mPos + mvert[i] * mScale, mColor };

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(ms), x);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(ms), ((float *)x) + 2);

	glUseProgram(mShader->GetProgram());

	mShader->SetWorld(glm::mat4(1.0f));
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	mShader->ResetProgram();
	glUseProgram(0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void Battleship::CellBufferPoly::Draw(glm::vec2 mPos, glm::vec2 mScale, glm::vec4 mColor)
{
	struct ms
	{
		glm::vec2 mPos;
		glm::vec4 mCol;
	}x[4]; /*= { { mStart, mColor }, { mEnd, mColor } };*/

	for (register int i = 0; i < 4; ++i)
		x[i] = { mPos + mvert[i] * mScale, mColor };

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(ms), x);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(ms), ((float *)x) + 2);

	glUseProgram(mShader->GetProgram());

	mShader->SetWorld(glm::mat4(1.0f));
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	mShader->ResetProgram();
	glUseProgram(0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
