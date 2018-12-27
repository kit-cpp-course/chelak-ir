#pragma once
#include <armadillo>

namespace median {
	/*
	 An interface in which finding the median is performed.
	*/
	class EvaluateMedian {
		/*
		 We are getting a point which is a geometric median of all points from cluster
		 and which is stored in a row.
		*/
	public:
		virtual arma::rowvec getMedian(arma::mat setOfPointsInCluster, size_t iterations) = 0;
	};
}