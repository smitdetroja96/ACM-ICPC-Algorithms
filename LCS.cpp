#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <stdio.h>
#include <bits/stdc++.h>

#define For(i,x,n)  for(ll i=x;i<n;i++)


typedef long long ll;

using namespace std;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);


	string a,b;
	ll n,m;


	cin>>a>>b;

	n = a.size();
	m = b.size();

	ll p[n+1][m+1];

	for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                p[i][j]=0;

            else if(a[i-1] == b[j-1])
                p[i][j] = p[i-1][j-1] + 1;

            else
                p[i][j] = max(p[i][j-1],p[i-1][j]);
        }
    }

    For(i,0,n)
    {
        For(j,0,m)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }

    ll ans = p[n][m];
    vector <char> z;

    ll i=n;
    ll j=m;

    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            z.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(p[i-1][j] > p[i][j-1])
            i--;
        else
            j--;
    }

    for(ll i=z.size()-1;i>=0;i--)
        cout<<z[i];

	return 0;
}






