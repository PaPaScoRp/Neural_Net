#pragma once
using namespace std;
struct Spiral_Data {
	//X = inputs. A 2D array
	//Y = ? 1D array
	Eigen::MatrixXd X;
	Eigen::ArrayXd y;
};


/*

points = 3
classes = 10
--
x = 30 row. 2 col
y = 30col
ix =range ( 0,3)

---------------------------------
	ix [point] = {
	for(int i = points*class_number; i < points*(class_number+1) < i++) {
	   ix[i] = i
	}

	for(auto const &i : ix){
	
	}
	*/

	/*
	def spiral_data(points, classes):
		X = np.zeros((points*classes, 2))

		y = np.zeros(points*classes, dtype='uint8')
		for class_number in range(classes):
			ix = range(points*class_number, points*(class_number+1))
			r = np.linspace(0.0, 1, points)  # radius
			t = np.linspace(class_number*4, (class_number+1)*4, points) + np.random.randn(points)*0.2
			X[ix] = np.c_[r*np.sin(t*2.5), r*np.cos(t*2.5)]
			y[ix] = class_number
		return X, y

	print(spiral_data(3, 100))
	*/
Spiral_Data Data_Generator(int points, int const classes) {

	Eigen::MatrixXd X = Eigen::ArrayXXd::Zero((points * classes), 2);
	Eigen::ArrayXd y = Eigen::ArrayXd::Zero(points * classes);

	int f = 0;
	int k = 0;
	for (int class_number = 0; class_number < classes; class_number++) {

		Eigen::VectorXd r = Eigen::VectorXd::LinSpaced(points, 0.0, 1).transpose(); //radius
		Eigen::VectorXd t = Eigen::VectorXd::LinSpaced(points, class_number * 4, (class_number + 1) * 4).transpose() + Eigen::VectorXd::Random(points).transpose()*0.2;
		
		//for (int k = ix[0]; k < ix[points] ; k++)
		
		//X[ix] = np.c_[r * np.sin(t * 2.5), r * np.cos(t * 2.5)] python
		X.row(k) << r.array() * ((t * 2.5).array()).sin(), r.array()* ((t * 2.5).array()).cos(); // cpp
			

			for (int f2 = k; f2 < k + points; f2++) {
				y[f2] = class_number;		
					}
				
			

		k = k + points;
	}

	return { X, y };
//for(int i = points * class_number; i < points * (class_number + 1); i++) {
				
}				
				

