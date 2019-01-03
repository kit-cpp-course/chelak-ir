#include "K_medians.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace arma;

/*
 Manhattan distance between two points.
*/
double manhDistance(arma::rowvec point1, arma::rowvec point2);

/*
 Clustering with K-medians.
*/
void cluster::K_medians::clusterize(data::DataProvider & providerOfData, cluster::ProvideK & providerOfK, cluster::InitiateK & initiateK, median::EvaluateMedian & median, ArgStore & argStore, double eps) const {
	double Q = datum::inf;	//infinity
	mat points = providerOfData.getMat();
	mat setOfK = initiateK.initiate(providerOfK, providerOfData);
	mat* disjointSet = new mat[setOfK.n_elem];
	double oldQ = 0;
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
			disjointSet[index].insert_rows(1, points.row(index));
		}
		for (size_t j = 0; j < setOfK.n_rows; j++) {
			setOfK.row(j) = median.getMedian(points, 200);
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
	ofstream outputFile(argStore.output(), ios::app);
	for (size_t i = 0; i < setOfK.n_rows; i++) {
		rowvec subK = setOfK.row(i);
		subK.save("temp.txt", arma_ascii);
		ifstream tempFile("temp.txt");
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
	delete(disjointSet);
}

double manhDistance(arma::rowvec point1, arma::rowvec point2) {
	double sum = 0;
	try {
		for (size_t i = 0; i < max(point1.n_elem, point2.n_elem); i++) {
			sum += abs(point1(i) - point2(i));
		}
	}
	catch (std::exception e) {
		std::cout << "Error. Probably points was in different dimensions.";
		system("pause");
		exit(0);
	}
	return sum;
}
