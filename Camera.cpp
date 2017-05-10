#include <cmath>
#include <array>
#include <boost/multi_array.hpp>

#include "Camera.h"

Camera::Camera()
{

}

Camera::Camera(double f, double arat, double s, int hres)
{
	focal_length = f;
	aspect_ratio = arat;
	sensor_size = s;
	h_res = hres;
	v_res = (int) round(hres/arat);

	fov = 2.0*atan(s / (2.0*f));
	frame_rays.resize(boost::extents[h_res][v_res][5]);
}

Camera::~Camera()
{

}

ray_vec_t* Camera::get_frame_rays(int frame_num)
{

	for(int i=0; i<h_res; i++)
	{
		for(int j=0; j<v_res; j++)
		{
			frame_rays[i][j][0] = position[0];
			frame_rays[i][j][1] = position[1];
			frame_rays[i][j][2] = position[2];

			frame_rays[i][j][3] = orientation[0] - fov*(i/h_res - 1/2);
			frame_rays[i][j][4] = orientation[1] - (fov/(2*aspect_ratio))*(j/v_res - 1/2);
		}
	}
	return &frame_rays;
}