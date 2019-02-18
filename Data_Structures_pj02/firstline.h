#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFSIZE 1024

/*
 * For the purposes of this assignment students may assume that lines
 * are, at maximum, 1000 characters long.
 */
int main(int argc, char** argv) {
  if(argc != 2) {
    printf("Usage: %s FILE\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int fd = open(argv[1], O_RDONLY);
  if(fd < 0) {
    perror("error opening input file");
    exit(EXIT_FAILURE);
  }

  char buf[BUFFSIZE];
  int numRead = 0;
  int newlinePosition = -1;

  numRead = read(fd, buf, BUFFSIZE);
  
  for(int i = 0; i < numRead && newlinePosition < 0; i++) {
    if(buf[i] == '\n') {
      newlinePosition = i;
      if(i + 1 < numRead) {
	newlinePosition += 1;
      }
    }
  }

  if(newlinePosition < 0) {
    newlinePosition = numRead;
  }

  write(STDOUT_FILENO, buf, newlinePosition);

  if(close(fd) < 0){
    perror("error closing file");
  }
}
