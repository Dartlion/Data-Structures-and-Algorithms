using namespace std;
#include "iostream"
#include "string"
#include "vector"

#define DEBUG

/*generate the good suffix table*/
int GenGoodSuffixTbl(string &mode,vector<int> &v )
{
	vector<int> vec;
	string suffix;
	string preSuffix;
	size_t len = mode.size();
    size_t cnt = 1;
	bool flag = 0;

	if (len == 0)
	{
		return 0;
	}
	for(int i=len-1; i>=0; --i)
	{
		if (0 == i)
		{
			vec.push_back(-1);
			break;
		}
		if (flag)
		{
            vec.push_back(*(vec.end()-1));
			continue;
		}
		suffix = mode.substr(i, cnt);
		for(int j=i-1; j>=0; --j)
		{
			preSuffix = mode.substr(j,cnt);

			/*the good suffix exist in mode*/
			if (suffix == preSuffix)
			{
				vec.push_back(j+cnt-1);
				break;
			}
			/*the good suffix not exit in mode*/
			if (0 == j) 
			{
				size_t sz = cnt-1;
				size_t k = 1;
				/*look the longest sub string in good suffix which match prefix of mode*/
				while (sz > 0 && k < cnt)
				{
					if (mode.substr(0,sz) == suffix.substr(k, sz))
					{
						vec.push_back(sz-1);
						break;
					}
					++k;
					--sz;
				}
				if (0 == sz && k == cnt)
				{
					flag = 1;
					vec.push_back(-1);
					break;
				}
			}
		}
        ++cnt;
	}
	/*reverse the element of vector*/
	for(int i=vec.size()-1; i>=0; --i)
	{
		v.push_back(vec[i]);
	}
	return 0;
}

/*Boyer-Moore string search algoritm
 * * @arg src : souce string
 * * @arg mode : search string
 * * @arg goodSuffixTbl
 * * @ret : the number of match times
 * *
 * * @ref : http://www.ruanyifeng.com/blog/2013/05 */
int Boyer_Moore(string &src, string &mode)
{
	string CmpString;
	vector<int> goodSuffixTbl;
	size_t srcLen = src.size();
	size_t modeLen = mode.size();
	size_t cnt = 0;
	size_t idx = 0;
	size_t badCharShfit = 0;
	size_t goodSuffixShfit = 0;
	size_t shift = 0;

	if (srcLen < modeLen)
	{
		return cnt;
	}
	
	GenGoodSuffixTbl(mode,goodSuffixTbl);
#ifdef DEBUG
	cout<<"good suffix table : ";
	for(size_t i=0; i<goodSuffixTbl.size(); ++i)
	{
		cout<<goodSuffixTbl[i]<<" ";
	}
	cout<<endl;
#endif

	while (idx <= srcLen - modeLen)
	{
		for (size_t k=modeLen-1; k>=0; --k)
		{
			/*full match*/
			if (0==k && mode[0]== src[idx])
			{
				++cnt;
				idx += (modeLen-1) - goodSuffixTbl[k];
				break;
			}
			/*partial match*/
			if (src[idx+k] != mode[k])
			{
				/*k is the locate of the not match char in mode*/
				for (size_t j=k-1; j>=0; --j)
				{
					if (src[idx+k]==mode[j])
					{
						/*bad char algorithm: bad char is the first not match char 
						 * shfit = (the locate of bad char in mode)-
						 *         (the locate of bad char appear the firs bad char in mode)*/
						badCharShfit = k - j;
						break;
					}
					if (0 == j && src[idx+k]!=mode[j])
					{
						badCharShfit = modeLen;
						break;
					}
				}
	            /*if no good suffix, shift is 0; 
				 * else use "good suffix algoritm"*/ 
				goodSuffixShfit = (k==modeLen-1) ? 0 : ((modeLen-1) - goodSuffixTbl[k]);

				shift = (badCharShfit >= goodSuffixShfit) ? badCharShfit : goodSuffixShfit;
				idx += shift;
				break;
			}
		}
	}
	return cnt;
}

int main()
{
	string s = "here is a simple example!";
	string mode ="example";
    
    size_t cnt = Boyer_Moore(s, mode);
	cout<<"find times: "<<cnt<<endl;

	return 0;
}
