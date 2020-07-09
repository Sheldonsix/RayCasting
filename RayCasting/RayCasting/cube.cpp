#include "cube.h"
#include <math.h>
#include <algorithm>
bool Cube::intersect(Ray ray, Hit& hit)
{
	hit.material_ = this->material_;
	hit.t_ = std::numeric_limits<float>::infinity();
	Vector3d O = ray.origin_;
	Vector3d V = ray.directionVector_;
	Vector3d P = p_; //ÖØÐÄ×ø±ê
	Vector3d S = p0_ - O;
	Vector3d E1 = p0_ - p1_;
	Vector3d E2 = p0_ - p2_;
	Vector3d a1 = E1.cross(E2);
	Vector3d a2 = S.cross(E2);
	Vector3d a3 = E1.cross(S);
	float b1 = S.dot(a1);
	float b2 = V.dot(a2);
	float b3 = V.dot(a3);
	float b4 = V.dot(a1);
	float t = b1 / b4;
	if (t <= 0.0) {
		return false;
	}
	else {
		float bt = b2 / b4;
		float gm = b3 / b4;
		if (bt >= 0 && bt <= 1 && gm >= 0 && gm <= 1 && bt + gm <= 1) {
			hit.t_ = t;
		}
		else {
			return false;
		}
		if (hit.t_ != std::numeric_limits<float>::infinity()) {
			//Vector3d tmp_direction = ray.directionVector_ * hit.t_;
			//hit.P_ = S + tmp_direction;
			hit.N_ = E1.cross(E2);
		}
	}
	hit.P_ = O + ray.directionVector_ * hit.t_ ;
	hit.N_.normalize();
	return true;
}