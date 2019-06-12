#include "matrix_4x4.h"

matrix_4x4::matrix_4x4(const float a_m00 /*= 1.0f*/, const float a_m01 /*= 0.0f*/, const float a_m02 /*= 0.0f*/, const float a_m03 /*= 0.0f*/,
					   const float a_m10 /*= 0.0f*/, const float a_m11 /*= 1.0f*/, const float a_m12 /*= 0.0f*/, const float a_m13 /*= 0.0f*/,
					   const float a_m20 /*= 0.0f*/, const float a_m21 /*= 0.0f*/, const float a_m22 /*= 1.0f*/, const float a_m23 /*= 0.0f*/,
					   const float a_m30 /*= 0.0f*/, const float a_m31 /*= 0.0f*/, const float a_m32 /*= 0.0f*/, const float a_m33 /*= 1.0f*/) :
	_2d{ a_m00, a_m01, a_m02, a_m03, a_m10, a_m11, a_m12, a_m13, a_m20, a_m21, a_m22, a_m23, a_m30, a_m31, a_m32, a_m33  }
{}

matrix_4x4::matrix_4x4(const vector_4& a_right, const vector_4& a_up, const vector_4 a_forward, const vector_4 a_time) :
	axes{ a_right, a_up, a_forward, a_time }
{}

matrix_4x4 matrix_4x4::operator*(const matrix_4x4& a_rhs) const
{
	return
	{
		_2d[0][0] * a_rhs._2d[0][0] + _2d[1][0] * a_rhs._2d[0][1] + _2d[2][0] * a_rhs._2d[0][2] + _2d[3][0] * a_rhs._2d[0][3],
		_2d[0][1] * a_rhs._2d[0][0] + _2d[1][1] * a_rhs._2d[0][1] + _2d[2][1] * a_rhs._2d[0][2] + _2d[3][1] * a_rhs._2d[0][3],
		_2d[0][2] * a_rhs._2d[0][0] + _2d[1][2] * a_rhs._2d[0][1] + _2d[2][2] * a_rhs._2d[0][2] + _2d[3][2] * a_rhs._2d[0][3],
		_2d[0][3] * a_rhs._2d[0][0] + _2d[1][3] * a_rhs._2d[0][1] + _2d[2][3] * a_rhs._2d[0][2] + _2d[3][3] * a_rhs._2d[0][3],

		_2d[0][0] * a_rhs._2d[1][0] + _2d[1][0] * a_rhs._2d[1][1] + _2d[2][0] * a_rhs._2d[1][2] + _2d[3][0] * a_rhs._2d[1][3],
		_2d[0][1] * a_rhs._2d[1][0] + _2d[1][1] * a_rhs._2d[1][1] + _2d[2][1] * a_rhs._2d[1][2] + _2d[3][1] * a_rhs._2d[1][3],
		_2d[0][2] * a_rhs._2d[1][0] + _2d[1][2] * a_rhs._2d[1][1] + _2d[2][2] * a_rhs._2d[1][2] + _2d[3][2] * a_rhs._2d[1][3],
		_2d[0][3] * a_rhs._2d[1][0] + _2d[1][3] * a_rhs._2d[1][1] + _2d[2][3] * a_rhs._2d[1][2] + _2d[3][3] * a_rhs._2d[1][3],

		_2d[0][0] * a_rhs._2d[2][0] + _2d[1][0] * a_rhs._2d[2][1] + _2d[2][0] * a_rhs._2d[2][2] + _2d[3][0] * a_rhs._2d[2][3],
		_2d[0][1] * a_rhs._2d[2][0] + _2d[1][1] * a_rhs._2d[2][1] + _2d[2][1] * a_rhs._2d[2][2] + _2d[3][1] * a_rhs._2d[2][3],
		_2d[0][2] * a_rhs._2d[2][0] + _2d[1][2] * a_rhs._2d[2][1] + _2d[2][2] * a_rhs._2d[2][2] + _2d[3][2] * a_rhs._2d[2][3],
		_2d[0][3] * a_rhs._2d[2][0] + _2d[1][3] * a_rhs._2d[2][1] + _2d[2][3] * a_rhs._2d[2][2] + _2d[3][3] * a_rhs._2d[2][3],

		_2d[0][0] * a_rhs._2d[3][0] + _2d[1][0] * a_rhs._2d[3][1] + _2d[2][0] * a_rhs._2d[3][2] + _2d[3][2] * a_rhs._2d[3][3],
		_2d[0][1] * a_rhs._2d[3][0] + _2d[1][1] * a_rhs._2d[3][1] + _2d[2][1] * a_rhs._2d[3][2] + _2d[3][2] * a_rhs._2d[3][3],
		_2d[0][2] * a_rhs._2d[3][0] + _2d[1][2] * a_rhs._2d[3][1] + _2d[2][2] * a_rhs._2d[3][2] + _2d[3][2] * a_rhs._2d[3][3],
		_2d[0][3] * a_rhs._2d[3][0] + _2d[1][3] * a_rhs._2d[3][1] + _2d[2][3] * a_rhs._2d[3][2] + _2d[3][3] * a_rhs._2d[3][3]
	};
}

vector_4 matrix_4x4::operator*(const vector_4& a_rhs) const
{
	return
	{
		_2d[0][0] * a_rhs[0] + _2d[1][0] * a_rhs[1] + _2d[2][0] * a_rhs[2] + _2d[3][0] * a_rhs[3],
		_2d[0][1] * a_rhs[0] + _2d[1][1] * a_rhs[1] + _2d[2][1] * a_rhs[2] + _2d[3][1] * a_rhs[3],
		_2d[0][2] * a_rhs[0] + _2d[1][2] * a_rhs[1] + _2d[2][2] * a_rhs[2] + _2d[3][2] * a_rhs[3],
		_2d[0][3] * a_rhs[0] + _2d[1][3] * a_rhs[1] + _2d[2][3] * a_rhs[2] + _2d[3][3] * a_rhs[3]
	};
}

matrix_4x4& matrix_4x4::operator*=(const matrix_4x4& a_rhs)
{
	*this = *this * a_rhs;

	return *this;
}

matrix_4x4 matrix_4x4::operator+(const matrix_4x4& a_rhs) const
{
	return
	{
		_2d[0][0] + a_rhs[0][0], _2d[0][1] + a_rhs[0][1], _2d[0][2] + a_rhs[0][2], _2d[0][3] + a_rhs[0][3],
		_2d[1][0] + a_rhs[1][0], _2d[1][1] + a_rhs[1][1], _2d[1][2] + a_rhs[1][2], _2d[1][3] + a_rhs[1][3],
		_2d[2][0] + a_rhs[2][0], _2d[2][1] + a_rhs[2][1], _2d[2][2] + a_rhs[2][2], _2d[2][3] + a_rhs[2][3],
		_2d[3][0] + a_rhs[3][0], _2d[3][1] + a_rhs[3][1], _2d[3][2] + a_rhs[3][2], _2d[3][3] + a_rhs[3][3]
	};
}

matrix_4x4& matrix_4x4::operator+=(const matrix_4x4& a_rhs)
{
	*this = *this + a_rhs;

	return *this;
}

matrix_4x4 matrix_4x4::operator-(const matrix_4x4& a_rhs) const
{
	return
	{
		_2d[0][0] - a_rhs[0][0], _2d[0][1] - a_rhs[0][1], _2d[0][2] - a_rhs[0][2], _2d[0][3] - a_rhs[0][3],
		_2d[1][0] - a_rhs[1][0], _2d[1][1] - a_rhs[1][1], _2d[1][2] - a_rhs[1][2], _2d[1][3] - a_rhs[1][3],
		_2d[2][0] - a_rhs[2][0], _2d[2][1] - a_rhs[2][1], _2d[2][2] - a_rhs[2][2], _2d[2][3] - a_rhs[2][3],
		_2d[3][0] - a_rhs[3][0], _2d[3][1] - a_rhs[3][1], _2d[3][2] - a_rhs[3][2], _2d[3][3] - a_rhs[3][3]
	};
}

matrix_4x4& matrix_4x4::operator-=(const matrix_4x4& a_rhs)
{
	*this = *this - a_rhs;

	return *this;
}

matrix_4x4& matrix_4x4::operator=(const matrix_4x4& a_rhs)
{
	axes[0] = a_rhs.axes[0];
	axes[1] = a_rhs.axes[1];
	axes[2] = a_rhs.axes[2];
	axes[3] = a_rhs.axes[3];

	return *this;
}

matrix_4x4::operator float* ()
{
	return _1d;
}

matrix_4x4::operator const float* () const
{
	return _1d;
}

vector_4 & matrix_4x4::operator[](const int index)
{
	return axes[index];
}

const vector_4 & matrix_4x4::operator[](const int index) const
{
	return axes[index];
}

void matrix_4x4::setRotateX(const float a_rotation)
{
	_2d[1][1] = cos(a_rotation);
	_2d[1][2] = sin(a_rotation);
	_2d[2][1] = -sin(a_rotation);
	_2d[2][2] = cos(a_rotation);
}

void matrix_4x4::setRotateY(const float a_rotation)
{
	_2d[0][0] = cos(a_rotation);
	_2d[0][2] = -sin(a_rotation);
	_2d[2][0] = sin(a_rotation);
	_2d[2][2] = cos(a_rotation);
}

void matrix_4x4::setRotateZ(const float a_rotation)
{
	_2d[0][0] = cos(a_rotation);
	_2d[0][1] = sin(a_rotation);
	_2d[1][0] = -sin(a_rotation);
	_2d[1][1] = cos(a_rotation);
}