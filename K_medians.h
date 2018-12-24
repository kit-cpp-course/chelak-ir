#pragma once
#include "ClusterData.h"
#include "InitiateK.h"
#include "EvaluateMedian.h"

namespace cluster {
	//�������� K-medians ��� ������������� ������ ������
	//�������� ����� ������, �������������� K �����, �������� ���������� ��������.
	class K_medians : public ClusterData, public InitiateK, public EvaluateMedian {

	};
}