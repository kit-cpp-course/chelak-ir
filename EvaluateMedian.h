#pragma once

namespace cluster {
	//Интерфейс для нахождения медианы среди набора точек
	class EvaluateMedian {
		virtual double* getMedian(double** setOfPointsInCluster) = 0;
	};
}