#include "RandomInitiatedK.h"

//I don't know why, but visual studio wants to put it's own defined min
//instead of min and max from arma so i must to do something like this.
#define min arma::min
#define max arma::max

arma::mat initiate(cluster::ProvideK & providerOfK, data::DataProvider & providerOfData) {
	size_t K = providerOfK.getK(providerOfData);	//getting K.
	ArgStore argStore = ArgStore::instance();
	mat points = providerOfData.getMat();	//Getting dataset.
	mat setOfK(K, points.n_cols);
	rowvec lowerBound = min(points, 0);	//Getting lower bounds for our random algorithm from dataset.
	rowvec upperBound = max(points, 0);	//Getting upper bounds for our random algorithm from dataset.
	for (size_t i = 0; i < K; i++) {
		for (size_t j = 0; j < setOfK.n_cols; j++) {
			uniform_real_distribution<double> unif(lowerBound(i), upperBound(i));
			default_random_engine re;
			setOfK(i, j) = unif(re);
		}
		return setOfK;
	}
}