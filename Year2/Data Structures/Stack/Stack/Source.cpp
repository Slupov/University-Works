#include <iostream>
#include <string>
#include "CStack.h"
using namespace std;

int main(const int argc, char** argv)
{
	if (argc < 3)
	{
		cout << "Usage: " << endl;
		cout << argv[0] << " in_file_name out_file_name";
		return -1;
	}

	CStack myStack;
	myStack.trace();

	if (0 > myStack.read_from_file_to_stack(argv[1]))
	{
		cout << "Can't read from file: " << argv[1];
		return -1;
	}
	if (0 > myStack.write_file_from_stack(argv[2]))
	{
		cout << "Can't write to file: " << argv[2];
		return -2;
	}

	return 0;
}
