#pragma once
#ifndef __COLOR_H__
#define __COLOR_H__
class Color
{
public:
	float r_, g_, b_;
	Color(float r = 0, float g = 0, float b = 0) : r_{ r }, g_{ g }, b_{ b } {};
	Color operator+(const Color& c) { return Color(r_ + c.r_, g_ + c.g_, b_ + c.b_); };
	Color operator*(const Color& c) { return Color(r_ * c.r_, g_ * c.g_, b_ * c.b_); };
	Color operator*(float c) { return Color(r_ * c, g_ * c, b_ * c); };
	Color operator==(const Color& c) { return r_ == c.r_ && g_ == c.g_ && b_ == c.b_; };
	Color operator+=(const Color& c) { return Color(r_ + c.r_, g_ + c.g_, b_ + c.b_); };
};
#endif