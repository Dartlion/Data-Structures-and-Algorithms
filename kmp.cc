using namespace std;
#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "numeric"

int GenPartialMatchTable(const string &src, vector<int> &v)
{
	vector<string> prefix;
	vector<string> suffix;
	string s;
	size_t cnt = 0;

	for(size_t len=1; len<=src.size(); ++len)
	{
		prefix.clear();
		suffix.clear();
		cnt = 0;

		/*generate prefix and suffix vector*/
		for(size_t sz=1; sz<len; ++sz)
		{
			prefix.push_back(src.substr(0, sz));
			suffix.push_back(src.substr(len-sz,sz));
		}

		/* look the common element in two vector and
		 * calculate the largest size in the common element*/	
		vector<string>::iterator it  = prefix.begin();
		while( (it = find_first_of(it, prefix.end(), suffix.begin(), suffix.end()))
			         != prefix.end() )
		{
			if (it != prefix.end())
			{
				if ((*it).size() > cnt)
				{
					cnt = (*it).size();
				}
			}
			++it;
		}
		v.push_back(cnt);
	}
	return 0;
}

/*KMP string search algoritm
 * @arg src : souce string
 * @arg mode : search string
 * @arg vec : partial match table of mode
 * @ret : the number of match times
 *
 * @ref : http://www.ruanyifeng.com/blog/2013/05 */
int Kmp(string &src, string &mode)
{
	string CmpString;
	vector<int> vec;
	size_t srcLen = src.size();
	size_t modeLen = mode.size();
	size_t cnt = 0;
	size_t idx = 0; 

	if (srcLen < modeLen)
	{
		return cnt;
	}
	
	GenPartialMatchTable(mode, vec);

	while(idx <= srcLen - modeLen)
	{
		CmpString = src.substr(idx,modeLen);
		for(size_t k=0; k<modeLen; ++k)
		{
			/*full match*/
			if ((k == modeLen -1) && (src[idx+k] == mode[k]))
			{
				++cnt;
				idx = idx + ( modeLen-vec[modeLen-1]);
				break;
			}
			if (src[idx+k] == mode[k])
			{
				continue;
			}
			/*no match*/
			if (k == 0)
			{
				idx = idx + 1;
				break;
			}
			/*match partial*/
			if (k > 0) 
			{
				idx = idx + (k-vec[k-1]);
				break;
			}
		}
		CmpString = "";

	}
	return cnt;
}

int main()
{
	string src = "BBC ABCDAB ABCDABCDABDE";
	string mode = "ABCDABD";

    size_t matchCnt = Kmp(src, mode);

	cout<<"match count: "<< matchCnt <<endl;

	return 0;
}

