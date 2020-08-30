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
#define czero(n)                    __builtin_popcountll(n) // count the number of 1's in the bit representation of a number
#define cenzero(n)                  __builtin_ctzll(n) // count the number of zereos from the end of the bit representation of a number until a 1
#define countbegzero(n)             __builtin_clzxll(n)
#define checkparity(n)              __builtin_parityll(n)// checks whether the number of bits are even or odd
#define pb                          push_back
#define eb                          emplace_back
#define mp                          make_pair
#define sp(x,y)                     fixed<<setprecision(y)<<x
#define vali                        valarray<int>
#define fastio()                    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mk(arr,n,type)              type *arr=new type[n]; // dynamic allocation of memory
#define del(arr)                    delete []arr;           // deletion of allocated memory
#define testcases(a)                int a; cin>>a; while(a--)
#define FORn(a,b,inc)               for(int i=a;i<b;i+=inc)
#define conscarr(A,n,x)             iota(A,A+n,x) 
#define ff 							first
#define ss 							second
#define vpi 						vector<pair<int,int>>
#define trace1(x)                   cerr<<#x<<": "<<x<<nl
#define trace2(x, y)                cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<nl
#define trace3(x, y, z)             cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<nl
#define trace4(a, b, c, d)          cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<nl
#define trace5(a, b, c, d, e)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<nl
#define trace6(a, b, c, d, e, f)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<nl  

mt19937                             rng(chrono::steady_clock::now().time_since_epoch().count());
// above line is the best random shuffler ;shuffle(arr,arr+n,rng) <- SYNTAX
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
inline void vect_input(vector<int>&v,int n){for(int i=0;i<n;i++){int input;cin>>input;v.pb(input);}}
inline int modulo(int a,int b){return (b+(a%b))%b;} 
inline int getascii(char ch){return (int)ch;}
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
void helper(int **A,int a,int b,int n,vector<bool> &visited)
{
    vi path(n);
    bool found=false;
    queue<int> q;
    q.push(a);
    visited[a]=true;
    while (!q.empty())
    {
        int x=q.front();
        if (x==b){
            found=true;
            break;
        }
        // cout<<x<<" "<<b<<nl;
        q.pop();
        for(int i=0;i<n;i++)
        {
            // trace1(A[x][i]);
            if (!visited[i] && A[x][i]==1)
            {
                visited[i]=true;
                path[i]=x;
                q.push(i);
            }
        }
    }
    if (found)
    {
        int i=b;
        while (i!=a)
        {
            cout<<i<<" ";
            i=path[i];
        }
        cout<<a;        
    }
    else
        return;
}
void path(int **A,int a,int b,int n)
{
    vector<bool> v(n,false);
    helper(A,a,b,n,v);
} 
int32_t main()  
{ 
    p_g_t();
    int V,E,tempX,tempY;
    cin>>V>>E;
    int **A=new int*[V];
    for(int i=0;i<V;i++)
    {
        A[i]=new int[V];
        for(int j=0;j<V;j++)
            A[i][j]=0;
    }
    for(int i=0;i<E;i++)
    {
        int x,y;
        cin>>x>>y;
        A[x][y]=1;
        A[y][x]=1;
    }
    cin>>tempX>>tempY;
    path(A,tempX,tempY,V);
    return 0;
}


       