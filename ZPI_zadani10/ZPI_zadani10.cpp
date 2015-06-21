// ZPI_zadani10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

using namespace std;

class Compute
{
public:
	Compute() {};
	Compute(const char* filename) :filename(filename),result(0){}
	~Compute(){}
	
	void GiveResult();

private:
	const char* filename;
	uint64_t result;

	void fileread(const char* filename);
	void WriteResult();
};


int _tmain(int argc, _TCHAR* argv[])
{
	Compute *compute = new Compute("Zad10.txt");
	compute->GiveResult();
	delete compute;
	std::cin.get();
	return 0;
}

/*
function fileread is used to read data from file,
evry line from file is save in different string in vector data
for egzample:
fileread("Zad10.txt");
should return nothing, but it result save data from file as a sum of a number
"123
456"
result will be saved as followed sum:
1 + 2 + 3 + 4 + 5 + 6
enter (ascii 10) is ignored
*/
void Compute::fileread(const char* filename)
{
	FILE* file;
	fopen_s(&file, filename, "r");
	if (!file){
		perror("File opening failed");
	}

	char sign; // note: int, not char, required to handle EOF
	string temp = "";

	while ((sign = fgetc(file)) != EOF) { // standard C I/O file reading loop
		if ((sign != 10))
		{
			result += static_cast<uint64_t>(atoi(&sign));
		}
	}

	if (ferror(file))
	{
		cout << endl;
		cout << "I/O error temp_resulthen reading" << endl;
	}
	else if (feof(file))
	{

	}
	fclose(file);
}

/*
function print result on scren inform
WYNIK: result
where result is uint64_t number
*/
void Compute::WriteResult(void)
{
	cout << "WYNIK: ";
	cout << result;
}

/*
function start calculations on file and call function WriteResult()
*/
void Compute::GiveResult(void)
{
	fileread(filename);
	WriteResult();
}
