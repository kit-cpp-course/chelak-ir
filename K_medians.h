#pragma once
#include "ClusterData.h"
#include "InitiateK.h"
#include "EvaluateMedian.h"
#include "ArgStore.h"

namespace cluster {
	/*
	 K-Medians algorithm
	 Gets dataset, k initialized points and an algorithm for evaluating median.
	*/
	class K_medians : public ClusterData {
	public:
		void clusterize(data::DataProvider & providerOfData, ProvideK & providerOfK, InitiateK & initiateK, median::EvaluateMedian & median, ArgStore & argStore, double eps) const;
	};
}