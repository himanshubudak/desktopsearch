#ifndef TRIES_H
#define TRIES_H

#include<iostream>
#include<vector>
#include<list>
#include<cstring>
#include<queue>
using namespace std;


struct node
{
	string name;
	// pointer....
	int count;
	string address;
	typedef list<node*>::iterator itr;
	itr parent;
	itr self;
	list<node*> store;
	list<node*> childList; 

	node(string d="",string counter="",int count1=0)
	: name(d),address(counter),count(count1){}
	
	bool operator() ( const node* lhs, const node* rhs ) const
    {
        return lhs->count < rhs->count;
    }
	
};



class tries {
	private :
		node* root;
		list<node*> rootList;
		
		
	public :
		 priority_queue<node*,vector<node*>,node> fileOrder;
		
		tries();
		void print();
		void insert(node* newNode);    //write in file also
		node* search(string str);
		void erase(string str,string counter);   //counter means pointer address
		void autocomplete(string str);
		void updateCount(string str,string counter);  //after opening str file increment count of that file       // write in file also
		void update();
		// take list of deleted files from b-tree and delete that items from history list and now call fresh tries again
		void reWriteHistory();
};


#endif
