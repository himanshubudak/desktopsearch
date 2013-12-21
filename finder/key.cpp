#include "key.h"
#include "Btree.h"

key::key(string name1,string add)
{
	name=name1;
	address=add;
	addStore.push_back(add);
}
	
