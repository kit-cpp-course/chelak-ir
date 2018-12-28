#pragma once
#include "ProvideK.h"
#include "ArgStore.h"

namespace cluster {
	/*
	 Get the k from the command line.
	*/
	class GetOptimalK : public ProvideK {

		ArgStore argStore = ArgStore::instance();

	public:
		size_t getK(const data::DataProvider & provider) const {
			return argStore.K();
		}
	};
}