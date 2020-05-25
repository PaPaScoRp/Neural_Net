#pragma once
#include <eigen/dense>
class Activation_ReLu {
public:
	Eigen::MatrixXd forward(Eigen::MatrixXd input) {
		return input.array().max(0);
	}
};