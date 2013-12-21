#include <QtGui/QApplication>
//#include "piechartqt.h"
#include <QScrollArea>
//#include<iostream>



#include<iostream>
#include<fstream>  ///////.............
#include "fileList.h"
#include "Btree.h"
#include "bnode.h"
#include "key.h"

#include "tries.h"
#include "random.h"
#include<list>
#include<string>
#include<vector>

using namespace std;


#include "piechartqt.h"

//@@@ basic definitions
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Arena *w = new Arena;

    //vector<string> vec;
    w->vec.push_back("1");
    w->vec.push_back("2");
    w->vec.push_back("3");
    w->vec.push_back("4");
/*
    w->vec.push_back("5");
    w->vec.push_back("6");
    w->vec.push_back("7");
    w->vec.push_back("8");
    w->vec.push_back("9");
    w->vec.push_back("10");
    w->vec.push_back("11"); w->vec.push_back("12");w->vec.push_back("13");w->vec.push_back("14");w->vec.push_back("15");
    w->vec.push_back("16");w->vec.push_back("17");w->vec.push_back("18");w->vec.push_back("19");w->vec.push_back("20");
    w->vec.push_back("21");w->vec.push_back("22");w->vec.push_back("23");w->vec.push_back("24");w->vec.push_back("25");
    w->vec.push_back("26");w->vec.push_back("27");w->vec.push_back("28");w->vec.push_back("29");w->vec.push_back("30");
    w->vec.push_back("31");w->vec.push_back("32");w->vec.push_back("33");w->vec.push_back("34");w->vec.push_back("35");
    w->vec.push_back("36");w->vec.push_back("37");w->vec.push_back("38");w->vec.push_back("39");w->vec.push_back("40");
    w->vec.push_back("41");
    

//  ################################################################//


    
    /**********************Creating indexes ******************************/
	
	ifstream iput;
    int updateCounter=100; //to update index files
//	int n=10;	// display list size
	string str1="qvlc";
	
	int flag=0,flag1=0;
	FILE* fp;
	fp=fopen("counter.txt","r");
	if(fp==NULL)
	{
		flag=1;
	}
	else
		fclose(fp);

	if(flag==1)
	{
		int k=1;
		fp=fopen("counter.txt","w");
		fprintf(fp,"%i",k);
		fclose(fp);
	}
	else
	{
		
		iput.open("counter.txt");
		int count;
		iput>>count;
		iput.close();
		
		if(count>=updateCounter)
		{
		//	callFileList();
			flag1=1;
			count=-1;
		}
		count++;
		
		fp=fopen("counter.txt","w+");
		fprintf(fp,"%i",count);
		fclose(fp);
	}
	
	if(flag1==1 || flag==1)
	{
		fileList f1;
		f1.runner();
	}


	
    

/********************Reading files in Prefix -trie********************************/	
		Btree b1;
		b1.takeInput(str1);
		tries t2;
		callPrefixTrie(t2);

/*************************history trie*****************************************/		

		tries t1;
		callHistoryTrie(t1);
				
/**************************************************************/
		string str;
		cout<<"enter the string :"<<endl;
		//cin>>str;
		 
        //vector<fax*> inputVector;
        //inputVector=process(str,t2,t1,n);
		
/*		for(int i=0;i<star.size();i++)
		{
			cout<<star[i]->nam<<endl;
		}
*/		 
/*		fax* fax1=new fax("rhythmbox-client","##");
		show(fax1,t2,t1);
		onClose(t1);
*/
    
//##########################################################################3


    w->startArena(t1,t2, 15);

    QScrollArea scrollarea;
    scrollarea.setWidget(w);
    scrollarea.setWidgetResizable(true);
    scrollarea.viewport()->setBackgroundRole(QPalette::Dark);
    scrollarea.viewport()->setAutoFillBackground(true);
    scrollarea.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollarea.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollarea.setWindowTitle(QObject::tr("arena"));
    scrollarea.show();




    //w->show();


    return a.exec();
}
