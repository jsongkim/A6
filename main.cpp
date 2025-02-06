/**********************************************************
* Author: Joseph Song-Kim
* Assignment: A6
* Due Date: 2/9/2025
* Purpose: Demonstrate the use of a struct.
**********************************************************/

#include "playerType.h"

#include <string>
#include <iostream>
#include <iomanip>
// Library needed for file processing.
#include <fstream>

using namespace std;

void readFile(playerType []);

int main(){
	playerType array[10];

	return 0;
}

void readFile(playerType list[]){
	ifstream inData;
	// Open the file.
	inData.open("input.txt");
	int index = 0;

	while (getline(inData, list[index].name) && index < 10){
		inData.getline(list[index].position, 3);
		inData >> list[index].td;
		inData >> list[index].catches;
		inData >> list[index].pyds;
		inData >> list[index].ryds;
		inData >> list[index].rusyds;

		inData.ignore(5, '\n');;
		inData.clear();
		index++;
	}

	inData.close();
	return;
}

