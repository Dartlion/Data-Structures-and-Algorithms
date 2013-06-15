#include "iostream"
using namespace std;

/*calaculate x^idx*/
int power(int x, int idx)
{
	if (0 == idx)
	{
		return 1;
	}
	if (1 == idx)
	{
		return x;
	}
	if (0 == idx%2)
	{
		return power(x*x, idx/2);
	}
	if (1 == idx%2)
	{
		return power(x*x, idx/2) * x;		
	}
}

int main()
{
	cout<< power(2,0) <<endl;
	cout<< power(2,1) <<endl;
	cout<< power(2,10) <<endl;
	cout<< power(2,11) <<endl;
}
