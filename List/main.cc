#include "List.h"
#include "iostream"
using namespace std;

int main()
{
	List<int> lst;
	cout<<"size = "<<lst.size()<<endl;

	for(int i=0; i< 38; ++i)
	{
		lst.push_back(i);
	}

	List<int> lst2(lst);
	cout<<"lst2 : ";
	for(List<int>::const_iterator it=lst2.begin(); it != lst2.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	lst2.erase(++lst2.begin());
	lst2.push_front(-100);
	lst2.pop_back();
	lst2.push_back(100);

	cout<<"lst2 : ";
	for(List<int>::const_iterator it=lst2.begin(); it != lst2.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	List<int> lst3 = lst2;
	cout<<"size = "<<lst3.size()<<endl;
	cout<<"back = "<<lst3.back()<<endl;

	return 0;


}
