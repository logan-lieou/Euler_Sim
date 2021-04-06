#include <math.h>

void SetBnd(int b, float x[], int N);
void Diffuse(int b, float x[], float x0[], float diff, float dt, int iter, int N);
void Project(float vx[], float vy[], float p[], float div[], int iter, int N);
void Advect(int b, float d[], float d0[], float vx[], float vy[], float dt, int N);

int IX(int x, int y, int N)
{
	if (x < 0) { x = 0; }
	if (x > N-1) { x = N-1; }

	if (y < 0) { y = 0; }
	if (y > N-1) { y = N-1; }

	return (y*N) + x;
}

void LinSolve(int b, float x[], float x0[], float a, float c, int iter, int N) {
	float cRecip = 1.0 / c;
	for (int k = 0; k < iter; k++) {
		for (int j = 1; j < N - 1; j++) {
			for (int i = 1; i < N - 1; i++) {
				x[IX(i, j, N)] = (x0[IX(i, j, N)] + a
						*(x[IX(i+1, j, N)]
						+x[IX(i-1, j, N)]
						+x[IX(i, j+1, N)]
						+x[IX(i, j-1, N)]
						+x[IX(i, j, N)]
						+x[IX(i, j, N)]
						)) * cRecip;
			}
		}
		setBnd(b, x, N);
	}
}
