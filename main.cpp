#include "K_medians.h"
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

	return 0;
}