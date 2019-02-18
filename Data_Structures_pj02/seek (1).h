#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cerrno>

using std::cout;
using std::endl;

#define BUFFSIZE 4096

int main(int argc, char** argv) {
  
  if(argc != 2) {
    cout << "usage: " << argv[0] << " FILE" << endl;
    exit(EXIT_FAILURE);
  }

  char buf[BUFFSIZE];

  int fd = open(argv[1], O_RDONLY);
  if(fd == -1) {
    perror("open1");
  }

  off_t pos = lseek(fd, 0, SEEK_END);
  if(pos == -1) {
    perror("seek");
  }

  cout << "position: " << pos << endl;

  int bytes_read = read(fd, buf, BUFFSIZE);
  if(bytes_read == -1) {
    perror("read1");
  }
  
  cout << "bytes read: " << bytes_read << endl;

  pos = lseek(fd, -10, SEEK_END);
  if(pos == -1) {
    perror("seek2");
  }

  cout << "new position: " << pos << endl;

  bytes_read = read(fd, buf, BUFFSIZE);
  if(bytes_read == -1) {
    perror("read2");
  }

  cout << "bytes read:" << bytes_read << endl;

  int numwritten = write(1, buf, bytes_read);
  if(numwritten != bytes_read) {
    perror("write");
  }

  if(close(fd) == -1) {
    perror("close");
  }

}
