#include <cmath>
#include <array>


typedef std::array<double, 3> pos_t; // Position (z, theta, phi)
typedef std::array<double, 3> orient_t;  // Orientation
typedef boost::multi_array<double, 3> ray_vec_t;

class Camera
{
	// Current camera state vector
	pos_t position;
	orient_t orientation;

	// Camera physical properties
	double focal_length;
	double aspect_ratio;
	double sensor_size;
	int h_res; //horizontal resolution
	int v_res;
	double fov;

	ray_vec_t frame_rays;

	// Public Methods
public:
	Camera();
	Camera(double f, double arat, double s, int hres);
	~Camera();
	ray_vec_t* get_frame_rays(int frame);


};

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
}

Camera::~Camera()
{

}

ray_vec_t* Camera::get_frame_rays(int frame)
{

	ray_vec_t frame(boost::extents[h_res][v_res][5]);

	for(int i=0; i<h_res; i++)
	{
		for(int j=0; j<v_res; j++)
		{
			frame[i][j][0] = position[0];
			frame[i][j][1] = position[1];
			frame[i][j][2] = position[2];

			frame[i][j][3] = orientation[0] - fov*(i/h_res - 1/2);
			frame[i][j][4] = orientation[1] - (fov/(2*aspect_ratio))*(j/v_res - 1/2);
		}
	}
	return &frame;
}