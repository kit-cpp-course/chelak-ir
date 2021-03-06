#pragma once
//#include "ProvideK.h"
#include <armadillo>

namespace cluster {
	/*
	 An interface which is necessary for initializing K points - cluster centers.
	*/
	class InitiateK {
	public:
		/*
		 initiates K points and then stores them in a matrix.
		*/
	public:
		virtual arma::mat initiate(size_t currentK, arma::mat setOfPoints) const = 0;
	};
}