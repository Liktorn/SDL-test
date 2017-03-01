#pragma once

namespace bw {

struct Particle
{
	double m_x;
	double m_y;
	
private:
	double m_speed;
	double m_direction;


	//Methods
public:
	Particle();
	~Particle();
	void update(int interval);
	
private:
	void init();
};

} /* end namespace bw*/

