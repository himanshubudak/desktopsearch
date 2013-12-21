#ifndef BNODE_H
#define BNODE_H
#include<list>
#include<iostream>
//#include "Btree.h"
//#include "key.h"
using namespace std;
class key;
class bnode
{
	public :
		list<key*> keyList;
		bnode* parent;
		
		
	//	list<bnode*> childList;
	//	typedef list<bnode*>::iterator iter;
		
		
		bnode(); 
};

#endif
