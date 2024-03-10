#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
Q2.  Given a directed acyclic graph G with N vertices and M edges. The task is
 to find the length of the longest path in Graph.
*/

void dfs(int u, vector<int> g[], bool vis[], int dp[])
{
    vis[u] = 1;
    for (auto child : g[u])
    {
        if (!vis[child])
            dfs(child, g, vis, dp);
        dp[u] = max(dp[u], 1 + dp[child]);
    }
}

void addEdge(vector<int> g[], int u, int v)
{
    g[u].push_back(v);
}

int main()
{
    freopen("input.txt","r",stdin);
    int n, e;
    cin >> n >> e;
    vector<int> g[n+1];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(g ,u, v);
    }
    bool vis[n+1] = {0};
    int dp[n+1] = {-1};
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i, g, vis, dp);
    }
 
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout<<ans;

    return 0;
}
