#pragma once
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

class numC
{
public:
	template<typename vec> bool checkMatrixSizeForMultipication(vector<vec>&, vector<vec>&);
	template<typename vec> bool checkMatrixSizeForMultipication(vector<vec>&, vector<vector<vec>>&);
	template<typename vec> bool checkMatrixSizeForMultipication(vector<vector<vec>>&, vector<vec>&);
	template<typename vec> bool checkMatrixSizeForMultipication(vector<vector<vec>>&, vector<vector<vec>>&);
	template<typename vec> bool checkMatrixSizeForMultipication(vector<vector<vector<vec>>>&, vector<vec>&);
	template<typename vec> vector<vec> dot(vector<vec>&, vector<vec>&);
	template<typename vec> vector<vec> dot(vector<vector<vec>>&, vector<vec>&);
	template<typename vec> vector<vec> dot(vector<vector<vec>>&, vector<vector<vec>>&);
	template<typename vec> vector<vec> dot(vector<vector<vector<vec>>>&, vector<vec>&);
	template<typename vec> vector<vec> dot(vector<vec>&, vector<vector<vec>>&);
	template<typename vec> vector<vec> dot(vector<vec>&, vector<vector<vector<vec>>>&);
	template<typename vec> vector<vec> addVec(vector<vec>, vector<vec>);
};







template<typename vec> bool numC::checkMatrixSizeForMultipication(vector<vec>& vec1, vector<vec>& vec2) {
	if (vec1.size() == vec2.size())
		return true;
	else {
		cout << "Error: the vertexes need to be the same size" << endl;
		return false;
	}
}

template<typename vec> bool numC::checkMatrixSizeForMultipication(vector<vector<vec>>& vec1, vector<vec>& vec2) {
	int x = vec1[0].size();
	for(int i = 1; i < vec1.size(); i++){
		if(vec1[i].size() != x){
			cout << "false" << endl;
			return false;
		} 
	}
	if (x == vec2.size()){
		return true;
	}
	else {
		cout << "false" << endl;
		return false;
	}
}


template<typename vec> bool numC::checkMatrixSizeForMultipication(vector<vec>& vec2, vector<vector<vec>>& vec1) {
	int x = vec1[0].size();
	for (int i = 1; i < vec1.size(); i++) {
		if (vec1[i].size() != x) {
			cout << "false" << endl;
			return false;
		}
	}
	if (x == vec2.size()) {
		return true;
	}
	else {
		cout << "false" << endl;
		return false;
	}
}


/*
* checks and sees if multiplying these two matrices is possible or not
* @param 2D vector, 2D vector 
* @return boolean value.
*/
template<typename vec> bool numC::checkMatrixSizeForMultipication(vector<vector<vec>>& vec1, vector<vector<vec>>& vec2) {
	// check to see if the first vector is rectangular
	int x = vec1[0].size();
	for (int i = 1; i < vec1.size(); i++) {
		if (vec1[i].size() != x) {
			cout << "false" << endl;
			return false;
		}
	}
	// check to see if the second vector is rectangular 
		int y = vec2[0].size();
	for (int i = 1; i < vec1.size(); i++) {
		if (vec2[i].size() != x) {
			cout << "false" << endl;
			return false;
		}
	}

	if (vec1.size() == vec2.size()){ return true;} //If both of the matrices are the same rectangle size then return true
	else if (vec1[0].size() == vec1.size()) { return true; } //If matrices are not the same rectangle but they are able to be multiplied
															 //then return true
	else{ //if they are not able to be multiplied return false
		cout << "false" << endl;
		return false;
	}
}




/**
 * In case there is a matrix and vector passed, the dot product will be returned
 * In case two matrices are passed, the function will multiply them
 * The vectors are allowed to be int, float, double, or even char!
 * @param Vector/Matrix, Vector/Matrix
 * @return A vector with the dot product of the two vectors
 */
template<typename vec> vector<vec> numC::dot(vector<vec>& vec1, vector<vec>& vec2) {
	bool check = checkMatrixSizeForMultipication(vec1, vec2);
	if (check == false) {
		throw "bruh";
		abort();
	}	vector<double> x;
	for (int i = 0; i < vec1.size(); i++) {

		x.push_back((vec1[i] * vec2[i]));

	}
	return x;
}

template<typename vec> vector<vec> numC::dot(vector<vector<vec>>& vec1, vector<vec>& vec2) {
	bool check = checkMatrixSizeForMultipication(vec1, vec2);
	vector<double> tVec1;
	if (check == false) {
		goto ex;
		abort(); 
	}

	
	for (int i = 0; i < vec1.size(); i++) {
		double tX = 0;
		for (int j = 0; j < vec1[i].size(); j++) {
			tX += ((vec1[i][j] * vec2[j]));

		}
		tVec1.push_back(tX);
	}

	return tVec1;

}

template<typename vec> vector<vec> numC::dot(vector<vec>& vec2, vector<vector<vec>>& vec1) {
	bool check = checkMatrixSizeForMultipication(vec1, vec2);
	if (check == false) {
		throw "bruh";
		abort();
	}
	vector<double> tVec1;
	for (int i = 0; i < vec1.size(); i++) {
		double tX = 0;
		for (int j = 0; j < vec1[i].size(); j++) {
			tX += ((vec1[i][j] * vec2[j]));

		}
		tVec1.push_back(tX);
	}
	return tVec1;

}

template<typename vec> vector<vec> numC::addVec(vector<vec> vec1, vector<vec> vec2) {
	bool check = checkMatrixSizeForMultipication(vec1, vec2);
	if (check == false) {
		abort();
	}
	vector<vec> temp;
	for (int i = 0; i < vec1.size(); i++) {
		temp.push_back(vec1[i] + vec2[i]);
	}
	return temp;
}
template<typename vec> vector<vec> dot(vector<vector<vec>>&, vector<vector<vec>>&) {

}