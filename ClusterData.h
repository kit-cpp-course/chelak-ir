#pragma once
#include "DataProvider.h"

//The namespace in which clustering process is done.
namespace cluster {
	//ClusterData is an interface in which clustering is performed.
	class ClusterData {
	public:
		//Clustering Data which is provided from DataProvider.
		virtual void clusterize(data::DataProvider & providerOfData/*, cluster::ProvideK & providerOfK*/, cluster::InitiateK & initiateK, median::EvaluateMedian & median, ArgStore & argStore, double eps) const = 0;
	};
}