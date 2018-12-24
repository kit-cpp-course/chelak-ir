#pragma once
#include "DataProvider.h"

//Пространство имен, в котором происходит сам процесс кластеризации.
namespace cluster {
	//ClusterData - интерфейс для процесса кластеризации
	class ClusterData {
	public:
		virtual void clusterize(data::DataProvider & provider) const = 0;
	};
}