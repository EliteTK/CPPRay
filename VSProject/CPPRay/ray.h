#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray
{
public:
	Ray(vec3 origin, vec3 direction);
	Ray(vec3 origin);
	Ray();

	void setOrigin(vec3 v);
	void setDirection(vec3 v);
	vec3 getOrigin();
	vec3 getDirection();
private:
	vec3 m_origin;
	vec3 m_direction;
};

#endif