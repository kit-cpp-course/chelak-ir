#pragma once
#include "DataProvider.h"
#include <armadillo>
#include <string>

typedef __nullterminated const char *LPCSTR;

namespace data {
	/*
	 The class which is necessary for getting data from a file which stores then as a matrix.
	*/
	class FileDataProvider : public DataProvider {

	public:
		/*
		 Gets a matrix from the file.
		 If there is no matrix in a file - quit.
		*/
		arma::mat getMat(LPCSTR input) {
			arma::mat A;
			try {
				A.load(input);
			}
			catch (std::exception e) {
				cout << "There was an error. Please check if your file content looks like a matrix." << endl;
				system("pause");
				exit(1);
			}
			return A;
		}
	};
}