#pragma once
#include "vector_3.h"
#include <cassert>

vector_3::vector_3(const float a_x, const float a_y , const float a_z) : data{ a_x, a_y, a_z }
{};

float& vector_3::operator[] (const int a_index)
{
	assert((a_index >= 0) && (a_index < 2)
		&& "Vector 3 index out of range");
	return data[a_index];
}

vector_3 vector_3::operator+(const vector_3& a_rhs) const
{
	return vector_3(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
}

vector_3 vector_3::operator-(const vector_3& a_rhs) const
{
	return vector_3(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
}

vector_3 vector_3::operator*(const float a_rhs) const
{
	return vector_3(x * a_rhs, y * a_rhs, z * a_rhs);
}

vector_3 vector_3::operator/(const float a_rhs) const
{
	return vector_3(x / a_rhs, y / a_rhs, z / a_rhs);
}

vector_3& vector_3::operator+=(const vector_3& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

vector_3& vector_3::operator-=(const vector_3& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}

vector_3& vector_3::operator*=(const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

vector_3& vector_3::operator/=(const float a_rhs)
{
	*this = *this / a_rhs;
	return *this;
}

vector_3& vector_3::operator= (const vector_3& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;

	return *this;
}

vector_3 vector_3::cross(const vector_3& a_vector_3) const
{
	return
	{
		y * a_vector_3.z - z * a_vector_3.y,
		z * a_vector_3.x - x * a_vector_3.z,
		x * a_vector_3.y - y * a_vector_3.x
	};
}

float vector_3::square_magnitude() const
{
	return x * x + y * y + z * z;
}

float vector_3::magnitude() const
{
	return std::sqrt(square_magnitude());
}

float vector_3::dot(const vector_3& a_vector_4) const
{
	return (x * a_vector_4.x) + (y * a_vector_4.y) + (z * a_vector_4.z);
}

void vector_3::normalise()
{
	float mag = magnitude();

	this->x /= mag;
	this->y /= mag;
	this->z /= mag;
}

vector_3 vector_3::normalised()
{
	vector_3 norm_vector = vector_3(x / magnitude(), y / magnitude(), z / magnitude());
	return norm_vector;
}

vector_3::operator float* ()
{
	return data;
}

vector_3::operator const float* () const
{
	return data;
}

vector_3 operator*(const float a_lhs, const vector_3& a_rhs)
{
	return a_rhs * a_lhs;
}