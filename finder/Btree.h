#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <list>
//#include "bnode.h"
#include "key.h"
#include<cstring>
using namespace std;

class bnode;
class key;
class Btree
{
	private :
		int order;
		bnode* root;
		bnode* base;
	//	list<bnode*> rootList;
	
	public :
		Btree(int n=5);
		void insert(key* newKey);
		void insertHelper(bnode* newNode,key* newKey);	
		void print();
		void takeInput(string str);
		key* search(string str);  //not key* since there may be more than 1 folders with same name
//		void erase(string str,string add);
};

#endif
