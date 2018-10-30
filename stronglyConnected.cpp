//SMIT DETROJA
//201601113

#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <bits/stdc++.h>

#define mod 1000000007
#define ll long long

#define pi(x) printf("%lld ",x)

#define pline printf("\n")

#define For(i,a,b) for(ll i=a;i<b;i++)
#define RFor(i,a,b) Rfor(ll i=a;i>=b;i--)
#define deb(x) cout<<#x<<" : "<<x<<endl;
#define debug(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<endl;

#define pb push_back
#define mp make_pair
#define fir first
#define sec second

using namespace std;

ll choose(ll n,ll k);
bool isprime(ll n);
void setprime(bool isprime[],ll n);


vector<ll> a1[100005];
vector<ll> a2[100005];
bool visited[100005];

void dfs(ll i)
{
    visited[i] = true;

    For(j,0,a1[i].size())
    {
        if(visited[a1[i][j]] == false)
        {
            dfs(a1[i][j]);
        }
    }

}

void dfs2(ll i)
{
    visited[i] = true;

    For(j,0,a2[i].size())
    {
        if(visited[a2[i][j]] == false)
        {
            dfs(a2[i][j]);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m;
    cin>>n>>m;

    bool flag = 0;
    bool flag2 = 0;

    For(i,0,m)
    {
        ll u,v;
        cin>>u>>v;
        u--;
        v--;

        a1[u].pb(v);
        a2[v].pb(u);
    }

    For(i,0,n)
    {
        visited[i] = false;
    }

    dfs(0);

    For(i,0,n)
    {
        if(visited[i]==false)
        {
            flag = 1;
            break;
        }
    }

    For(i,0,n)
    {
        visited[i] = false;
    }

    dfs2(0);

    For(i,0,n)
    {
        if(visited[i]==false)
        {
            flag2 = 1;
            break;
        }
    }

    if(flag==0 ||  flag2==0)
        cout<<"The graph is strongly connected";
    else
        cout<<"Graph is not strongly connected";


    return 0;

}

ll choose(ll n,ll k)
{
    if(k==0)
        return 1;
    return (n* choose(n-1,k-1))/k;
}

bool isprime(ll n)
{
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}

void setprime(bool isprime[],ll n)
{
    For(i,0,n)
        isprime[i]=true;
        isprime[0]=false;
        isprime[1]=false;

    For(i,2,n)
    {
        for(ll j=2;i*j<n;j++)
            isprime[i*j]=false;
    }
}

