#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<set>
#include<map>
#include<queue>
#include<stack>

//Required Headers
using namespace std;

#define nl                          '\n'
#define int                         long long
#define vi                          vector<int>
#define pi                          pair<int,int>
#define vpi                         vector<pi> 
#define czero(n)                    __builtin_popcountll(n) // count the number of 1's in the bit representation of a number
#define cenzero(n)                  __builtin_ctzll(n) // count the number of zereos from the end of the bit representation of a number until a 1
#define countbegzero(n)             __builtin_clzxll(n)
#define checkparity(n)              __builtin_parityll(n)// checks whether the number of bits are even or odd
#define pb                          push_back
#define eb                          emplace_back
#define mp                          make_pair
#define sp(x,y)                     fixed<<setprecision(y)<<x
#define vali                        valAay<int>
#define fastio()                    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mk(A,n,type)                type *A=new type[n]; // dynamic allocation of memory
#define del(A)                      delete []A;           // deletion of allocated memory
#define testcases(a)                int a; cin>>a; while(a--)
#define FORn(a,b,inc)               for(int i=a;i<b;i+=inc)
#define conscA(A,n,x)               iota(A,A+n,x) 
#define trace1(x)                   cerr<<#x<<": "<<x<<nl
#define trace2(x, y)                cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<nl
#define trace3(x, y, z)             cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<nl
#define trace4(a, b, c, d)          cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<nl
#define trace5(a, b, c, d, e)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<nl
#define trace6(a, b, c, d, e, f)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<nl  

mt19937                             rng(chrono::steady_clock::now().time_since_epoch().count());
// above line is the best random sh.firstler ;sh.firstle(A,A+n,rng) <- SYNTAX
const int MOD=1000000007;
const int inf=1e18;
const int MOD_1=998244353;

/**************************************************************************************************************/
inline int gcd(int a,int b) {if (a==0) return b; else return gcd(b%a,a);}
inline void take_input(int A[],int n){for(int i=0;i<n;i++){ cin>>A[i];}}
inline void show(int *A,int n){for(int i=0;i<n;i++){cout<<A[i]<<" ";}cout<<nl;}
inline int countDivisibles(int a,int b,int c){if (a%c==0){return (b/c-a/c+1);} return (b/c-a/c);}
inline bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); } 
inline bool sortbysecdesc(const pair<int,int> &a, const pair<int,int> &b) { return (a.second > b.second); }
inline void swap(int &a,int &b){int temp=a;a=b;b=temp;} 
inline void initialise(int A[],int n,int k){for(int i=0;i<n;i++){A[i]=k;}}
inline int modulo(int a,int b){return (b+(a%b))%b;} 
template<typename T>
void show_vect(vector<T> v){for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<nl;}
template<typename T>
void vect_input(vector<T>&v,int n){for(int i=0;i<n;i++){T input;cin>>input;v.pb(input);}}
/****************************************************************************************************************/

typedef unsigned long long ull;
// *-------------------------------------------------------------
void p_g_t()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
    freopen("error.in","w",stderr);
    #endif
}
//essentials||  
//main code........ 
// Driver Code
void build(int *A,int *tree,int start,int end,int tn)
{
    if (start==end)
    {
        tree[tn]=A[start];
        return;
    }
    int mid=(start+end)/2;
    build(A,tree,start,mid,2*tn);
    build(A,tree,mid+1,end,2*tn+1);
    tree[tn]=tree[2*tn]+tree[2*tn+1];
}
void update(int *A,int *tree,int start,int end,int tn,int idx,int val)
{
    if (start==end)
    {
        A[idx]=val;
        tree[tn]=val;
        return;
    }
    int mid=(start+end)/2;
    if (idx>mid)
    {
        update(A,tree,mid+1,end,2*tn+1,idx,val);
    }
    else
    {
        update(A,tree,start,mid,2*tn,idx,val);
    }
    tree[tn]=tree[2*tn]+tree[2*tn+1];
}
int query(int *tree,int start,int end,int tn,int l,int r)
{
    if (start>r || end<l)
        return 0;
    if (start>=l && end<=r)
        return tree[tn];
    int mid=(start+end)/2;
    int ans1=query(tree,start,mid,2*tn,l,r);
    int ans2=query(tree,mid+1,end,2*tn+1,l,r);
    return ans1+ans2;
}
int32_t main() 
{ 
    p_g_t();
    int A[]={1,2,3,4,5,6,7,8,9};
    mk(tree,18,int);
    build(A,tree,0,8,1);
    update(A,tree,0,8,1,2,4);
    tree[0]=-1;
    show(tree,18);
    cout<<query(tree,0,8,1,1,5);
    return 0;
}


        