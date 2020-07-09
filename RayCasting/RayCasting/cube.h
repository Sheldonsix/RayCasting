#pragma once
#include "vector3d.h"
#include "color.h"
#include "ray.h"
#include "object.h"

class Cube : public Object
{
public:
	Vector3d p0_, p1_, p2_; //三角形的顶点坐标
	Vector3d p_; //三角形的重心坐标
	Cube() {};
	virtual bool intersect(Ray ray, Hit& hit);  //检测是否相交
};
