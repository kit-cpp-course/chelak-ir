#pragma once
#include "DataProvider.h"

//The namespace in which clustering process is done.
namespace cluster {
	//ClusterData is an interface in which clustering is performed.
	class ClusterData {
	public:
		//Clustering Data which is provided from DataProvider.
		virtual void clusterize(data::DataProvider & providerOfData, ProvideK & providerOfK, InitiateK & initiateK, median::EvaluateMedian & median, double eps, ArgStore & argStore) const = 0;
	};
}