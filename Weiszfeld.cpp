#include "Weiszfeld.h"
#include <iostream>

using namespace median;

/*
 Manhattan distance between two points.
*/
double manhDistance(arma::rowvec point1, arma::rowvec point2);

/*
 Gets a mean of a set of points.
*/
arma::rowvec mean(arma::mat setOfPoints);

/*
 Checks if the median is already a point and shifts it if so.
*/
arma::rowvec checkMedian(arma::rowvec median, arma::mat setOfPoints);

/*
 Gets median using Weiszfeld's algorithm.
*/
arma::rowvec getMedian(arma::mat setOfPoints, size_t iterations = 200) {
	arma::rowvec median = mean(setOfPoints);
	median = checkMedian(median, setOfPoints);
	arma::rowvec m1;
	double m2 = 0;
	for (size_t i = 0; i < iterations; i++) {
		for (size_t j = 0; j < setOfPoints.n_rows; j++) {
			double dist = manhDistance(median, setOfPoints.row(j));
			if (dist != 0) {
				m1 += setOfPoints.row(j) / dist;
				m2 += 1.0 / dist;
			}
		}
		median = m1 / m2;
	}
	return median;
}

arma::rowvec checkMedian(arma::rowvec median, arma::mat setOfPoints) {
	while (true)
	{
		bool isGood = true;
		for (size_t i = 0; i < setOfPoints.n_rows; i++) {
			if (manhDistance(median, setOfPoints.row(i)) == 0) {
				for (size_t j = 0; j < median.n_elem; j++) {
					median(j) += .1;
				}
				isGood = false;
			}
		}
		if (isGood) break;
	}
	return median;
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

arma::rowvec mean(arma::mat setOfPoints) {
	arma::rowvec a = sum(setOfPoints);					//a vector which contains sums of an elements from each column.
	arma::rowvec meanPoint(setOfPoints.n_cols);
	for (size_t i = 0; i < setOfPoints.n_cols; i++) {
		meanPoint(i) = a(i) / setOfPoints.n_rows;
	}
	return meanPoint;
}