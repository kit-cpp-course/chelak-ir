#include "RandomInitiatedK.h"

//I don't know why, but visual studio wants to put it's own defined min
//instead of min and max from arma so i must to do something like this.
#undef min
#undef max

typedef __nullterminated const char *LPCSTR;

arma::mat cluster::RandomInitiatedK::initiate(size_t currentK, arma::mat setOfPoints) const {
	mat setOfK(currentK, setOfPoints.n_cols);
	rowvec lowerBound = min(setOfPoints, 0);	//Getting lower bounds for our random algorithm from dataset.
	rowvec upperBound = max(setOfPoints, 0);	//Getting upper bounds for our random algorithm from dataset.
	for (size_t i = 0; i < currentK; i++) {
		for (size_t j = 0; j < setOfK.n_cols; j++) {
			std::uniform_real_distribution<double> unif(lowerBound(i), upperBound(i));
			std::default_random_engine re;
			setOfK(i, j) = unif(re);
		}
	}
	return setOfK;
}