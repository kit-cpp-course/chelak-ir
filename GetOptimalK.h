#pragma once
#include "ProvideK.h"

namespace cluster {
	/*
	 Get the k from the command line.
	*/
	class GetOptimalK : public ProvideK {

	public:
		size_t getK(const data::DataProvider & provider, size_t currentK) const {
			return currentK;
		}
	};
}