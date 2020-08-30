#include <bits/stdc++.h>
#include<sys/time.h>
using namespace std;
#define nl 					'\n'
#define int 				long long
#define vi 					vector<int>
#define iter 				vector<int>::iterator
#define czero(n) 			__builtin_popcountll(n) // count the number of 1's in the bit representation of a number
#define cenzero(n) 			__builtin_ctzll(n) // count the number of zereos from the end of the bit representation of a number until a 1
#define pb 					push_back
#define mp					make_pair
#define ps(x,y) 			fixed<<setprecision(y)<<x
#define vali 				valarray<int>
#define fastio() 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 				1000000007 
#define inf 				1e18
#define mk(arr,n,type)  	type *arr=new type[n]; // dynamic allocation of memory
#define del(arr)			delete []arr;			// deletion of allocated memory
#define testcases(a) 		int a; cin>>a; while(a--)
#define rev					greater<int>()
#define conscarr(A,n,x)		iota(A,A+n,x)	
mt19937         			rng(chrono::steady_clock::now().time_since_epoch().count());
// above line is the best random shuffler ;shuffle(arr,arr+n,rng) <- SYNTAX
int gcd(int a,int b) {if (a==0) return b; else return gcd(b%a,a);}
inline void take_input(int A[],int n){for(int i=0;i<n;i++){ cin>>A[i];}}
inline void show(int A[],int n){for(int i=0;i<n;i++){cout<<A[i]<<" ";}cout<<nl;}
inline void vect_input(vi &v,int n){int input;for(int i=0;i<n;i++){cin>>input;v.pb(input);}}
inline void show_vect(vi v){for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<nl;}

/****************************************/
// int gettimeinmicroseconds(){struct timeval start; gettimeofday(&start ,NULL); return start.tv_sec*1000000+start.tv_usec;}
/****************************************/
typedef unsigned long long ull;
// *-------------------------------------------------------------*
void p_g_t()
{
	fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
    #endif
}
int sub(string str,string output[])
{
	if (str.empty())
	{
		output[0]="";
		return 1;
	}
	int smalloutput=sub(str.substr(1),output);
	for(int i=0;i<smalloutput;i++)
	{
		output[i+smalloutput]=str[0]+output[i];
	}
	return 2*smalloutput;
}
int32_t main() 
{ 
	p_g_t();
	string S;
	cin>>S;
	string S_1[1000];
	int x=sub(S,S_1);
	for(int i=0;i<x;i++)
	{
		cout<<S_1[i]<<nl;
	}
	return 0; 
} 
