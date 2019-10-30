/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	ifstream myfile;
	myfile.open(filename.c_str(), ios::in);

	if (!myfile.is_open()) {
		return COULD_NOT_OPEN_FILE_TO_READ;
	}

	string line = "";

	while (getline(myfile, line)) {
		getline(myfile, line);
		contents += line;
	}

	if (contents.length() < 1) {
		return COULD_NOT_OPEN_FILE_TO_READ;
	}

	return SUCCESS;

}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream myfile;
	myfile.open(filename);

	if (!myfile.is_open()) {
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}

	for (int i = 0; i < myEntryVector.size(); i++) {
		myfile << myEntryVector[i] << "\n";
	}

	return SUCCESS;

}


