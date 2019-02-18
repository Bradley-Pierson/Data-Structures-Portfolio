#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <sys/stat.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(int args, char * argv[]){
	if(args > 1){  //checks for file
		for(int i = 1; i < args; i++){
			int fd = open(argv[i], O_RDONLY);  //opens file
			if(fd < 0){  //check open
				cout << "open" << endl;;
				exit(EXIT_FAILURE);
			}
			struct stat buf;  //buffer
			fstat(fd, &buf);  //stat into buffer
			cout << "size (bytes): " << buf.st_size << endl;  //prints size
		}
	}
	else{  //read from standard input
		char buf[4096]; //buffer
		int r;
		int fd = open("input.txt", O_RDWR | O_CREAT, 0777);  //opens and creates input.txt
		while(r = read(STDIN_FILENO, buf, 4096)){  //reads from standard input
			write(fd, buf, r);  //writes to file
		}
		struct stat buf2;  //create buffer
		fstat(fd, &buf2);  //fstat into buffer
		cout << "size (bytes): " << buf2.st_size << endl;  //prints size
		close(fd);  //closes file destination
		remove("input.txt");  //deletes input.txt
		 
	}
	return EXIT_SUCCESS;
}
