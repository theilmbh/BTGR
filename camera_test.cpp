#include <iostream>
#include "Camera.h"

int main()
{
	double f = 50.0;
	double arat = 1.8;
	double s_size = 35.0;
	int hres = 200;

	pos_t pos({-10, 0, 0});
	orient_t orient({0, 0, 0});
	Camera cam(f, arat, s_size, hres);
	cam.set_position(pos);
	cam.set_orientation(orient);
	ray_vec_t *frame = cam.get_frame_rays(0);
	std::cout << (*frame)[2][3][1] << std::endl;
	return 0;
}