#include "fileList.h"
#include <cstring>
using namespace std;


// To show all files and folder of given folder

int fileList::listdir(const char *path) {
  struct dirent *entry;
  DIR *dp;
 
  dp = opendir(path);
  if (dp == NULL){return -1;}
 
  while ((entry = readdir(dp)))
    cout<<entry->d_name<<endl;
 
  closedir(dp);
  return 0;
}
 
/********************************************************/

// to change dir to home folder 

int fileList::HomeFinder(const char* dirname,char homeFolder[256])
{
	//ofstream output;
	//output.open("output.txt");
	
	DIR *pdir=NULL;
	pdir=opendir(dirname);
	int flag=0;
	
	struct dirent *pent=NULL;
	
	if(pdir!=NULL)
	{
		while((pent=readdir(pdir))!=NULL)
		{			
			if(strcmp(pent->d_name,homeFolder)==0)
			{
			//	cout<<"HomeFolder : "<<homeFolder<<" "<<pent<<endl;
				
				if(chdir(homeFolder)==0);
				{
					string str1="/users/ug11/";
					str1.append(homeFolder);
					str1.append("/");
		//			cout<<"home  "<<str1<<endl;
					fileList::fileSet(".",str1);
					break;
				}
			}
			
			
			if(strcmp(pent->d_name,"..")==0)
			{
				chdir("..");
				HomeFinder(".",homeFolder);
				break;
			}
					
		}
	}
	closedir(pdir);
	
	return EXIT_SUCCESS;
}


/************************************************************/

// store all files and folders of given directory in a vector

vector<char*> fileList::folderSet(const char* dirp)
{
	DIR *pdir=NULL;
	pdir=opendir(dirp);
	
	vector<char*> folderVector;
	struct dirent *pent=NULL;
	
	if(pdir!=NULL)
	{
		while((pent=readdir(pdir))!=NULL)
		{
			int dk1 = pent->d_name[0];
			int dk='.';
			if(dk1 !=dk)
			{
				folderVector.push_back(pent->d_name);
				
			}
		}				
	}
	
	return folderVector;	
}


/************************************************************/


void fileList::fileSet(const char* dirp,string str)
{
	
	vector<char*> fileStore;
	fileStore = folderSet(dirp);
	
	for(int i=0;i<fileStore.size();i++)
	{
		struct stat s;
		if( stat(fileStore[i],&s) == 0 )
		{
			if( s.st_mode & S_IFDIR )
			{
				string str1=str;
				str.append(fileStore[i]);
				str.append("/");
				output<<fileStore[i]<<","<<str<<endl;
				chdir(fileStore[i]);
				
			
				fileList::fileSet(".",str);
				str=str1;
			}
			else if( s.st_mode & S_IFREG )
			{
				string str2=str;
				str.append(fileStore[i]);
				output<<fileStore[i]<<","<<str<<endl;
				str=str2;
			}
		}
	}
	chdir("..");

}
	

/******************************************RUN********************************************/
void fileList::runner()
{
	system("whoami > username.txt");
	input.open("username.txt");
	output.open("index.txt");
	char name[256];
	input.getline (name,256);
	char nmm[256]="usr";
	HomeFinder(".",name);
	usrFinder(".",nmm);
	input.close();
	output.close();
}


/***************************************************usr finder****************************************/

int fileList::usrFinder(const char* dirname,char usrFolder[256])
{
	//ofstream output;
	//output.open("output.txt");
	
	DIR *pdir=NULL;
	pdir=opendir(dirname);
	int flag=0;
	
	struct dirent *pent=NULL;
	
	if(pdir!=NULL)
	{
		while((pent=readdir(pdir))!=NULL)
		{			
			if(strcmp(pent->d_name,usrFolder)==0)
			{
				
				
				if(chdir(usrFolder)==0);
				{
		
					vector<char*> fileStore;
					fileStore = folderSet("bin");

					for(int i=0;i<fileStore.size();i++)
					{
                        string str="##";
						
						string str1=fileStore[i];
						if((str1[0]>96 && str1[0]<123) || (str1[0]>64 && str1[0]<91))
						{
							output<<fileStore[i]<<","<<str<<endl;
						}
					}
					return EXIT_SUCCESS;
					break;
				}
			}
			
					
		}
		chdir("..");
		usrFinder(".",usrFolder);
		
	}
	closedir(pdir);
	
	return EXIT_SUCCESS;
}
