#include <iostream>
#include <eigen/dense>
#include "Layer_Dense.h"
#include "Activation_ReLu.h"
#include "Timer.h"
#include "Generate_Data.h"
using namespace std;

int main() {
	{ //scope for benchmark
		Timer timer; //initiate the timer for benchmark



		//Eigen::ArrayXd a(4), b(4); 
		//a(0) = 1; a(1) = 2; a(2) = 3; a(3) = 5; 
		//b(0) = 2; b(1) = 0; b(2) = 4; b(3) = 0; 
		//cout << a.max(b) << endl;					
		int b = 10;
		for (int i = 0; i <= b; i++) {
			cout << i << endl;
		}


		Eigen::MatrixXd inputs(3, 4);
		inputs << 1, 2, 3, 2.5,
			2.0, 5.0, -1.0, 2.0,
			-1.5, 2.7, 3.3, -0.8;
		Layer_Dense layer1(4, 5);
		Layer_Dense layer2(5, 2);
		Activation_ReLu activation;

		cout << layer2.forward(activation.forward(layer1.forward(inputs))) << "\n\n\n";


	}



}



