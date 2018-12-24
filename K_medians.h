#pragma once
#include "ClusterData.h"
#include "InitiateK.h"
#include "EvaluateMedian.h"

namespace cluster {
	//Алгоритм K-medians для кластеризации набора данных
	//Получает набор данных, инициированные K точек, алгоритм вычисления мединаны.
	class K_medians : public ClusterData, public InitiateK, public EvaluateMedian {

	};
}