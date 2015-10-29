//============================================================================
// Name        : Demo_dir.cpp
// Author      : Zishuo
// Version     :
// Copyright   : This code is under GNU lisence.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <dirent.h>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {
	DIR *dp;
	struct dirent *dirp;
	if (argc < 2) {
		dp = opendir(".");
	} else {
		dp = opendir(argv[1]);
	}

	if (dp == NULL) {
		cerr << "can't open directory : " << argv[1] << endl;
	}

	while ((dirp = readdir(dp)) != NULL)
		cout << dirp->d_name << endl;

	return 0;
}
