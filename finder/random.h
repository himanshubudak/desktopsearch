#ifndef RANDOM_H
#define RANDOM_H

#include<iostream>
#include<fstream>  ///////.............APP  APP APP....................
#include "fileList.h"
#include "bnode.h"
#include "tries.h"
#include <list>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


struct fax
{
    string nam;
    string add;

    fax(string nam1="",string add1="")
    : nam(nam1),add(add1){}
};


vector<fax*> process(string str,tries t2,tries t1,int n);

void showthis(fax* newfax,tries t2,tries t1);
void callPrefixTrie(tries t2);
void callHistoryTrie(tries t1);
void onClose(tries t1);
vector<fax*> full(string str,tries t2);
/************************************Btree******************************/

//creating b-tree object to read files in b-tree
/*
void callBtree(Btree b1)
{

    ifstream it;                        // to read from index.txt
    it.open("index.txt");
    string line;
    string name;
    string address;
    int i=0;
    if(!it.good()){cout<<"cant open index.txt for some reason"<<endl;}
    while(getline(it,line))
    {
        cout<<"into the while loop"<<endl;
        int sep;
        sep=line.find(',');
        name=line.substr(0,sep);
        address=line.substr(sep+1,line.size());
        cout<<"name" <<name <<endl;
        key* k1=new key(name,address);
        b1.insert(k1);
    }


    cout<<"after the awhile loop\n";

    it.close();
    b1.print();

}


	
*/
#endif
