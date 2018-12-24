#pragma once

namespace data {
	//���������, ���������� �� ��������� ��������� �������, ������� ����� ��������������.
	class DataProvider {
		//����������� �����, ������� ���������� ������ ����� ����� numberOfPoints, ��� ������ ����� ����� dimensions ���������.
		virtual double** generate(size_t numberOfPoints, size_t dimensions) = 0;
	};
}