#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "ray.h"
#include "intersection.h"
#include "material.h"
#include "math.h"

class Sphere
{
public:
	Sphere(vec3 position, float radius, Material material);
	Sphere();

	Intersection intersect(const Ray &r) const
	{
		vec3 SP;
		float t, b, d;

		SP = m_position - r.getOrigin();
		b = vec3::dot(SP, r.getDirection());
		d = b * b - vec3::dot(SP, SP) + m_radius * m_radius;

		if (d < 0.0f)
			return Intersection::invalidIntersection;

		d = std::sqrt(d);
		t = (t = b - d) > EPSILON ? t : ((t = b + d) > EPSILON ? t : -1.0f);

		if (t == -1.0f)
			return Intersection::invalidIntersection;

		auto &x = Intersection();
		x.setPosition(r.getOrigin() + r.getDirection() * t);
		x.setNormal((x.getPosition() - m_position) / m_radius);
		x.setT(t);
		x.setMaterial(m_material);

		return x;
	}
private:
	vec3 m_position;
	float m_radius;
	Material m_material;
protected:
};

#endif