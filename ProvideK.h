#pragma once
#include "DataProvider.h"

namespace cluster {
	//Интерфейс, снабжающий нас оптимальным значением K исходя из структуры набора данных.
	class ProvideK {
	public:
		virtual size_t getK(data::DataProvider & provider) = 0;
	};
}