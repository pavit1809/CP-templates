#include <bits/stdc++.h>
#include<chrono>

using namespace std;
using namespace chrono;

#define nl                          '\n'
#define int                         long long
int expo(int a, int b) {int res = 1; while (b > 0) {if (b & 1)res = (res * a); a = (a * a) ; b = b >> 1;} return res;}
bool isPrime(int n) {if (n <= 1) {return false;} if (n <= 3) {return true;} if (n % 2 == 0 || n % 3 == 0) {return false;} for (int i = 5; i * i <= n; i = i + 6) {if (n % i == 0 || n % (i + 2) == 0) {return false; }} return true;}
mt19937                             rng(chrono::steady_clock::now().time_since_epoch().count());

int brute(vector<int> &A, int n, int k, int start, int height1, int height2, int ***dp)
{
    if (height2 >= k && height1 >= k)
        return 0;
    if (start >= n)
        return INT_MAX;
    if (dp[start][height1][height2] != -1)
        return dp[start][height1][height2];
    int bestans = INT_MAX;
    int skip = brute(A, n, k, start + 1, height1, height2, dp);
    bestans = min(bestans, skip);
    if (height1 + A[start] >= k && height1 < k)
    {
        bestans = min(bestans, 1 + brute(A, n, k, start + 1, k, height2, dp));
    }
    if (height1 + A[start] < k && height1 < k)
    {
        bestans = min(bestans, 1 + brute(A, n, k, start + 1, height1 + A[start], height2, dp));
    }
    if (height2 + A[start] >= k && height2 < k)
    {
        bestans = min(bestans, 1 + brute(A, n, k, start + 1, height1, k, dp));
    }
    if (height2 + A[start] < k && height2 < k)
    {
        bestans = min(bestans, 1 + brute(A, n, k, start + 1, height1, height2 + A[start], dp));
    }
    return dp[start][height1][height2] = bestans;
}
int perfectsol(vector<int> &A, int n, int k)
{
    int ***dp = new int**[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int*[k + 1];
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = new int[k + 1];
            for (int w = 0; w <= k; w++)
            {
                dp[i][j][w] = -1;
            }
        }
    }
    int ans = brute(A, n, k, 0, 0, 0, dp);
    return ((ans > n) ? -1 : ans);
}
bool checker(vector<int> A,int desiredsize,int k)
{
    if (desiredsize < 2)
        return false;
    A.resize(desiredsize);
    reverse(A.begin(), A.end());
    int sum1 = A[desiredsize - 1],sum2=0;
    A.pop_back(); 
    //giving the least to sum1;
    while (sum1 < k && A.size() > 0)
    {
        int req = k - sum1;
        auto it = lower_bound(A.begin(), A.end(), req);
        if (it == A.end())
        {
            sum1 += (A.back());
            A.pop_back();
        }
        else
        {
            sum1 += (*it);
            A.erase(it);
        }
    }
    while (sum2 < k && A.size() > 0)
    {
        int req = k - sum2;
        auto it = lower_bound(A.begin(), A.end(), req);
        if (it == A.end())
        {
            sum2 += (A.back());
            A.pop_back();
        }
        else
        {
            sum2 += (*it);
            A.erase(it);
        }
    }
    return (sum1 >= k && sum2 >= k);
}
int mysol(vector<int> A, int n, int k)
{
    sort(A.begin(), A.end(), greater<int>());
    int l = 1, r = n;
    int ans = n + 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (checker(A, mid, k))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ((ans == n + 1) ? -1 : ans);
}
int32_t main()
{
    int t = 1000;
    while (t--)
    {
        int n = rng() % 100;
        if (n == 0)
            n = 1;
        int k = rng() % 100;
        if (k == 0)
            k = 1;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            A[i] = 1 + rng() % (1+rng()%50);
        }
        int myans = mysol(A, n, k);
        int perfectans = perfectsol(A, n, k);
        if (myans == perfectans)
        {
            cout << "matching..." << nl;
            // cout<<"n->"<<n<<nl;
            // cout<<"k->"<<k<<nl;
            // cout<<"Your answer->"<<myans<<nl;
            // cout<<"Correct answer->"<<perfectans<<nl;
            // cout << "Your answer->" << myans << nl;
            // cout << "Correct answer->" << perfectans << nl;
        }
        else
        {
            cout << "Not matching..." << nl;
            cout << "Tescase failed:" << nl;
            cout << "n->" << n << nl;
            cout << "k->" << k << nl;
            cout << "Array is->" << nl;
            sort(A.begin(), A.end());
            for (auto x : A) {
                cout << x << " ";
            }
            cout << nl;
            cout << "Your answer->" << myans << nl;
            cout << "Correct answer->" << perfectans << nl;
            t = 0;
            exit(0);
        }
    }
    return 0;
}