#include "Camera.h"

int main()
{
	double f = 50.0;
	double arat = 1.8;
	double s_size = 35.0;
	int hres = 200;
	Camera cam(f, arat, s_size, hres);
	ray_vec_t *frame = cam.get_frame_rays(0);

	return 0;
}