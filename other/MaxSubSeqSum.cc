#include "iostream"
#include "vector"
using namespace std;

/*calaculate the max subsequence sum.
 * the sum must larger than zero,else return 0*/
int MaxSubSeqSum(vector<int> &v, vector<int> &maxSubSeq)
{
	int sum = 0;
	int maxSum = 0;
	int start = 0;
	int beg = 0;
	int end = 0;

	for (size_t i=0; i<v.size(); ++i)
	{
		if (0 == sum)
		{	
			start = i;
		}
		sum += v[i];
		
		if (sum > maxSum)
		{
			maxSum = sum;
			beg = start;
			end = i;
		}
		if (sum < 0)
		{
			sum = 0;
		}
	}

	for (int k=beg; k<=end; ++k)
	{
		maxSubSeq.push_back(v[k]);
	}

	return maxSum;
}

int main()
{
	int a[50]= {9,0,-8,-7,1,8,4,-6,2,4,5,-1,-4,7,2,4,5,-4,-6,9,8,4,3,-2,-1,3,
	            5,-8,7,-9,4,-7,-6,3,5,-6,6,7,8,-11,2};
	vector<int> v(a,a+50);
	vector<int> maxSubSeq;

	cout<< "max sub sequence sum is: " << MaxSubSeqSum(v, maxSubSeq) << endl;

	cout<<"max sub sequence is: ";
	for (size_t i=0; i<maxSubSeq.size(); ++i)
	{
		cout<<maxSubSeq[i]<<" ";
	}
	cout<<endl;

}
