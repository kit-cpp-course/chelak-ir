#pragma once
#include "DataProvider.h"
#include <random>

namespace data {
	
	class RandomDataProvider : public DataProvider {
	public:
		size_t numberOfPoints;	//���������� ����� � ������� ������
		size_t dimensions;		//����������� �����
		double limits;			//����������� �� ������� ������� ��� �������� ����� � dimensions-������ ����, ������ �� ��������� ������� ����� ������ � ������� �� 0 �� limits.

		RandomDataProvider(size_t numberOfPoints = 60, size_t dimensions = 2, double limits = 30) : numberOfPoints(numberOfPoints), dimensions(dimensions), limits(limits) {}

		//��������� ������ ���������� �������.
		double** generate(size_t numberOfPoints, size_t dimensions) {
			double** setOfPoints;
			setOfPoints = new double *[dimensions];
			for (size_t i = 0; i < dimensions; i++) {
				setOfPoints[i] = new double [numberOfPoints];
			}

			std::uniform_real_distribution<double> unif(3, 10);
			std::default_random_engine re;
			size_t numberOfClusters = unif(re);	//��������� ���������� ��������� (�� 3 �� 10)

			for (int t = 0; t < numberOfClusters; t++) {

				std::uniform_real_distribution<double> unif(0, limits*.9);
				std::default_random_engine re;
				size_t lowerBound = unif(re);

				std::uniform_real_distribution<double> unif(lowerBound, limits);
				std::default_random_engine re;
				size_t upperBound = unif(re);

				for (size_t i = 0; i < dimensions; i++) {
					for (size_t j = 0; j < numberOfPoints/numberOfClusters; j++) {
						std::uniform_real_distribution<double> unif(lowerBound, upperBound);
						std::default_random_engine re;
						setOfPoints[i][j] = unif(re);
					}
				}
			}
			return setOfPoints;
		}
	};
}