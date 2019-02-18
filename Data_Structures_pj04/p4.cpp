//includes
#include <string>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sstream>
#include <fcntl.h>

using namespace std;


int main(){
	cout.setf(std::ios::unitbuf);
	char buf[1024];
	char *pwd = getcwd(buf, 1024);
	cout << "1730sh:" << pwd << "/$ ";
	bool running = true;
	
	string parse1, parse2, parse3, parse4, parse5, parse6, parse7, parse8, parse9, parse10, parse11;

	//set up infinite loop
	while(running == true){
		string command;//string to getline command
		getline(cin, command);

		int lengthCommand = command.length(); //length of getline

		//booleans for parse purposes
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
		bool bool11 = true;

		int count = 0; //count number of arguments
		int beg = 0; //index at beginning of argument
		char c; //space

		//command parsing
		for(int i = 0; i < lengthCommand; i++){
			c = command.at(i);
			if((isspace(c) || i == lengthCommand - 1) && bool1 == true){
				count++;
				parse1 = command.substr(beg,i-beg);
				if(i == lengthCommand - 1){
					parse1 = command.substr(beg, i - beg + 1);
				}
				beg = i+1;
				bool1 = false;
				continue;
			}
			if((isspace(c) || i == lengthCommand - 1) && bool2 == true){
				count++;
				parse2 = command.substr(beg,i-beg);
				if(i == lengthCommand - 1){
					parse2 = command.substr(beg, i - beg + 1);
				}
				beg = i+1;
				bool2 = false;
				continue;
			}
			if((isspace(c) || i == lengthCommand - 1) && bool3 == true){
				count++;
				parse3 = command.substr(beg,i-beg);
				if(i == lengthCommand - 1){
					parse3 = command.substr(beg, i - beg + 1);
				}
				beg = i+1;
				bool3 = false;
				continue;
			}
			if((isspace(c) || i == lengthCommand-1) && bool4 == true){
				count++;
				parse4 = command.substr(beg,i-beg);
				if(i == lengthCommand - 1){
					parse4 = command.substr(beg, i - beg + 1);
				}
				beg = i+1;
				bool4 = false;
				continue;
			}
			if((isspace(c) || i == lengthCommand-1) && bool5 == true){
				count++;
				parse5 = command.substr(beg,i-beg);
				if(i == lengthCommand - 1){
					parse5 = command.substr(beg, i - beg + 1);
				}
				beg = i+1;
				bool5 = false;
				continue;
			}
			if((isspace(c) || i == lengthCommand-1) && bool6 == true){
				count++;
				parse6 = command.substr(beg,i-beg);
				if(i == lengthCommand - 1){
					parse6 = command.substr(beg, i - beg + 1);
				}
				beg = i+1;
				bool6 = false;
				continue;
			}
			if((isspace(c) || i == lengthCommand-1) && bool7 == true){
				count++;
				parse7 = command.substr(beg,i-beg);
				if(i == lengthCommand - 1){
					parse7 = command.substr(beg, i - beg + 1);
				}
				beg = i+1;
				bool7 = false;
				continue;
			}
			if((isspace(c) || i == lengthCommand-1) && bool8 == true){
				count++;
				parse8 = command.substr(beg,i-beg);
				if(i == lengthCommand - 1){
					parse8 = command.substr(beg, i - beg + 1);
				}
				beg = i+1;
				bool8 = false;
				continue;
			}
			if((isspace(c) || i == lengthCommand-1) && bool9 == true){
				count++;
				parse9 = command.substr(beg,i-beg);
				if(i == lengthCommand - 1){
					parse9 = command.substr(beg, i - beg + 1);
				}
				beg = i+1;
				bool9 = false;
				continue;
			}
			if((isspace(c) || i == lengthCommand-1) && bool10 == true){
				count++;
				parse10 = command.substr(beg,i-beg);
				if(i == lengthCommand - 1){
					parse10 = command.substr(beg, i - beg + 1);
				}
				beg = i+1;
				bool10 = false;
				continue;
			}
			if((isspace(c) || i == lengthCommand-1) && bool11 == true){
				count++;
				parse11 = command.substr(beg,i-beg);
				if(i == lengthCommand - 1){
					parse11 = command.substr(beg, i - beg + 1);
				}
				beg = i+1;
				bool11 = false;
				continue;
			}
		}
			
			//if exit is entered, breaks loop, program terminates
			if(parse1.compare("exit") == 0  || parse2.compare("exit") == 0  || parse3.compare("exit") == 0  || parse4.compare("exit") == 0  || 
			parse5.compare("exit") == 0  || parse6.compare("exit") == 0  || parse7.compare("exit") == 0  || parse8.compare("exit") == 0  || 
			parse9.compare("exit") == 0 || parse10.compare("exit") == 0 || parse11.compare("exit") == 0){
				break;
			}

		//creates arg array
		char * arg[11];
		arg[0] = (char*)parse1.c_str();
		arg[1] = (char*)parse2.c_str();
		arg[2] = (char*)parse3.c_str();
		arg[3] = (char*)parse4.c_str();
		arg[4] = (char*)parse5.c_str();
		arg[5] = (char*)parse6.c_str();
		arg[6] = (char*)parse7.c_str();
		arg[7] = (char*)parse8.c_str();
		arg[8] = (char*)parse9.c_str();
		arg[9] = (char*)parse10.c_str();
		arg[10] = (char*)parse11.c_str();
		arg[count] = NULL;

		//if export is a command
		bool exp = false;
		if(parse1.compare("export") == 0){
			exp = true;
			const char * name;
			const char * variable;
			char d;
			for(int i = 0; i < parse2.length(); i++){
				d = parse2.at(i);
				if(d == '='){
					name = (const char*)parse2.substr(0,i).c_str();
					variable = (const char*)parse2.substr(i+1).c_str();
				}
			}
			int set = setenv(name, variable, 1);
			if(set < 0){
				perror("set error");
				exit(EXIT_FAILURE);
			}
			cout << "1730sh:" << pwd << "/$ ";
		}
		
		//fork process (does not happen if export)
		pid_t pid;
		if(exp == false){
			pid = fork();
		}
		else{
			pid = -1;
		}
		
		
		if(pid == 0){
			//child
			bool redir = false;
			int where = 0;
			cout << "count: " << count << endl;
			for(int i = 0; i < count; i++){
				cout << "arg[" << i << "] = " << arg[i] << endl;
				if(arg[i][0] == '>' && arg[i][1] != '>'){
				//cout << "ARROW LOCATED" << endl;
					int fd = open(arg[i+1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
					if(fd < 0){
						perror("open error");
						exit(EXIT_FAILURE);
					}
					int d2 = dup2(fd, STDOUT_FILENO);
					if(d2 < 0){
						perror("dup2 error");
						exit(EXIT_FAILURE);
					}
					redir = true;
					where = i;
				}
				if(arg[i][0] == '>' && arg[i][1] == '>'){
					cout << "MULTIPLE ARROWS LOCATED" << endl;
					cout << "file: " << arg[i+1] << endl;
					int fd = open(arg[i+1], O_WRONLY | O_CREAT | O_APPEND, 0777);
					if(fd < 0){
						perror("open error");
						exit(EXIT_FAILURE);
					}
					int d2 = dup2(fd, STDOUT_FILENO);
					if(d2 < 0){
						perror("open error");
						exit(EXIT_FAILURE);
					}
					redir = true;
					where = i;
				}
				if(arg[i][0] == '<'){
					cout << "LEFT ARROW LOCATED" << endl;
					cout << "file: " << arg[i] << endl;
					int fd = open(arg[i+1], O_RDONLY);
					if(fd < 0){
						perror("open error");
						exit(EXIT_FAILURE);
					}
					int d2 = dup2(fd, STDIN_FILENO);
					if(d2 < 0){
						perror("dup2 error");
						exit(EXIT_FAILURE);
					}
					redir = true;
					where = i;
				}
			}
			

			if(redir){
				arg[where] = NULL;
			}
			execvp(arg[0],arg);
		}
		else if(pid > 0){
			//parent
			wait(0);
			if(running == true){
				cout << "1730sh:" << pwd << "/$ ";
			}
		}
	}
}
