#include "Particle.h"
#include <stdlib.h>


namespace bw
{

void Particle::update()
{
	//Update the position
	m_x += xSpeed;
	m_y += ySpeed;

	//Checking so they are not outside of the screen
	if (m_x < -1.0 || m_x > 1.0)
		xSpeed = -xSpeed;
	if (m_y < -1.0 || m_y > 1.0)
		ySpeed = -ySpeed;
}
Particle::Particle()
{
	// starting in a random location
	m_x = ((2.0 * rand()) / RAND_MAX) - 1;
	m_y = ((2.0 * rand()) / RAND_MAX) - 1;

	//getting a random speed
	speed = 0.005;
	xSpeed = speed * (((2.0 * rand()) / RAND_MAX) - 1);
	ySpeed = speed * (((2.0 * rand()) / RAND_MAX) - 1);

}


Particle::~Particle()
{
}

} /*end of namespace*/