#include "bits/stdc++.h"
using namespace std;

#define vi vector<ll>
#define ll long long
#define pb push_back
#define nl "\n"
struct node
{
    int s,d,c;
};
bool comp(node n1,node n2)
{
    return n1.c<n2.c;
}
int find(int x,int *parent)
{
    if (parent[x]==x)
    {
        return x;
    }
    return find(parent[x],parent);
}
void unio(int s,int d,int *parent,int *size,int &cost,int cr)
{
	int parent_a=find(s-1,parent);
	int parent_b=find(d-1,parent);
    if(parent_a==parent_b)
        return;
    cost+=cr;
    if (size[parent_a]>=size[parent_b])//the larger connected component eats up the smaller one
    { 
       size[parent_a]+=size[parent_b];
        parent[parent_b]=parent_a;
    }
    else
    {
        size[parent_b]+=size[parent_a];
        parent[parent_a]=parent_b;
    }
    return;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
    freopen("error.in","w",stderr);
    #endif
    int t;
    cin>>t;
    int k=1;
    while (t--)
    {
    	int n,m,ca;
    	cin>>n>>m>>ca;
    	vector<node> v(m);
    	for(int i=0;i<m;i++)
    	{
    		cin>>v[i].s>>v[i].d>>v[i].c;
    	}
      	sort(v.begin(), v.end(),comp);
      	int *parent=new int[n];
      	int *size=new int[n];
      	for(int i=0;i<n;i++){
      		parent[i]=i;
      		size[i]=1;
      	}
      	int costr=0;
      	for(int i=0;i<m;i++)
      	{
      		if (v[i].c<ca)
      			unio(v[i].s,v[i].d,parent,size,costr,v[i].c);
      	}
      	int count=0;
      	for(int i=0;i<n;i++)
      	{
      		if (parent[i]==i)
      			count++;
      	}
      	cout<<"Case "<<"#"<<(k++)<<": "<<costr+count*ca<<" "<<count<<nl;
    }
	return 0;
}