#pragma once
#include "ProvideK.h"

namespace cluster {
	//Интерфейс инициализации K точек, которые будут центрами кластеров.
	//Для их инициализации нам потребуется значение K
	class InitiateK {
	public:
		virtual double* initiate(cluster::ProvideK & provider) = 0;
	};
}