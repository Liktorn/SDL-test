#include <SDL.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

using namespace bw;

int main(int argc, char ** argv)
{
	srand((unsigned int)time(NULL));

	// Create the screen
	Screen screen;
	if (screen.init() == false)
	{
		std::cout << "Error initialising SDL." << std::endl;
	}

	Swarm swarm;

	// main loop
	while (true)
	{	
		//returns the ticks since the loop started to elapsed
		int elapsed = SDL_GetTicks();

		//update the swarm 
		swarm.update(elapsed);
		
		// sin() makes a value that goes from -1 to 1
		// this makes it go from 0 to 255 (unsigned char is max 255)
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.003)) * 128);

		// Making NPARTICLES amount of random particles and print them on the screen
		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) 
		{
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			//some magic to make it a circle and not a oval
			int y = particle.m_y  * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		//blur effect
		screen.boxBlur();

		// Draw the screen
		screen.update();
		// check and see wether to continue the loop
		if (screen.processEvents() == false)
			break;
	}

	//Pause the console so that the window does not exit imediatly
	std::cout << "like this" << std::endl;
	system("PAUSE"); // <-- this will stop the console from closing.

	//destroy all windows, renderers, textures etc...
	screen.close();

	return 0;
}