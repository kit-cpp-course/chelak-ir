#pragma once
#include "DataProvider.h"

//������������ ����, � ������� ���������� ��� ������� �������������.
namespace cluster {
	//ClusterData - ��������� ��� �������� �������������
	class ClusterData {
	public:
		virtual void clusterize(data::DataProvider & provider) const = 0;
	};
}