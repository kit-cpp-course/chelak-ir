#pragma once
#include "EvaluateMedian.h"

namespace median {
	/*
	 Weiszfeld algorithm for finding the median.
	*/
	class Weiszfeld : public EvaluateMedian {
	public:
		arma::rowvec getMedian(arma::mat setOfPoints, size_t iterations) {}
	};
}