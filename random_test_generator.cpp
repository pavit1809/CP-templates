#include<bits/stdc++.h>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t=10;
	srand((unsigned) time(0));
	cout<<t<<endl;
	while (t--)
	{
		int n=rand()%15;
		cout<<n<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<rand()%10000000<<" ";
		}
		cout<<endl;
	}
    return 0;
}
