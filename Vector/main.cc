#include "Vector.h"
#include "iostream"
using namespace std;

int main()
{
	Vector<int> vec;
	cout<<"size = "<<vec.size()<<endl;
	cout<<"capacity = "<<vec.capacity()<<endl;

	for(int i=0; i< 38; ++i)
	{
		vec.push_back(i);
	}

	Vector<int> vec2(vec);
	cout<<"vec2 : ";
	for(Vector<int>::const_iterator it=vec2.begin(); it< vec2.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	Vector<int> vec3 = vec2;
	cout<<"size = "<<vec3.size()<<endl;
	cout<<"capacity = "<<vec3.capacity()<<endl;
	cout<<"back = "<<vec3.back()<<endl;
	cout<<"vec[5] = "<<vec3[5]<<endl;

	return 0;


}
