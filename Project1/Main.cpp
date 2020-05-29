#include <iostream>
#include <eigen/dense>
#include "Layer_Dense.h"
#include "Activation_ReLu.h"
#include "Timer.h"
#include "Generate_Data.h"
#include <vector>
#include <cmath>
using namespace std;

int main() {
	{ //scope for benchmark
		Timer timer; //initiate the timer for benchmark

		Eigen::MatrixXd inputs(3, 4);
		inputs << 1, 2, 3, 2.5,
			2.0, 5.0, -1.0, 2.0,
			-1.5, 2.7, 3.3, -0.8;
		Layer_Dense layer1(4, 5);
		Layer_Dense layer2(5, 2);
		Activation_ReLu activation;

		//cout << layer2.forward(activation.forward(layer1.forward(inputs))) << "\n\n\n";

		auto generated = Data_Generator(3, 100);
		cout << activation.forward(generated.X);
	}

}



