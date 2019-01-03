#pragma once
#include "InitiateK.h"
#include "ArgStore.h"
#include <armadillo>

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