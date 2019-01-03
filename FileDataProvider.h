#pragma once
#include "DataProvider.h"
#include "ArgStore.h"
#include <armadillo>
#include <string>

namespace data {
	/*
	 The class which is necessary for getting data from a file which stores then as a matrix.
	*/
	class FileDataProvider : public DataProvider {

		//Getting path to our origin dataset.
		ArgStore argStore = ArgStore::instance();
		string name;

	public:
		/*
		 Gets a matrix from the file.
		 If there is no matrix in a file - quit.
		*/
		arma::Mat<double> getMat() {
			arma::mat A;
			try {
				A.load(name);
			}
			catch (exception e) {
				cout << "There was an error. Please check if your file content looks like a matrix." << endl;
				system("pause");
				exit(1);
			}
			return A;
		}
	};
}