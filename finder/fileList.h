#ifndef FILELIST_H
#define FILELIST_H

#include<iostream>
#include<dirent.h>
#include<unistd.h>
#include<vector>
#include<stdlib.h>
#include<cstring>
#include<fstream>
#include<sys/stat.h>
using namespace std;

class fileList
{
	public:
		ifstream input;
		ifstream exput;
		ofstream output;
	
	
		fileList(){};
		void fileSet(const char* dirp,string str);  //list files of given directory and it's subdirectory
		int listdir(const char *path);
		int HomeFinder(const char* dirname,char homeFolder[256]);
		int usrFinder(const char* dirname,char usrFolder[256]);
		vector<char*> folderSet(const char* dirp);
		void runner(); 

};
#endif
