#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

int main(){
  //process id of current process
  pid_t parentPid = getpid();
  //current process parent id
  pid_t parentParentPid = getppid();
  cout << "Process ID: " << parentPid << endl;
  cout << "Parent's process ID: " << parentParentPid << endl;
  //forks and saves returned process id
  pid_t childPid = fork();
  if (childPid == 0){
    //enters if statement only in the child
    //actual process id of the child
    pid_t actualChild = getpid();
    //process id of child's parent (same as parentPid above)
    pid_t childParentPid = getppid();
    cout << "Child's process ID: " << actualChild << endl;
    cout << "Child's Parent's process ID: " << childParentPid << endl;
  }
  exit(EXIT_SUCCESS);
}
