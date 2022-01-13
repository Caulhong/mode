#include <iostream>
using namespace std;
const int maxn = 1e4+5;
int father[maxn];
int n, m;
void init()
{
	for(int i = 0; i <= n; ++i)
	{
		father[i] = i;
	}
}
int find(int x)
{
	if(father[x] == x) return x;
	return father[x] = find(father[x]);
}
int main()
{
	cin >> n >> m;
	init();
	int a, b, c;
	for(int i = 1; i <= m; ++i)
	{
		cin >> a >> b >> c;
		if(a == 1)
		{
			father[find(b)] = find(c);
		}
		else if(a == 2)
		{
			if(find(b) == find(c))
			{
				cout << "Y" << endl;
			}
			else 
			{
				cout << "N" << endl;
			}
		}
	}
	return 0;
}
