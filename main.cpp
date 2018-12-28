#include "K_medians.h"
#include "GetOptimalK.h"
#include "RandomInitiatedK.h"
#include "Weiszfeld.h"
#include "FileDataProvider.h"
#include "CheckArguments.h"

using namespace cmdLine;

//Arguments provided from command line.
//We need 3 arguments: 
//First argument will be a path to an origin file with the set of numbers.
//Second argument will be the path where the clustered dataset will be saved.
//And finally third argument is a number K for k-medians purposes.

int main(size_t count, char ** args) {
	ArgStore argStore = ArgStore::instance();
	arguments argCheck(count, args);
	argCheck.ArgControl(argStore);
	data::FileDataProvider fileDataProvider;
	cluster::GetOptimalK getOptimalK;
	cluster::K_medians kMedians;
	cluster::RandomInitiatedK randomInitiatedK;
	median::Weiszfeld weiszfeld;
	kMedians.clusterize(fileDataProvider, getOptimalK, randomInitiatedK, weiszfeld, argStore, 10);

	return 0;
}