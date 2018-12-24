#pragma once
#include "DataProvider.h"

namespace cluster {
	//���������, ���������� ��� ����������� ��������� K ������ �� ��������� ������ ������.
	class ProvideK {
	public:
		virtual size_t getK(data::DataProvider & provider) = 0;
	};
}