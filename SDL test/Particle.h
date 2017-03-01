#pragma once

namespace bw {

struct Particle
{
	double m_x;
	double m_y;
	double speed;
	double xSpeed;
	double ySpeed;

public:
	Particle();
	~Particle();
	void update();
};

} /* end namespace bw*/

