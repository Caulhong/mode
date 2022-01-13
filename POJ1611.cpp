#include <iostream>
using namespace std;
int n,m;
const int maxn = 3e4+10;
int father[maxn];
int total[maxn];
void init()
{
	for(int i = 0; i < n; ++i)
	{
		father[i] = i;
		total[i] = 1;
	}
}
int find(int x)
{
	if(x == father[x])return x;
	return father[x] = find(father[x]);
}
void merge(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
	{
		total[fx]+=total[fy];
		father[fy] = fx;
	}
}
int main()
{
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		else
		{
			init();
			for(int i = 1; i <= m; ++i)
			{
				int p;
				cin >> p;
				int tmp;
				int fa;
				for(int j = 1; j <= p; ++j)
				{
					cin >> tmp;
					if(j == 1) fa = tmp;
					else
					{
						merge(tmp,fa);
					}
				}
			}
			cout << total[find(0)] << endl;
		}
	}
	return 0;
}
