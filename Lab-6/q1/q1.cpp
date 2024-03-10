#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
Q1. Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find
 Topological Sorting of that Graph.
*/

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v);
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
void Graph::topologicalSort()
{
    vector<int> indegree(V, 0);
    for (int u = 0; u < V; u++)
    {
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            indegree[*it]++;
        }
    }
    queue<int> q;
    for (int u = 0; u < V; u++)
    {
        if (indegree[u] == 0)
        {
            q.push(u);
        }
    }

    while (!q.empty())
    {
        int tmp = q.front();
        cout << tmp << " ";
        q.pop();
        for (auto it = adj[tmp].begin(); it != adj[tmp].end(); it++)
        {
            indegree[*it]--;
            if (indegree[*it] == 0)
            {
                q.push(*it);
            }
        }
    }
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    /*
    Time complexity:
    It takes O(V) for calculating indegree and the while loop takes O(E) so overall time complxity:O(V+E)
    Space complexity:
    queue stores all vertices of graph. So O(V).
    */

    return 0;
}
