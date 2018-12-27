#include "K_medians.h"

using namespace arma;

/*
 Manhattan distance between two points.
*/
double manhDistance(arma::rowvec point1, arma::rowvec point2);

/*
 Clustering with K-medians.
*/
void clusterize(data::DataProvider & providerOfData, cluster::ProvideK & providerOfK, cluster::InitiateK & initiateK, median::EvaluateMedian & median, ArgStore & argStore, double eps = 10) {
	double Q = datum::inf;	//infinity
	mat points = providerOfData.getMat();
	mat setOfK = initiateK.initiate(providerOfK, providerOfData);
	mat* disjointSet = new mat[setOfK.n_elem];
	double oldQ = 0;
	do {
		for (size_t i = 0; i < points.n_rows; i++) {
			double min = datum::inf;
			size_t index = 0;
			for (size_t j = 0; j < setOfK.n_rows; j++) {
				double dist = manhDistance(points.row(i), setOfK.row(j));
				if (dist < min) {
					min = dist;
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
	for (size_t i = 0; i < setOfK.n_rows; i++) {
		rowvec subK = setOfK.row(i);
		subK.save(argStore.output, arma_ascii);
		disjointSet[i].save(argStore.output, arma_ascii);
	}
}

double manhDistance(arma::rowvec point1, arma::rowvec point2) {
	double sum = 0;
	try {
		for (size_t i = 0; i < point1.n_elem; i++) {
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