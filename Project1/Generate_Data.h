#pragma once
#include <numeric>
struct Spiral_Data {
	//X = inputs. A 2D array
	//Y = ? 1D array
	Eigen::MatrixXd X;
	Eigen::VectorXd y;
	Spiral_Data(int, int);
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

Spiral_Data::Spiral_Data(int points = 0, int const classes) {
	X = Eigen::ArrayXXd::Zero((points * classes), 2);
	y = Eigen::ArrayXd::Zero(points * classes);
	vector<int> ix;
	for(int class_number = 0; class_number < classes; class_number++) {

		for(int i = points * class_number; i < points * (class_number + 1); i++) {

			ix.push_back(i);
			Eigen::VectorXd r = Eigen::VectorXd::LinSpaced(points, 0.0, 1).transpose(); //radius
			Eigen::VectorXd t = Eigen::VectorXd::LinSpaced(points, class_number * 4, (class_number + 1) * 4).transpose() + Eigen::VectorXd::Random(points).transpose()*0.2;
			for (int j = 0; j < ix.size(); j++)

				X << r * (t * 2.5).sin(), r* (t * 2.5).cos();

		}
	}
}


