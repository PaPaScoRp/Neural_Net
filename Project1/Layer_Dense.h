#pragma once
#include <eigen/dense>
class Layer_Dense{
private:
	Eigen::MatrixXd weights, output;
	Eigen::ArrayXd biases;

public:
	Layer_Dense(int, int);
	Eigen::MatrixXd forward(Eigen::MatrixXd);
};

