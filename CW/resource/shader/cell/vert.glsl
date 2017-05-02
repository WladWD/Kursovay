//#version 100
/////////////////////////////////////////////////////////
//attribute
attribute vec2 gWorldPos;
attribute vec4 glWorldColor;
/////////////////////////////////////////////////////////
//varying
varying vec2 gFragWorldPos;
varying vec4 gFragColor;
/////////////////////////////////////////////////////////
//uniform
uniform mat4 mWorld;
/////////////////////////////////////////////////////////
//vertex shader
void main()
{
	vec4 gWorld = mWorld * vec4(gWorldPos, 0.0, 1.0);

	gFragWorldPos = gWorld;
	gFragColor = glWorldColor;

	gl_Position = gWorld;
}
/////////////////////////////////////////////////////////

