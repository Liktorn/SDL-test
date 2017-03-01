#pragma once
#include "Particle.h"

namespace bw
{

class Swarm
{
public:
	const static int NPARTICLES = 1000;

private:
	Particle *m_pParticles;

public:
	Swarm();
	~Swarm();
	void update();

	const Particle *const getParticles() { return m_pParticles; }
};

}
