#include <cstdlib>
#include <stdio.h>
#include <fcntl.h>
#include <cerrno>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main(){
  char * arg[12];
  string cmd;
  getline(cin, cmd);
  stringstream ss(cmd);
  string temp {""};
  int i {0};
  while (ss >> temp){
    const  char * temp2 = temp.c_str();
    arg[i] = (char*) temp2;
    cout << arg[i] << endl;
    //cout << "temp: " << temp << endl;
    //cout << "arg[" << i << "] = " << arg[i] << endl;
    i++;
    delete temp2;
  }
  arg[i] = NULL;
  pid_t pid {fork()};
  if (pid == 0){
    execvp(arg[0], arg);
  }
  else if (pid != 0){
    wait(0);
    exit(EXIT_SUCCESS);
  }
}
