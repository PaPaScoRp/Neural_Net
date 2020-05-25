#include "Layer_Dense.h"
Layer_Dense::Layer_Dense(int n_inputs, int n_neurons) {
	weights = .10 * weights.Random(n_inputs, n_neurons);
	biases = Eigen::ArrayXd::Zero(n_neurons);
}

Eigen::MatrixXd Layer_Dense::forward(Eigen::MatrixXd inputs) {
	output = (inputs * weights);
	output.rowwise() += (biases.transpose()).matrix();
	return output;
}
