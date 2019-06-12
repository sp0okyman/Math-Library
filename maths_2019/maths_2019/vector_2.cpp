#pragma once
#include "vector_2.h"
#include <cassert>

//vector_2::vector_2() : x(0.0f), y(0.0f)
//{}

vector_2::vector_2(const float a_x, const float a_y) : data{ a_x, a_y }
{};

float& vector_2::operator[] (const int a_index)
{
	assert((a_index >= 0) && (a_index < 2)
		&& "Vector 2 index out of range");
	return data[a_index];
}

vector_2 vector_2::operator+(const vector_2& a_rhs) const
{
	return vector_2(x + a_rhs.x, y + a_rhs.y);
}

vector_2 vector_2::operator-(const vector_2& a_rhs) const
{
	return vector_2(x - a_rhs.x, y - a_rhs.y);
}

vector_2 vector_2::operator*(const float a_rhs) const
{
	return vector_2 (x * a_rhs, y * a_rhs);
}

vector_2 vector_2::operator/(const float a_rhs) const
{
	return vector_2 (x / a_rhs, y / a_rhs);
}

vector_2& vector_2::operator+=(const vector_2& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}       

vector_2& vector_2::operator-=(const vector_2& a_rhs) 
{
	*this = *this - a_rhs;
	return *this;
}

vector_2& vector_2::operator*=(const float a_rhs) 
{
	*this = *this * a_rhs;
	return *this;
}

vector_2& vector_2::operator/=(const float a_rhs)
{
	*this = *this / a_rhs;
	return *this;
}

float vector_2::square_magnitude() const
{
	return x * x + y * y;
}

float vector_2::magnitude() const
{
	return std::sqrt(square_magnitude());
}

void vector_2::normalise()
{
	float mag = magnitude();
	this->x /= mag;
	this->y /= mag;
}

vector_2 vector_2::normalised()
{
	vector_2 norm_vector = vector_2(x / magnitude(), y / magnitude());
	return norm_vector;
}

float vector_2::dot(const vector_2& a_vector_2) const
{
	return (x * a_vector_2.x) + (y * a_vector_2.y);
}

vector_2::operator float* ()
{
	return data;
}

vector_2::operator const float* () const
{
	return data;
}

vector_2 operator*(const float a_lhs, const vector_2& a_rhs)
{
	return a_rhs * a_lhs;
}