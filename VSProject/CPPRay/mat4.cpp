#include "mat4.h"

mat4::mat4()
{
	m = new float[4 * 4];
}

mat4 mat4::initIdentity()
{
	for (int i = 0; i < 4 * 4; i++)
	{
		m[i] = 0;
	}

	m[0 + 0 * 4] = 1;
	m[1 + 1 * 4] = 1;
	m[2 + 2 * 4] = 1;
	m[3 + 3 * 4] = 1;

	return *this;
}

mat4 mat4::initTranslation(float x, float y, float z)
{
	this->initIdentity();

	m[0 + 0 * 4] = x;
	m[1 + 1 * 4] = y;
	m[2 + 2 * 4] = z;

	return *this;
}

// I need to implement quaternions before doing this, not touching ugly euler angles
mat4 mat4::initRotation()
{
	return *this;
}

mat4 mat4::initScale(float x, float y, float z)
{
	this->initIdentity();

	m[0 + 0 * 4] = x;
	m[1 + 1 * 4] = y;
	m[2 + 2 * 4] = z;

	return *this;
}

mat4 mat4::operator*(const mat4 &other)
{
	mat4 data = mat4();

	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			data.m[i + j * 4] = m[0 + j * 4] * other.m[i + 0 * 4] +
								m[0 + j * 4] * other.m[i + 0 * 4] +
								m[0 + j * 4] * other.m[i + 0 * 4] +
								m[0 + j * 4] * other.m[i + 0 * 4];
		}
	}

	return data;
}

float mat4::getValueAtIndex(int x, int y)
{
	if (m != nullptr)
		return m[x + y * 4];
	
	return 0.0f;
}