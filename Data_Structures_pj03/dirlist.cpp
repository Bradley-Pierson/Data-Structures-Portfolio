#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <dirent.h>
using namespace std;

int main(){
	struct dirent * entry = nullptr;
	DIR * pwd = opendir(".");  //opens current directory into pwd
	
	if(pwd == nullptr){
		perror("opendir");
	}
	else{
		while((entry = readdir(pwd)) != nullptr){  //while entry is reading directory of pwd
			cout << entry->d_name << endl;  //prints entry name
		}
		closedir(pwd);  //closes pwd
	}
	return EXIT_SUCCESS;
}
