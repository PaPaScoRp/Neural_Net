#pragma once
#include <numeric>
struct Spiral_Data {
	//X = inputs. A 2D array
	//Y = ? 1D array
	Eigen::Array2Xd X;
	Eigen::ArrayXd y;
	Spiral_Data(int, int);
};
/*
def spiral_data(points, classes):
	X = np.zeros((points*classes, 2))
	y = np.zeros(points*classes, dtype='uint8')
	for class_number in range(classes):
		ix = range(points*class_number, points*(class_number+1))
		r = np.linspace(0.0, 1, points)  # radius
		t = np.linspace(class_number*4, (class_number+1)*4, points) + np.random.randn(points)*0.2
		print (r)
		X[ix] = np.c_[r*np.sin(t*2.5), r*np.cos(t*2.5)]
		y[ix] = class_number
	return X, y

print(spiral_data(3, 100))
*/

Spiral_Data::Spiral_Data(int points, int classes) {
	X = Eigen::ArrayXd::Zero((points * classes), 2);
	y = Eigen::ArrayXd::Zero(points * classes);
	for (int pashm = 0; pashm <= classes; pashm++) {
		ix
	}
}

