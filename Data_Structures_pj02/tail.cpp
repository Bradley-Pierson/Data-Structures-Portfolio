#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
using namespace std;

int main(int args, char * argv[]){
	int n;
	char buf[4096];
	string arg2;
	if(args > 2){
		arg2 = argv[2];
	}
	string lines;
	int numLines;
	int count = 0;
	int characterCount = 0;
	int position = 0;
	bool check = true;
	bool file = true;
	if(args == 2){
		numLines = 10;
		file = false;
	}
	if(args == 3){
		string argu3 = argv[2];
		cout << "argu3 length: " << argu3.length() << endl;
		cout << "compare: " << argu3.compare("-") << endl;
		if(argu3.length() < 3 && argu3.compare("-") != 0){
			numLines = stoi(argu3);
			file = false;
		}
		else if(argu3.length() > 3 && argu3.compare("-") != 0){
			numLines = 10;
			file = true;
		}
		else{
			numLines = 10;
			file = false;
		}
	}
	if(args == 4){
		string argu4 = argv[3];
		if(argu4.compare("-") == 0){
			file = false;
			string argu3 = argv[2];
			numLines = stoi(argu3);
		}
		else{
			file = true;
			string argu3 = argv[2];
			numLines = stoi(argu3);
		}
	}
	cout << "args: " << args << endl;
	cout << "file: " << file << endl;
	
	if(args == 4 && file == true){
		int lineLength;
		int filedes = open(argv[3], O_RDONLY);
		n = read(filedes,buf,4096);
		int startPosition = 0;
		int endPosition = n;
		int numWritten;
		int totalLineLength = 0;
		
		while(count < numLines){
			string arg4 = argv[3];
			if(arg4.length() > 3){
				int newLinePosition1 = -1;
				int newLinePosition2 = -1;
			//	cout << "end position: " << endPosition << endl;
				
				for(int i = endPosition; i > 0 && newLinePosition1 < 0; i--){
					if(buf[i] == '\n'){
						newLinePosition1 = i;
					}
				}	
			//	cout << "new line positon 1: " << newLinePosition1 << endl;
				for(int i = newLinePosition1 - 1; i > 0 && newLinePosition2 < 0; i--){
					if(buf[i] == '\n'){
						newLinePosition2 = i;
					}
				}
				lineLength = newLinePosition1 - newLinePosition2;
				totalLineLength += lineLength;
				newLinePosition1 += 1;
				endPosition = endPosition - lineLength;
				count++;
			}
		}
		position = lseek(filedes, -totalLineLength, SEEK_END);
		n = read(filedes, buf, 4096);
		numWritten = write(STDOUT_FILENO, buf, totalLineLength);
			
		close(filedes);
	}
	if(args == 3 && file == true){
		cout << "check true" << endl;
		int filedes = open(argv[2], O_RDONLY);
		int lineLength;
		n = read(filedes, buf, 4096);
		int endPosition = n;
		int numWritten;
		int totalLineLength = 0;
		cout << "num lines: " << numLines << endl;	
		while(count < numLines){
			int newLinePosition1 = -1;
			int newLinePosition2 = -1;
			
			for(int i = endPosition; i > 0 && newLinePosition1 < 0; i--){
				if(buf[i] == '\n'){
					newLinePosition1 = i;
				}
			}
			for(int i = newLinePosition1 - 1; i > 0 && newLinePosition2 < 0; i--){
				if(buf[i] == '\n'){
					newLinePosition2 = i;
				}
			}
			lineLength = newLinePosition1 - newLinePosition2;
			totalLineLength += lineLength;
			newLinePosition1 += 1;
			endPosition = endPosition - lineLength;
			count++;
		}
		position = lseek(filedes, -totalLineLength, SEEK_END);
		n = read(filedes, buf, 4096);
		numWritten = write(STDOUT_FILENO, buf, totalLineLength);
		close(filedes);
	}

	if(args == 3 && file == false){
		cout << "check false" << endl;
		string input;
		string output;
		int countLines = 0;
		while(input != "end"){
			cin >> input;
			output += input + '\n';
		}
		string outputFin;
		int newLinePosition = -1;
		int index;
		for(int i = output.length(); i > 1 && newLinePosition < 0; i--){
			if(output.at(i-1) == '\n'){
				countLines++;
			}
			if(countLines == numLines+2){
				newLinePosition = i;
				index = i;
			}
		}
		if(newLinePosition < 0){
			newLinePosition++;
		}
		int leng = output.length();
		outputFin = output.substr(newLinePosition, leng - index - 3);
		cout << outputFin;
		
	}

	if(args == 4 && file == false){
		string input;
		string output;
		int countLines = 0;
		while(input != "end"){
			cin >> input;
			output += input + '\n';
		}
		string outputFin;
		int newLinePosition = -1;
		int index;
		for(int i = output.length(); i > 1 && newLinePosition < 0; i--){
			if(output.at(i-1) == '\n'){
				countLines++;
			}
			if(countLines == numLines+2){
				newLinePosition = i;
				index = i;
			}
		}
		if(newLinePosition < 0){
			newLinePosition++;
		}
		int leng = output.length();
		outputFin = output.substr(newLinePosition, leng - index - 3);
		cout << outputFin;
		
	}
	
	if(args == 2){
		cout << "check" << endl;
		string input;
		string output;
		int countLines = 0;
		while(input != "end"){
			cin >> input;
			output += input + '\n';
		}
		string outputFin;
		int newLinePosition = -1;
		int index;
		for(int i = output.length(); i > 1 && newLinePosition < 0; i--){
			if(output.at(i-1) == '\n'){
				countLines++;
			}
			if(countLines == numLines+2){
				newLinePosition = i;
				index = i;
			}
		}
		if(newLinePosition < 0){
			newLinePosition++;
		}
		int leng = output.length();
		outputFin = output.substr(newLinePosition, leng - index - 3);
		cout << outputFin;
		
	}

/*	
	if(args == 4 && file == false){
		int filedes = open("input.txt", O_RDWR);
		int lineLength;
		int totalLineLength = 0;
		int newLinePosition1;
		int newLinePosition2;
		int m = read(STDIN_FILENO, buf, 4096);
		write(filedes, buf, 4096);
		int endPosition = m;
		int numWritten;
		
		while(count < numLines){
			newLinePosition1 = -1;
			newLinePosition2 = -1;
			for(int i = endPosition; i > 0 && newLinePosition1 < 0; i--){
				if(buf[i] == '\n'){
					newLinePosition1 = i;
				}
			}
			for(int i = newLinePosition1-1; i > 0 && newLinePosition2 < 0; i--){
				if(buf[i] == '\n'){
					newLinePosition2 = i;
				}
			}
			lineLength = newLinePosition1 - newLinePosition2;
			totalLineLength += lineLength;
			newLinePosition1 += 1;
			position = lseek(STDIN_FILENO, -totalLineLength, SEEK_END);
			m = read(STDIN_FILENO, buf, 4096);
			numWritten = write(STDOUT_FILENO, buf, lineLength);
			position = lseek(STDIN_FILENO, 0, SEEK_SET);
			m = read (STDIN_FILENO, buf, 4096);
			count++;
		}
		
	}
*/	

	exit(0);
}
