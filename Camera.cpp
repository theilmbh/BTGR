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

	fov = 2.0*std::arctan(s / (2.0*f));
}
Camera::~Camera()
{

}

ray_vec_t* Camera::get_frame_rays(int frame)
{

}