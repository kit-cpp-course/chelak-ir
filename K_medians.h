#pragma once
#include "ClusterData.h"

typedef __nullterminated const char *LPCSTR;

namespace cluster {
	/*
	 K-Medians algorithm
	 Gets dataset, k initialized points and an algorithm for evaluating median.
	*/
	class K_medians : public ClusterData {
	public:
		void clusterize(data::DataProvider & providerOfData, cluster::ProvideK & providerOfK, cluster::InitiateK & initiateK, median::EvaluateMedian & median, LPCSTR input, LPCSTR output, size_t K, double eps) const;
	};
}