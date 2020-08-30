#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,out;
    stringstream ss;
    getline(cin,s);
    ss<<s;
    int x;
    while(ss>>out)
    {
        stringstream convert(out);
        convert>>x;
        cout<<x<<endl;
    }
    return 0;
}