#include <SFML/Graphics.h>

#include "physics.h"
#include "options.h"
#define SIZE 70
#define SCALE 8

struct Container {
	private:
		Physics physics;

		int size;
		float dt;
		float diff;
		float visc;

		float px[SIZE*SIZE];
		float py[SIZE*SIZE];
};
