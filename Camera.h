#include <array>
#include <boost/multi_array.hpp>


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