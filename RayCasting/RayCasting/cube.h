#pragma once
#include "vector3d.h"
#include "color.h"
#include "ray.h"
#include "object.h"

class Cube : public Object
{
public:
	Vector3d p0_, p1_, p2_; //�����εĶ�������
	Vector3d p_; //�����ε���������
	Cube() {};
	virtual bool intersect(Ray ray, Hit& hit);  //����Ƿ��ཻ
};
