#include "Particle.h"
#include <math.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES // for C++
#include <cmath>


namespace bw
{


Particle::Particle()
{
	// initiate a random direction in radiants
	m_direction = (2 * M_PI * rand()) / RAND_MAX;
	// Initiate arandom speed
	m_speed = (0.0001 * rand()) / RAND_MAX;
}


Particle::~Particle()
{
}

void Particle::update(int interval)
{
	double xSpeed = m_speed * cos(m_direction);
	double ySpeed = m_speed * sin(m_direction);
	// xSpeed * interval makes the game runn equally fast on different computers
	m_x += xSpeed * interval;
	m_y += ySpeed * interval;
}

} /*end of namespace*/