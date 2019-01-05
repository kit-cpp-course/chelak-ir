#pragma once
#include <armadillo>
#include "ProvideK.h"
#include "EvaluateMedian.h"
#include "InitiateK.h"

typedef __nullterminated const char *LPCSTR;

namespace data {
	/*
	 An interface which is necessary for providing a clustering algorithm with the data.
	*/
	class DataProvider {
	public:
		/*
		* An abstract method which is necessary for getting a matrix with points.
		*/
		virtual arma::mat getMat(LPCSTR input) = 0;
	};
}