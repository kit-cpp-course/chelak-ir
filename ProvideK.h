#pragma once
#include "DataProvider.h"

namespace cluster {
	/*
	 An interface which is necessary for providing us with an optimal value of K depending on the structure of a dataset.
	*/
	class ProvideK {
	public:
		virtual size_t getK(const data::DataProvider & provider, size_t currentK) const = 0;
	};
}