#pragma once
#include "ProvideK.h"

namespace cluster {
	//��������� ������������� K �����, ������� ����� �������� ���������.
	//��� �� ������������� ��� ����������� �������� K
	class InitiateK {
	public:
		virtual double* initiate(cluster::ProvideK & provider) = 0;
	};
}