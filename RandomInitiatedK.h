#pragma once
#include "InitiateK.h"
#include <armadillo>

using namespace arma;

namespace cluster {
	/*
	 Initiating K points using normal random distribution.
	*/
	class RandomInitiatedK : public InitiateK {
	public:
		arma::mat initiate(size_t currentK, arma::mat setOfPoints) const;
	};
}