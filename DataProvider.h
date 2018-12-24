#pragma once

namespace data {
	//Интерфейс, отвечающий за снабжению программы данными, которые нужно кластеризовать.
	class DataProvider {
		//Абстрактный метод, который генерирует массив точек длины numberOfPoints, где каждая точка имеет dimensions координат.
		virtual double** generate(size_t numberOfPoints, size_t dimensions) = 0;
	};
}