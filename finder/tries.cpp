#include "tries.h"
#include<fstream>
ofstream output;


tries::tries()
{
	root=new node;
	root->name="ROOT";
	root->address="";
	list<node*>::iterator itr=rootList.begin();
	
	root->self=rootList.insert(itr,root); 
}	
/***************************PRINT**************************************/

void printHelper(node* root);
void tries::print()
{
	cout<<"********************PRINT***************"<<endl;
	printHelper(root);
}

void printHelper(node *root)
{
	list<node*>::iterator itr;
	
	for(itr=root->childList.begin();itr != root->childList.end();itr++)
	{
		cout<<(*itr)->name<<"--";
		if((*itr)->store.size()!=0)
		{
			list<node*>::iterator itr1;
			for(itr1=(*itr)->store.begin();itr1!=(*itr)->store.end();itr1++)
			{
				cout<<(*itr1)->name<<","<<(*itr1)->address<<","<<(*itr1)->count<<endl;
			}
		}
		
		if((*itr)->childList.size()!=0)
		{
			printHelper(*itr);
		}
		
	//	cout<<endl;
	}
}
			
		

/**************************INSERT**************************************/
void insertHelper(node* root,node* newNode,string str);
void tries::insert(node* newNode)
{
	
	insertHelper(root,newNode,newNode->name);
}

void insertHelper(node* root,node* newNode,string str)
{
	
	list<node*>::iterator itr;
	
	if(str.size()==0)
	{
		itr=root->store.end();
		newNode->self=root->store.insert(itr,newNode);
		newNode->parent=root->self;
	//	cout<<newNode->name<<endl;		
	}
	else if(root->childList.size()==0)
	{
		//creating nodes for all string characters one by one
		
		for(int i=0;i<str.size();i++)
		{
		  node* strNode=new node;
			
		  char c=str[i];
		  int k=c;
	      if(!(k<123 && k>96))
		  {
			  k=k+32;
			  c=k;
			str[i]=c;
		  }
			strNode->name=str[i];
			strNode->parent=root->self;
		//	cout<<"id "<<strNode->name<<" "<<(*(strNode->parent))->name<<endl;
			itr=root->childList.end();
			strNode->self=root->childList.insert(itr,strNode);
		//	cout<<"id "<<strNode->name<<" "<<(*(strNode->parent))->name<<endl<<endl;
			
			root=strNode;
		  
		  
		}
		
		itr=root->store.end();
		newNode->self=root->store.insert(itr,newNode);
		newNode->parent=root->self;
		
	}
	else
	{
		int flag=0;
		itr=root->childList.begin();
		
		for(itr;itr!=root->childList.end();itr++)
		{
			char c=str[0];
			int k=c;
			if(!(k<123 && k>96))
			{
				k=k+32;
				c=k;
				str[0]=c;
			}
			
			if(str[0] < (*itr)->name[0])
			{
				flag=1;
				node* strNode=new node;
				strNode->name=str[0];
				strNode->parent=root->self;
				strNode->self=root->childList.insert(itr,strNode);
			
				insertHelper(strNode,newNode,str.substr(1,str.size()));
				break;
			}
			else if(str[0]>(*itr)->name[0])
			{
				flag=0;
				continue;
			}
			else
			{
				flag=1;
				insertHelper(*itr,newNode,str.substr(1,str.size()));
				break;
			}
		}
		
		if(flag==0)
		{
			node* strNode=new node;
			strNode->name=str[0];
			strNode->parent=root->self;
			strNode->self=root->childList.insert(itr,strNode);
			
			insertHelper(strNode,newNode,str.substr(1,str.size()));
		}
	}
}


/******************SEARCH*********************************************/

node* searchHelper(node* root,string str,string fullstr);
node* tries::search(string str)
{
	//cout<<"*********search Result**************"<<endl;
	return searchHelper(root,str,str);
}				

node* searchHelper(node* root,string str,string fullstr)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(str.size()==0)
	{
		return root;
	}
	else
	{
		char c=str[0];
		int k=c;
		if(!(k<123 && k>96))
		{
			k=k+32;
			c=k;
			str[0]=c;
		}
		
		list<node*>::iterator itr;
		
		int flag=0;
		
		for(itr=root->childList.begin();itr!=root->childList.end();itr++)
		{
			if(str[0]==(*itr)->name[0])
			{
				flag=1;
				return searchHelper(*itr,str.substr(1,str.size()),fullstr);
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
}
	
/****************ERASE************************************************/	

	
void tries::erase(string str,string counter)
{
	node* newNode=new node;
	newNode = tries::search(str);
	
	list<node*>::iterator itr;

	if(newNode==NULL)
		cout<<"already doesn't exit"<<endl;
	else
	{
		//cout<<"search found "<<newNode->name<<endl;
		if(newNode->childList.size() >0 || newNode->store.size()>1)
		{
			for(itr=newNode->store.begin();itr!=newNode->store.end();itr++)
			{
				if((*itr)->name==str && (*itr)->address==counter)
				{
				//	cout<<"store size "<<newNode->store.size()<<endl;
					delete *itr;					
					newNode->store.erase(itr);
				//	cout<<"store size "<<newNode->store.size()<<endl;
				//	cout<<str<<"  deleted"<<endl;
					break;
				}
			}
		}
		
		else
		{
			itr=newNode->store.begin();	
			delete *itr;
			itr=newNode->store.erase(itr);
			
			node* prevNode=new node;
			while(newNode->childList.size()<1 && newNode->store.size()==0 && (*(newNode->parent))->name!="ROOT")
			{
				prevNode=newNode;
				newNode=*(newNode->parent);
				delete *(prevNode->self);
				itr=newNode->childList.erase(prevNode->self);
			}
			if((*(newNode->parent))->name == "ROOT" && newNode->childList.size()==0)
			{
				root->childList.erase(newNode->self);
				delete newNode;
			}
			
			
		}
	}
}
					
/*****************AUTOCOMPLETE********************************************/

void autoHelper(node *root, priority_queue<node*,vector<node*>,node> & fileOrder);

void tries::autocomplete(string str)        //apply const
{
	if(str.size()!=0)
	{
		node* newNode=new node;
		newNode=tries::search(str);
		if(newNode!=NULL)
		{//cout<<444<<endl;
			if(newNode->store.size()!=0)
			{
				list<node*>::iterator itr;
				for(itr=newNode->store.begin();itr != newNode->store.end();itr++)
				{
					fileOrder.push(*itr);
				}
			}
			
			autoHelper(newNode,fileOrder);
		//	return  fileOrder;
		}
		
	}
}

	
void autoHelper(node *root, priority_queue<node*,vector<node*>,node> & fileOrder)
{
	list<node*>::iterator itr;
	
	
	for(itr=root->childList.begin();itr != root->childList.end();itr++)
	{
		if((*itr)->store.size()!=0)
		{
			list<node*>::iterator itr1;
			for(itr1=(*itr)->store.begin();itr1!=(*itr)->store.end();itr1++)
			{
				fileOrder.push(*itr1);
			}
		}
		
		if((*itr)->childList.size()!=0)
		{
			autoHelper(*itr,fileOrder);
		}
		
	//	cout<<endl;
	}
}


/***********************UPDATE COUNTER************************************/

void tries::updateCount(string str,string counter)
{
	node* st=new node;
	st=tries::search(str);
	
	list<node*>::iterator itr=st->store.begin();
		
	for(itr;itr != st->store.end();itr++)
	{
		if((*itr)->address==counter)
		{
			(*itr)->count++;
		}
	}  	
}
	 
/********************ReWriteHistory*************************************/
void reHelper(node* root);

void tries::reWriteHistory()
{
    cout<<767676<<endl;
	output.open("history.txt");
	reHelper(root);
	output.close();
}

void reHelper(node* root)
{
	list<node*>::iterator itr;
	
	for(itr=root->childList.begin();itr != root->childList.end();itr++)
	{
		if((*itr)->store.size()!=0)
		{
			list<node*>::iterator itr1;
			for(itr1=(*itr)->store.begin();itr1!=(*itr)->store.end();itr1++)
			{
				output<<(*itr1)->name<<","<<(*itr1)->address<<","<<(*itr1)->count<<endl;
			}
		}
		
		if((*itr)->childList.size()!=0)
		{
			reHelper(*itr);
		}
		
	//	cout<<endl;
	}
}
