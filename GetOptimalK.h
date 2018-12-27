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
		size_t getK(data::DataProvider & provider) {
			return argStore.K();
		}
	};
}