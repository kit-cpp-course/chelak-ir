#pragma once

namespace cluster {
	//��������� ��� ���������� ������� ����� ������ �����
	class EvaluateMedian {
		virtual double* getMedian(double** setOfPointsInCluster) = 0;
	};
}