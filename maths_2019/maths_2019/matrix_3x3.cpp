#include "matrix_3x3.h"

matrix_3x3::matrix_3x3(const float a_m00 /*= 1.0f*/, const float a_m01 /*= 0.0f*/, const float a_m02 /*= 0.0f*/,
	const float a_m10 /*= 0.0f*/, const float a_m11 /*= 1.0f*/, const float a_m12 /*= 0.0f*/,
	const float a_m20 /*= 0.0f*/, const float a_m21 /*= 0.0f*/, const float a_m22 /*= 1.0f*/) :
	_2d{ a_m00, a_m01, a_m02, a_m10, a_m11, a_m12, a_m20, a_m21, a_m22 }
{

}

matrix_3x3::matrix_3x3(const vector_3& a_right, const vector_3& a_up, const vector_3 a_forward) :
				axes{a_right, a_up, a_forward}
{}

matrix_3x3 matrix_3x3::operator*(const matrix_3x3 a_rhs) const
{
	return
	{
		_2d[0][0] * a_rhs._2d[0][0] + _2d[1][0] * a_rhs._2d[0][1] + _2d[2][0] * a_rhs._2d[0][2],
		_2d[0][1] * a_rhs._2d[0][0] + _2d[1][1] * a_rhs._2d[0][1] + _2d[2][1] * a_rhs._2d[0][2],
		_2d[0][2] * a_rhs._2d[0][0] + _2d[1][2] * a_rhs._2d[0][1] + _2d[2][2] * a_rhs._2d[0][2],

		_2d[0][0] * a_rhs._2d[1][0] + _2d[1][0] * a_rhs._2d[1][1] + _2d[2][0] * a_rhs._2d[1][2],
		_2d[0][1] * a_rhs._2d[1][0] + _2d[1][1] * a_rhs._2d[1][1] + _2d[2][1] * a_rhs._2d[1][2],
		_2d[0][2] * a_rhs._2d[1][0] + _2d[1][2] * a_rhs._2d[1][1] + _2d[2][2] * a_rhs._2d[1][2],

		_2d[0][0] * a_rhs._2d[2][0] + _2d[1][0] * a_rhs._2d[2][1] + _2d[2][0] * a_rhs._2d[2][2],
		_2d[0][1] * a_rhs._2d[2][0] + _2d[1][1] * a_rhs._2d[2][1] + _2d[2][1] * a_rhs._2d[2][2],
		_2d[0][2] * a_rhs._2d[2][0] + _2d[1][2] * a_rhs._2d[2][1] + _2d[2][2] * a_rhs._2d[2][2]
	};
}

vector_3 matrix_3x3::operator*(const vector_3& a_rhs) const
{
	return
	{
		_2d[0][0] * a_rhs[0] + _2d[1][0] * a_rhs[1] + _2d[2][0] * a_rhs[2],
		_2d[0][1] * a_rhs[0] + _2d[1][1] * a_rhs[1] + _2d[2][1] * a_rhs[2],
		_2d[0][2] * a_rhs[0] + _2d[1][2] * a_rhs[1] + _2d[2][2] * a_rhs[2]
	};
}

matrix_3x3 matrix_3x3::operator+(const matrix_3x3& a_rhs) const
{
	return
	{
		_2d[0][0] + a_rhs[0][0], _2d[0][1] + a_rhs[0][1], _2d[0][2] + a_rhs[0][2],
		_2d[1][0] + a_rhs[1][0], _2d[1][1] + a_rhs[1][1], _2d[1][2] + a_rhs[1][2],
		_2d[2][0] + a_rhs[2][0], _2d[2][1] + a_rhs[2][1], _2d[2][2] + a_rhs[2][2]
	};
}

matrix_3x3& matrix_3x3::operator+=(const matrix_3x3& a_rhs)
{
	*this = *this + a_rhs;

	return *this;
}

matrix_3x3 matrix_3x3::operator-(const matrix_3x3& a_rhs) const
{
	return
	{
		_2d[0][0] - a_rhs[0][0], _2d[0][1] - a_rhs[0][1], _2d[0][2] - a_rhs[0][2],
		_2d[1][0] - a_rhs[1][0], _2d[1][1] - a_rhs[1][1], _2d[1][2] - a_rhs[1][2],
		_2d[2][0] - a_rhs[2][0], _2d[2][1] - a_rhs[2][1], _2d[2][2] - a_rhs[2][2]
	};
}

matrix_3x3& matrix_3x3::operator-=(const matrix_3x3& a_rhs)
{
	*this = *this - a_rhs;

	return *this;
}

matrix_3x3& matrix_3x3::operator=(const matrix_3x3& a_rhs)
{
	axes[0] = a_rhs.axes[0];
	axes[1] = a_rhs.axes[1];
	axes[2] = a_rhs.axes[2];

	return *this;
}

matrix_3x3::operator float* ()
{
	return _1d;
}

matrix_3x3::operator const float* () const
{
	return _1d;
}

vector_3 & matrix_3x3::operator[](const int index)
{
	return axes[index];
}

const vector_3 & matrix_3x3::operator[](const int index) const
{
	return axes[index];
}

void matrix_3x3::setRotateX(const float a_rotation)
{
	_2d[1][1] = cos(a_rotation);
	_2d[1][2] = sin(a_rotation);
	_2d[2][1] = -sin(a_rotation);
	_2d[2][2] = cos(a_rotation);
}

void matrix_3x3::setRotateY(const float a_rotation)
{
	_2d[0][0] = cos(a_rotation);
	_2d[0][2] = -sin(a_rotation);
	_2d[2][0] = sin(a_rotation);
	_2d[2][2] = cos(a_rotation);
}

void matrix_3x3::setRotateZ(const float a_rotation)
{
	_2d[0][0] = cos(a_rotation);
	_2d[0][1] = sin(a_rotation);
	_2d[1][0] = -sin(a_rotation);
	_2d[1][1] = cos(a_rotation);
}