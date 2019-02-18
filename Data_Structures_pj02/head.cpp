#include <iostream>
#include <sstream>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(int args, char * argv[]){
	int count = 0;  //variable to count number of '\n' characters hit
	char buf[4096];  //sets buffer of length 4096
	int numRead = 0;  //number of bytes read
	int newLinePosition = -1;  //position of last '\n' character reached before printing
	int numLines;
	if(args == 2){
		numLines = 10;
	}
	if(args > 2){
		string argu = argv[2];
		if(argu.compare("-") == 0 || argu.length() > 2){
			numLines = 10;
		}
		else{
			numLines = stoi(argu);
		}
	}
	
	
	cout << "args: " << args <<  endl;
	cout << "numLines: " << numLines << endl;
	if(args > 2){
		for(int i = 2; i < args; i++){
			string argu = argv[i];
			if(argu.length() < 2){
				if(argu.compare("-") == 0){
					string input;
					string output;
					while(input != "end"){
						cin >> input;
						output += input + '\n';
					}
					string outputFin;
					int lineCount = 0;
					int index = -1;
					for(int i = 0; i < output.length() && index < 0; i++){
						if(output.at(i) == '\n'){
							lineCount++;
						}
						if(lineCount == numLines){
							index = i;
						}
					}
					if(index < 0){
						index = output.length() - 3;
					}
					outputFin = output.substr(0, index+1);
					cout << outputFin;
				}
			}
			else if(argu.length() > 2){
				int filedes = open(argv[i], O_RDONLY);
				numRead = read(filedes, buf, 4096);
				for(int j = 0; j < numRead && count < numLines; j++){
					if(buf[j] == '\n'){	
						newLinePosition = j;
						count += 1;
					}
				}
				write(STDOUT_FILENO, buf, newLinePosition);
				cout << endl;
				close(filedes);	
			}
/*
			else if{
				string input;
				string output;
				while(input != "end"){
					cin >> input;
					output += input + '\n';
				}
				string outputFin;
				int lineCount = 0;
				int index = -1;
				for(int i = 0; i < output.length() && index < 0; i++){
					if(output.at(i) == '\n'){
						lineCount++;
					}
					if(lineCount == numLines){
						index = i;
					}
				}
				if(index < 0){
					index = output.length() - 3;
				}
				outputFin = output.substr(0, index+1);
				cout << outputFin;
			}
*/
		}
	}
	if(args == 2){
		string input;
		string output;
		while(input != "end"){
			cin >> input;
			output += input + '\n';
		}
		string outputFin;
		int lineCount = 0;
		int index = -1;
		for(int i = 0; i < output.length() && index < 0; i++){
			if(output.at(i) == '\n'){
				lineCount++;
			}
			if(lineCount == numLines){
				index = i;
			}
		}
		if(index < 0){
			index = output.length() - 3;
		}
		outputFin = output.substr(0, index+1);
		cout << outputFin;
	}
	
	/*
	if(arg1.compare("-n") == 0 && args > 3 && strlen(argv[2]) < 3){
		string lines = argv[2];
		int numLines = stoi(lines);	
		for(int i = 3; i < args; i++){ //for number of arguments
			int filedes = open(argv[i], O_RDONLY);  //opens file
			numRead = read(filedes, buf, 4096);  //reads entire file

			for(int j = 0; j < numRead && count < numLines; j++){ //until entire file is read or until we hit amount of lines we need to print
				if(buf[j] == '\n'){  //if buffer at index j equals '\m'
					newlinePosition = j;  //newlinePosition = that index
					count += 1;  //count increases because '\n' characer hit
				}
			}
		
				
			if(numRead < 0){ //if read does not return number greater than 0
				cout << "read error" << endl;  //prints error
			}
		
			write(STDOUT_FILENO, buf, newlinePosition); //writes to console until newlinePosition is reached
		
			close(filedes);  //closes file
			
			cout << endl;
		}
	}

	cout << "check 2" << endl;	
	if(arg1.compare("-n") == 0 && args > 2 && strlen(argv[2]) > 2){
		for(int i = 2; i < args; i++){
			int filedes = open(argv[i], O_RDONLY);
			numRead = read(filedes, buf, 4096);

			for(int j = 0; j < numRead && count < 10; j++){
				if(buf[j] == '\n'){
					newlinePosition = j;
					count +=1;
				}
			}
			
			if(numRead < 0){
				cout << "read error" << endl;
			}
			
			write(STDOUT_FILENO, buf, newlinePosition);
			
			close(filedes);

			cout << endl;
		}
	}

	if(args < 4){
		if(args < 3){
			string input;
			string output = "";
			while(count < 10){
				cin >> input;
				output += input + '\n';
				count++;
			}
			cout << output;
		}
		else{
			string input;
			string output = "";
			string lines = argv[2];
			int numLines = stoi(lines);
			while(count < numLines){
				cin >> input;
				output += input + '\n';
				count++;
			}
			cout << output;
		}
	}
	*/

	exit(0);
}
