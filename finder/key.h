#ifndef KEY_H
#define KEY_H

#include<iostream>
#include<list>
#include "bnode.h"
//#include "Btree.h"
using namespace std;
class bnode;
class key
{
	public:
		string name;
		string address;
		typedef list<key*>::iterator itr;
		itr self;
		
		bnode* selfNode;
		bnode* leftChild;
		bnode* rightChild;
		
		list<string> addStore;  //adress storing list of same file but different address
		
		key(string name1="",string add="");
};

#endif
