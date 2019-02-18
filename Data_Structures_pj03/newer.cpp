#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

using std::cout;
using std::endl;

int main(int argc, char** argv){
  if (argc != 4){ //program only takes one option and two files
    cout << "Error: Usage: ./newer (-a|-m|-c) FILE1 FILE2" << endl;
    exit(EXIT_FAILURE);
  }
  //opens each file
  int file1 = open(argv[2], O_RDONLY);
  int file2 = open(argv[3], O_RDONLY);
  if ((file1 < 0) | (file2 < 0)){
    perror("open error");
    exit(EXIT_FAILURE);
  }
  //structs store each files fstat return data
  struct stat buf1;
  struct stat buf2;
  fstat(file1, &buf1);
  fstat(file2, &buf2);
  if (argv[1][1] == 'a'){ //access
    if (buf1.st_atime > buf2.st_atime) cout << argv[2] << " was accessed last." << endl;
    else cout << argv[3] << " was accessed last." << endl;
    //cout << argv[2] << buf1.st_atime << endl;
    //cout << argv[3] << buf2.st_atime << endl;
  }
  else if (argv[1][1] == 'm'){ //modify
    if (buf1.st_mtime > buf2.st_mtime) cout << argv[2] << " was modified last." << endl;
    else cout << argv[3] << " was modified last." << endl;
    //cout << argv[2] << buf1.st_mtime << endl;
    //cout << argv[3] << buf2.st_mtime << endl;
  }
  else if (argv[1][1] == 'c'){ //status change
    if (buf1.st_ctime > buf2.st_ctime) cout << argv[2] << " was changed last." << endl;
    else cout << argv[3] << " was changed last." << endl;
    //cout << argv[2] << buf1.st_ctime << endl;
    //cout << argv[3] << buf2.st_ctime << endl;
  }
  exit(EXIT_SUCCESS);
}
