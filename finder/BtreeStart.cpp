#include<iostream>
#include<fstream>
#include "Btree.h"
#include "key.h"
using namespace std;

main()
{
	Btree b1;
	ifstream input;
	input.open("index.txt");
	string line,name,address;
	
	while(getline(input,line))
	{
		int sep=0;
		sep=line.find(',');
		name=line.substr(0,sep);
		address=line.substr(sep+1,line.size());
		
		key* k1=new key(name,address);
		b1.insert(k1);
		name="";
		address="";
	}
	
	input.close();
	b1.print();
}
