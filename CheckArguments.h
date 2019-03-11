#pragma once
#include "ArgStore.h"
#include <fstream>
#include <iostream>
#include <exception>
#include <regex>

namespace cmdLine {
	/*
	* A class which is necessary for checking correctness of an arguments from the command line.
	*/
	class arguments {
		size_t count; //number of the arguments.
		char ** args; //arguments of the command line.
	private:
		/*
		* Transforms first argument (path to the origin dataset) into LPCSTR.
		* If the path was incorrect - close programm.
		*/
		inline LPCSTR checkInput() const {
			string in = args[1];
			ifstream f(args[1]);
			if (!f.good() || !regex_match(in.begin(), in.end(), regex{ R"([^\s]+(txt)$)" }))
			{
				cout << endl << "Your path was incorrect." << endl;
				system("pause");
				exit(0);
			}
			LPCSTR input(args[1]);
			return input;
		}
		/*
		* Transforms second argument (the path where the clustered dataset will be saved) into LPCSTR.
		* If the path was incorrect returns default value.
		*/
		inline LPCSTR checkOutput() const {
			string out = args[2];
			if (!regex_match(out.begin(), out.end(), regex{ R"([^\s]+(txt)$)" }))
			{
				cout << endl << "Your path was incorrect. New output path: output.txt" << endl;
				system("pause");
				LPCSTR output = "output.txt";
				return output;
			}
			LPCSTR output(args[2]);
			return output;
		}
		/*
		* Transforms third argument (which is a value of K) into size_t.
		* If data was incorrect returns default value.
		*/
		inline size_t checkK() const {
			string in = args[3];
			size_t K = strtol(args[3], 0, 0);
			if (K < 0) {
				return 3;
			}
			return K;
		}

	public:
		/*
		* Main constructor of the class.
		*/
		arguments(size_t count, char * arguments[]) : count(count), args(arguments) {};
		/*
		* Setting up new command line argument values.
		*/
		void ArgControl(ArgStore & argStore1) const {
			if (count > 3) {
				argStore1.inputDataset = checkInput();
				argStore1.outputDataset = checkOutput();
				argStore1.myK = checkK();
			}
			else {
				cout << "Error." << endl;
				exit(0);
			}
		}
	};
}