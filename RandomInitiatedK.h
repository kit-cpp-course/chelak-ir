#pragma once
#include "InitiateK.h"
#include "ArgStore.h"
#include <armadillo>
//I don't know why, but visual studio wants to put it's own defined min
//instead of min and max from arma so i must to do something like this.
#define min arma::min
#define max arma::max
using namespace arma;

namespace cluster {
	/*
	 Initiating K points using normal random distribution.
	*/
	class RandomInitiatedK : public InitiateK {
	public:
		arma::mat initiate(cluster::ProvideK & providerOfK, data::DataProvider & providerOfData) const {}
	};
}