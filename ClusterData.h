#pragma once
#include "InitiateK.h"
#include "EvaluateMedian.h"
#include "DataProvider.h"

typedef __nullterminated const char *LPCSTR;

//The namespace in which clustering process is done.
namespace cluster {
	//ClusterData is an interface in which clustering is performed.
	class ClusterData {
	public:
		//Clustering Data which is provided from DataProvider.
		virtual void clusterize(data::DataProvider & providerOfData, cluster::InitiateK & initiateK, median::EvaluateMedian & median, LPCSTR input, LPCSTR output, size_t K, double eps) const = 0;
	};
}