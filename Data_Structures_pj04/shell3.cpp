#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

using namespace std;

int main(){
	string command;
	getline(cin, command);
	int lengthCommand = command.length();
	string parse1, parse2, parse3, parse4, parse5, parse6, parse7, parse8, parse9, parse10;
	bool bool1 = true;
	bool bool2 = true;
	bool bool3 = true;
	bool bool4 = true;
	bool bool5 = true;
	bool bool6 = true;
	bool bool7 = true;
	bool bool8 = true;
	bool bool9 = true;
	bool bool10 = true;
	int count = 0;
	int beg = 0;
	char c;
	for(int i = 0; i < lengthCommand; i++){
		c = command.at(i);
		if((isspace(c) || i == lengthCommand - 1) && bool1 == true){
			count++;
			parse1 = command.substr(beg,i);
			beg = i+1;
			bool1 = false;
			continue;
		}
		if((isspace(c) || i == lengthCommand - 1) && bool2 == true){
			count++;
			parse2 = command.substr(beg,i);
			beg = i+1;
			bool2 = false;
			continue;
		}
		if((isspace(c) || i == lengthCommand - 1) && bool3 == true){
			count++;
			parse3 = command.substr(beg,i);
			beg = i+1;
			bool3 = false;
			continue;
		}
	}
	char * arg[count];
	
	arg[0] = (char*)parse1.c_str();
	cout << "arg: " << arg[0] << endl;
	arg[1] = (char*)parse2.c_str();
	cout << "arg1: " << arg[1] << endl;
	arg[2] = (char*)parse3.c_str();
	arg[count] = NULL;
	execvp(arg[0],arg);

}

