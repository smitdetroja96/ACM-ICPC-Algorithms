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

vector<ll> adj[100005];
bool visited[100005];
ll disc[100005];
ll low[100005];
ll parent[100005];
bool ver[100005];

void find(ll i)
{
    static ll time = 0;
    visited[i] = true;
    ll child = 0;

    disc[i] = low[i] = ++time;

    For(j,0,adj[i].size())
    {
        if(visited[adj[i][j]] == false)
        {
            child++;
            parent[adj[i][j]] = i;
            find(adj[i][j]);

            low[i] = min(low[i],low[adj[i][j]]);

            if (parent[i] == -1 && child > 1)
               ver[i] = true;

            if (parent[i] != -1 && low[adj[i][j]] >= disc[i])
               ver[i] = true;

        }
        else if (adj[i][j] != parent[i])
            low[i]  = min(low[i], disc[adj[i][j]]);
    }

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m;
    cin>>n>>m;

    ll u,v;

    For(i,0,m)
    {
        cin>>u>>v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    For(i,0,n)
    {
        visited[i] = false;
        parent[i] = -1;
        ver[i] = false;
    }

    For(i,0,n)
    {
        if(visited[i] == false)
        {
            find(i);
        }
    }

    cout<<"The cut vertices are : ";

    For(i,0,n)
    {
        if (ver[i] == true)
            cout<<i+1<<" ";
    }

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
