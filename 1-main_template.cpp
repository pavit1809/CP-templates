/*
	Developer:Pavitra Goyal
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<chrono>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds; 

#define nl                          '\n'
#define int                         long long
#define vi                          vector<int>
#define pi                          pair<int,int>
#define czero(n)                    __builtin_popcountll(n) // count the number of 1's in the bit representation of a number
#define cenzero(n)                  __builtin_ctzll(n) // count the number of zereos from the end of the bit representation of a number until a 1
#define countbegzero(n)             __builtin_clzxll(n)
#define checkparity(n)              __builtin_parityll(n)// checks whether the number of bits are even or odd
#define pb                          push_back
#define mp                          make_pair
#define sp(x,y)                     fixed<<setprecision(y)<<x
#define fastio()                    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mk(arr,n,type)              type *arr=new type[n]; // dynamic allocation of memory
#define del(arr)                    delete []arr;           // deletion of allocated memory
#define testcases(a)                int a; cin>>a; while(a--)
#define FORn(a,b,inc)               for(int i=a;i<b;i+=inc)
#define conscarr(A,n,x)             iota(A,A+n,x) 
#define ff                          first
#define ss                          second
#define vpi                         vector<pair<int,int>>
#define vpd	                    	vector<pair<double,double>>
#define gcd(a,b)					__gcd(a,b);
#define lcm(a,b)					(a/gcd(a,b))*b;
#define trace1(x)                   cerr<<#x<<": "<<x<<nl
#define trace2(x, y)                cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<nl
#define trace3(x, y, z)             cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<nl
#define trace4(a, b, c, d)          cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<nl
#define trace5(a, b, c, d, e)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<nl
#define trace6(a, b, c, d, e, f)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<nl  

mt19937                             rng(chrono::steady_clock::now().time_since_epoch().count());
// above line is the best random shuffler ;shuffle(arr,arr+n,rng) <- SYNTAX

/**************************************************************************************************************/
int spf[1000001];
inline int read(){int val = 0; char ch;for(ch = getchar(); ch<'0' || ch>'9'; ch = getchar());for(; ch>='0' and ch<='9'; ch = getchar()) val = val*10 + ch - '0';return val;}
inline void take_input(int A[],int n){for(int i=0;i<n;i++){ cin>>A[i];}}
inline void show(int *A,int n){for(int i=0;i<n;i++){cout<<A[i]<<" ";}cout<<nl;}
inline int countDivisibles(int a,int b,int c){if (a%c==0){return (b/c-a/c+1);} return (b/c-a/c);}
inline bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); } 
inline bool sortbysecdesc(const pair<int,int> &a, const pair<int,int> &b) { return (a.second > b.second); } 
inline void swap(int &a,int &b){int temp=a;a=b;b=temp;}
inline void init1d(int *A,int n,int x){for(int i=0;i<n;i++){A[i]=x;} return;}
inline string getstr(int n){ostringstream ss;ss<<n; string res=ss.str();return res;}
inline int modulo(int a,int b){return (b+(a%b))%b;} 
inline int getascii(char ch){return (int)ch;}
int expo(int n,int x){int ans=1;while (x>0){if (x&1){ans*=n;} x=x>>1; n=n*n;} return ans;}
int expo(int a, int b, int mod){int res=1; while(b>0){if (b&1)res=(res*a)%mod;a=(a*a)%mod;b=b>>1;} return res;}
int expo(int a,int b,int c,int mod){return expo(a,expo(b,c,mod-1),mod);}
int nCr(int n,int r){int ans=1;if (n-r<r){r=n-r;}for(int i=0;i<r;i++){ans*=(n-i);ans/=(i+1);} return ans;}
void smallpf(int n=1000001){init1d(spf,1000001,0);spf[1]=0;for(int i=2;i<=1000000;i++){if (spf[i]==0){spf[i]=i;for(int j=2*i;j<=1000000;j+=i){if (spf[j]==0){spf[j]=i;}}}}}
vi sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
vi pfs(int n){vi ans;while (n>1){ans.pb(spf[n]);n=n/spf[n];}ans.pb(1);return ans;}
int gcdext(int a,int b,int *x,int *y){if (a==0){*x=0,*y=1;return b;}int x1,y1;int gcd=gcdext(b%a,a,&x1,&y1);*x=y1-(b/a)*x1;*y=x1;return gcd;}
int modinv(int b,int m){int x,y;int g=gcdext(b,m,&x,&y);if (g!=-1){return -1;}return (x%m+m)%m;}
int moddiv(int a,int b,int m){a=a%m;int inv=modinv(b,m);return (inv*a)%m;}
template<typename T>
void show_vect(vector<T> v){for(int i=0;i<v.size()-1;i++){cout<<v[i]<<" ";}cout<<v[v.size()-1];cout<<nl;}
template<typename T>
void debug_vect(vector<T> v){for(int i=0;i<v.size();i++){cerr<<v[i]<<" ";}cerr<<nl;}
template<typename T>
void vect_input(vector<T>&v,T n){for(int i=0;i<n;i++){cin>>v[i];}}
template<typename T>
void show_set(set<T> s){for(auto x:s){cout<<x<<" ";}cout<<nl;}

/****************************************************************************************************************/

typedef unsigned long long ull;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pdbs; 
const int rownbr[8]={-1,-1,-1,0,0,1,1,1};
const int colnbr[8]={-1,0,1,-1,1,-1,0,1};
const int rownbr1[4]={1,-1,0,0}; 
const int colnbr1[8]={0,0,1,-1}; 
const int MOD=1000000007;
const int inf=1e18;
const int MOD_1=998244353;
const double PI=3.141592653589793238;
// *-------------------------------------------------------------
void p_g_t()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.in", " r", stdin);
    freopen("output.in", "w", stdout);
    freopen("error.in","w",stderr);
    #endif
} 		 		
// Driver Code
void solve()
{
	return;
}	 	 	
int32_t main() 
{ 	
    p_g_t();
    int t=1;
    //take input iff there are multiple tcs 
    cin>>t;
    while (t--)
    {
    	solve();
    }
    cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}  
