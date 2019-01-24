#pragma once
#include <string>

using namespace std;

namespace cmdLine {
	class arguments;
}
/*
 Singleton class which is necessary for storing arguments from command line.
 */
class ArgStore {
	friend class cmdLine::arguments;
	static ArgStore myInstance;
	LPCSTR inputDataset;	//The path to the origin dataset.
	LPCSTR outputDataset;	//The path where the clustered dataset will be saved.
	size_t myK;				//K which is required in the k-medians algorithm.

public:
	/*
	 Returns configurations.
	*/
	static ArgStore & instance() {
		return myInstance;
	}
	/*
	 Returns an adress of the origin dataset.
	*/
	const LPCSTR & input() const {
		return inputDataset;
	}
	/*
	 Returns an adress in which clustered dataset will be saved.
	*/
	const LPCSTR & output() const {
		return outputDataset;
	}
	/*
	 Returns a value of K which is necessary in K-Medians
	*/
	const size_t & K() const {
		return myK;
	}
};

ArgStore ArgStore::myInstance = ArgStore();