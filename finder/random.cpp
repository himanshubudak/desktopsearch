/*******************************************************************************/
//predict filename...

#include"random.h"
#include<iostream>
using namespace std;

vector<fax*> full(string str,tries t2)
{
    vector<fax*> abc;
    node* newNode=new node;

    newNode=t2.search(str);
    if(newNode!=NULL)
    {
        list<node*>::iterator itr=newNode->store.begin();
    for(itr;itr!=newNode->store.end();itr++)
    {
        fax* neww=new fax;
        neww->nam=(*itr)->name;
        neww->add=(*itr)->address;
        abc.push_back(neww);
    }

    }
    return abc;
}

vector<fax*> process(string str,tries t2,tries t1,int n)
{
    vector<fax*> sto; //vector to store possiblities
    vector<fax*> acList; //final display list vector

    t2.autocomplete(str);

    int m=n*0.3; //history list size
    int i=0;
    while (!t2.fileOrder.empty())
    {
        fax* newfax=new fax(t2.fileOrder.top()->name,t2.fileOrder.top()->address);
        sto.push_back(newfax);
        t2.fileOrder.pop();
    }


    //reading possible history item in displaying vector
    t1.autocomplete(str);
    i=0;
    while (!t1.fileOrder.empty())
    {
        if(i!=m+1)
        {
            fax* newfax=new fax(t1.fileOrder.top()->name,t1.fileOrder.top()->address);
            acList.push_back(newfax);
            t1.fileOrder.pop();
            i++;
        }
        else
            break;
    }


    for(i=0;i<sto.size();i++)
    {
        acList.push_back(sto[i]);
    }

    //display final autocomplete  list

/*	for(i=0;i<acList.size();i++)
    {
        cout<<acList[i]->nam<<" "<<acList[i]->add<<endl;
    }
    */
    return acList;
}

/*******************************************************************************/

// open selected file
void showthis(fax* newfax,tries t2,tries t1)
{   //cout<<"emtejdjksdjjd"<<endl;
    //system("geany");
    node* st=new node;
    st=t2.search(newfax->nam);

    if(st!=NULL &&  st->store.size()!=0)
    {
        list<node*>::iterator itr=st->store.begin();

        for(itr;itr != st->store.end();itr++)
        {
            if((*itr)->address==newfax->add)
            {
                if(newfax->add != "##")
                {
                    string str="gnome-open ";
                    str.append("'");
                    str.append(newfax->add);
                    str.append("'");

                    system(str.c_str());
                }
                else
                {
                    string str3=newfax->nam;
                    system(str3.c_str());
                }
                break;
            }
        }

        // writing this file in history

      node* st1=new node;
      st1=t1.search(newfax->nam);


        if(st1!=NULL &&  st1->store.size()!=0)
        {
            list<node*>::iterator itr1=st1->store.begin();

            for(itr1;itr1 != st1->store.end();itr1++)
            {
                if((*itr1)->address==newfax->add)
                {
                    (*itr1)->count++;
                    break;
                }
            }
          }
          else
          {
              node* st2=new node(newfax->nam,newfax->add,1);
              t1.insert(st2);
          }
    }
    else
        cout<<"Doesn't exit"<<endl;
}



/****************************************************************/
//crating new trie object for prefix trie
void callPrefixTrie(tries t2)
{
    ifstream input;                        // to read from history.txt
    input.open("index.txt");
    string line;
    string name;
    string address;
    int counter;

    if (input.is_open())
    {
        while (input.good() )
        {
            getline(input,line);

          if(line.size()!=0)
          {
            int i=0;
            while(line[i]!=',')
            {
                name.append(1,line[i]);
                i++;
            }
            i++;
            while(line[i]!='\0')
            {
                address.append(1,line[i]);
                i++;
            }

            counter=0;
            node* n1=new node(name,address,counter);

            t2.insert(n1);
            name="";
            address="";
          }
        }
    }
    input.close();
    //t2.print();

}

/****************************************************************/
//crating new trie object for maintaining history
void callHistoryTrie(tries t1)
{
    ifstream iput;
    iput.open("history.txt");  //reading from history.txt
    string line;
    string name;
    string address;
    string counter1;
    int counter;
    if (iput.is_open())
    {
        while (iput.good() )
        {
            getline(iput,line);

          if(line.size()!=0)
          {
            int i=0;
            while(line[i]!=',')
            {
                name.append(1,line[i]);
                i++;
            }
            i++;
            while(line[i]!=',')
            {
                address.append(1,line[i]);
                i++;
            }
            i++;
            while(line[i]!='\0')
            {
                counter1.append(1,line[i]);
                i++;
            }
            counter=atoi(counter1.c_str());

        //	cout<<name<<"  "<<address<<"  "<<counter<<endl;

            node* n1=new node(name,address,counter);

            t1.insert(n1);
        //	t1.print();

            name="";
            address="";
            counter1="";
          }
         }
    }
    iput.close();
}
/******************************************************************/

// on closing program call to rewrite history
void onClose(tries t1)
{
    t1.reWriteHistory();
}

