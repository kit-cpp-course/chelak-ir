#include "K_medians.h"
#include <fstream>
#include <iostream>
#include <string>

typedef __nullterminated const char *LPCSTR;

using namespace arma;

/*
 Manhattan distance between two points.
*/
double manhDistance(arma::rowvec point1, arma::rowvec point2);

/*
 Saving clustered set in a text file.
*/
void saveSet(LPCSTR output, mat* disjointSet, mat setOfK);

/*
 Clustering with K-medians.
*/
void cluster::K_medians::clusterize(data::DataProvider & providerOfData, cluster::InitiateK & initiateK, median::EvaluateMedian & median, LPCSTR input, LPCSTR output, size_t K, double eps) const {
	double Q = datum::inf;	//infinity
	mat points = providerOfData.getMat(input);
	mat setOfK = initiateK.initiate(K, points);
	mat* disjointSet = new mat[setOfK.n_elem];
	double oldQ = 0;
	int h = 0;
	//K-medians algorithm
	do {
		for (size_t i = 0; i < points.n_rows; i++) {
			double minimum = datum::inf;
			size_t index = 0;
			for (size_t j = 0; j < setOfK.n_rows; j++) {
				double dist = manhDistance(points.row(i), setOfK.row(j));
				if (dist < minimum) {
					minimum = dist;
					index = j;
				}
			}
			disjointSet[index].insert_rows(0, points.row(index));
		}
		for (size_t i = 0; i < setOfK.n_rows; i++) {
			setOfK.row(i) = median.getMedian(points, 200);
		}
		double sum = 0;
		for (size_t j = 0; j < setOfK.n_elem; j++) {
			for (size_t i = 0; i < disjointSet[j].n_rows; i++) {
				sum += manhDistance(disjointSet[j].row(i), setOfK.row(j));
			}
		}
		double oldQ = Q;
		Q = sum;
	} while (oldQ - Q > eps);
	//saving clustered set
	saveSet(output, disjointSet, setOfK);
}

#define maximum(a,b) ((a) > (b) ? (a) : (b))

double manhDistance(arma::rowvec point1, arma::rowvec point2) {
	double sum = 0;
	try {
		for (size_t i = 0; i < maximum(point1.n_elem, point2.n_elem); i++) {
			sum += abs(point1(i) - point2(i));
		}
	}
	catch (std::exception e) {
		std::cout << "Error. Probably points were in different dimensions.";
		system("pause");
		exit(1);
	}
	return sum;
}

void saveSet(LPCSTR output, mat* disjointSet, mat setOfK) {
	std::ofstream outputFile(output, ios::app);
	for (size_t i = 0; i < setOfK.n_rows; i++) {
		rowvec subK = setOfK.row(i);
		subK.save("temp.txt", arma_ascii);
		std::ifstream tempFile("temp.txt");
		outputFile << i << " cluster" << endl << "Center of this cluster:" << endl;
		char vect[1000];
		tempFile.getline(vect, 1000);
		outputFile << vect << endl;
		disjointSet[i].save("temp.txt", arma_ascii);
		outputFile << i << "Points from cluster" << endl;
		while (tempFile.good()) {
			tempFile.getline(vect, 1000);
			outputFile << vect << endl;
		}
		tempFile.close();
	}
	outputFile.close();
	delete(disjointSet);
	return;
}