#include "Btree.h"
#include "key.h"
#include "bnode.h"
using namespace std;


Btree::Btree(int n)
{
	root=new bnode;
	base=new bnode;
	order=n;
}

/***************************SEARCH*******************************/
bnode* searchHelper(bnode* root,string str);

key* Btree::search(string str)
{
	bnode* bnode1=new bnode;
	bnode1 = searchHelper(root,str);
	
	int flag=0;
	list<key*>::iterator itr;
	for(itr=bnode1->keyList.begin();itr!=bnode1->keyList.end();itr++)
	{
		if((*itr)->name==str)
		{
			flag=1;
			return *itr;
			break;
		}
		else
		{
			flag=0;
			continue;
		}
	}
	
	if(flag==0)
		return NULL;		
}


bnode* searchHelper(bnode* root,string str)
{
//	cout<<root->keyList.size()<<endl;
	list<key*>::iterator cat=root->keyList.begin();
//	cout<<root->keyList.size()<<endl;
	if((*cat)->leftChild==NULL)
	{
		return root;
	}
	else
	{
		int flag=0;
		
		list<key*>::iterator itr;
		for(itr=root->keyList.begin();itr != root->keyList.end();itr++)
		{
			if(str==(*itr)->name)
			{
				flag=1;
				return root;
				break;
			}
			else if(str < (*itr)->name)
			{
				flag=1;
				return searchHelper((*itr)->leftChild,str);
				break;
			}
			else
			{
				flag=0;
				continue;
			}
		}
		
		if(flag==0)
		{
			itr--;
			return searchHelper((*itr)->rightChild,str);
		}
	}				
}

/*********************PRINT*************************************/

void printHelper(bnode* root);

void Btree::print()
{
	cout<<"***************PRINT********************************"<<endl;
	
	printHelper(root);
}

void printHelper(bnode* root)
{
	if(root!=NULL)
	{
		list<key*>::iterator itr;
		
		for(itr=root->keyList.begin();itr != root->keyList.end();itr++)
		{
			 printHelper((*itr)->leftChild);
			
			cout<<(*itr)->name<<"--";
			//<<root<<" "<<root->parent<<","<<(*itr)->leftChild<<"  "<<(*itr)->rightChild<<endl;
			
			
			list<string>::iterator itr1;
			for(itr1=(*itr)->addStore.begin();itr1!=(*itr)->addStore.end();itr1++)
			{
				cout<<*itr1<<"**************";
			}
			cout<<endl;
			
			
		}
		
		itr--;
		printHelper((*itr)->rightChild);
		
		
	}
}



/***********************INSERT**********************************/


void Btree::insert(key* newKey)
{
	if(base->keyList.size()==0)
	{	//cout<<333<<endl;
		list<key*>::iterator itr=base->keyList.begin();
		newKey->self=base->keyList.insert(itr,newKey);
		newKey->selfNode=base;
		
		root=base;
//		cout<<root->keyList.size()<<endl;
	}
	else
	{//cout<<444<<endl;
		
	bnode* bnode1=new bnode;	
	bnode1=searchHelper(root,newKey->name);
	
	list<key*>::iterator itr23=bnode1->keyList.begin();
	//cout<<" starting-  "<<(*itr23)->name ;
	
	int flag=0;
	
		list<key*>::iterator itr;
		for(itr=bnode1->keyList.begin();itr!=bnode1->keyList.end();itr++)
		{
			if((*itr)->name==newKey->name)
			{
				flag=1;
				(*itr)->addStore.push_back(newKey->address);
				break;
			}
			else
				continue;
		}
	
	if(flag==0)
		insertHelper(bnode1,newKey);
	
	}
}

//////////////////////////////////////////////////////////

void Btree::takeInput(string str)
{
	string str1;
	str1=str;
}



void Btree::insertHelper(bnode* newNode,key* newKey)	
{
	if(newNode==NULL)
	{
		cout<<"root changed : "<<newKey->name<<endl;
		bnode* newNode=new bnode;
		root=newNode;
		
		list<key*>::iterator itr=newNode->keyList.begin();
		newKey->self=newNode->keyList.insert(itr,newKey);
		newKey->selfNode=newNode;
		
		newKey->leftChild->parent=newNode;
		newKey->rightChild->parent=newNode;
		newNode->parent=NULL;
	}
		
	else
	{
		int flag=0;
		
		list<key*>::iterator itr;
		for(itr=newNode->keyList.begin();itr!=newNode->keyList.end();itr++)
		{
			if((*itr)->name > newKey->name)
			{
				flag=1;
				newKey->self=newNode->keyList.insert(itr,newKey);
				newKey->selfNode=newNode;
	
				if(newKey->leftChild !=NULL)
				{	
					newKey->leftChild->parent=newNode;
				}	
				if(newKey->rightChild !=NULL)
				{
					newKey->rightChild->parent=newNode;
				
					
					(*itr)->leftChild=newKey->rightChild;	
				}
				
				break;
			}
		}
		
		
		if(flag==0)
		{
			newKey->self=newNode->keyList.insert(itr,newKey);
			newKey->selfNode=newNode;
			
			if(newKey->leftChild !=NULL)
				newKey->leftChild->parent=newNode;
			if(newKey->rightChild !=NULL)
				newKey->rightChild->parent=newNode;
		}
	
	//breakin the list
	
		if(newNode->keyList.size()==order)
		{
			bnode* bnode1=new bnode;
			

			for(int i=0;i< order/2;i++)
			{
				itr=bnode1->keyList.begin();
				
				key* nk=new key;
				
				nk=newNode->keyList.back();
				
				if(nk->leftChild !=NULL)
					nk->leftChild->parent=bnode1;
				if(nk->rightChild !=NULL)
					nk->rightChild->parent=bnode1;
					
				nk->self = bnode1->keyList.insert(itr,nk);
				nk->selfNode = bnode1;
				newNode->keyList.pop_back();	
			}
			
			key* key1=new key;
			key1=newNode->keyList.back();
			newNode->keyList.pop_back();
			
			key1->leftChild=newNode;
			key1->rightChild=bnode1;
						
			Btree::insertHelper(newNode->parent,key1);
		}
	}
}


/*********************ERASE********************************************/
