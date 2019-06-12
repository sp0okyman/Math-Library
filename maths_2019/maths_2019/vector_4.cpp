#pragma once
#include "vector_4.h"
#include <cassert>

vector_4::vector_4(const float a_x, const float a_y, const float a_z, const float a_w) : data{ a_x, a_y, a_z, a_w }
{};

float& vector_4::operator[] (const int a_index)
{
	assert((a_index >= 0) && (a_index < 2)
		&& "Vector 4 index out of range");
	return data[a_index];
}

vector_4 vector_4::operator+(const vector_4& a_rhs) const
{
	return vector_4(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z, w + a_rhs.w);
}

vector_4 vector_4::operator-(const vector_4& a_rhs) const
{
	return vector_4(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z, w - a_rhs.w);
}

vector_4 vector_4::operator*(const float a_rhs) const
{
	return vector_4(x * a_rhs, y * a_rhs, z * a_rhs, w * a_rhs);
}

vector_4 vector_4::operator/(const float a_rhs) const
{
	return vector_4(x / a_rhs, y / a_rhs, z / a_rhs, w / a_rhs);
}

vector_4& vector_4::operator+=(const vector_4& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

vector_4& vector_4::operator-=(const vector_4& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}

vector_4& vector_4::operator*=(const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

vector_4& vector_4::operator/=(const float a_rhs)
{
	*this = *this / a_rhs;
	return *this;
}

vector_4& vector_4::operator= (const vector_4& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;

	return *this;
}

vector_4 vector_4::cross(const vector_4& a_vector_3) const
{
	return
	{
		y * a_vector_3.z - z * a_vector_3.y,
		z * a_vector_3.x - x * a_vector_3.z,
		x * a_vector_3.y - y * a_vector_3.x,
		w
	};
}

float vector_4::square_magnitude() const
{
	return x * x + y * y + z * z + w * w;
}

float vector_4::magnitude() const
{
	return std::sqrt(square_magnitude());
}

float vector_4::dot(const vector_4& a_vector_4) const
{
	return (x * a_vector_4.x) + (y * a_vector_4.y) + (z * a_vector_4.z) + (w * a_vector_4.w);
}

void vector_4::normalise()
{
	float mag = magnitude();

	this->x /= mag;
	this->y /= mag;
	this->z /= mag;
	this->w /= mag;
}

vector_4 vector_4::normalised()
{
	vector_4 norm_vector = vector_4(x / magnitude(), y / magnitude(), z / magnitude(), w / magnitude());
	return norm_vector;
}

vector_4::operator float* ()
{
	return data;
}

vector_4::operator const float* () const
{
	return data;
}

vector_4 operator*(const float a_lhs, const vector_4& a_rhs)
{
	return a_rhs * a_lhs;
}