#include <iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

//DFS to find articulations point
void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool>&vis,
unordered_map<int, list<int>> &adjc, vector<int> &ap, int &timer)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for(auto neighbour: adjc[node])
    {
        if (neighbour == parent)
        {
            continue;
        }
        if (!vis[neighbour])
        {
            dfs(neighbour, node, disc, low, vis, adjc, ap, timer);
            low[node] = min(low[node], low[neighbour]);
            //check for articluation point
            if(low[neighbour] >= disc[node] && parent != -1)
            {
                ap[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], disc[neighbour]);
        }
    }
    if(parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}

int main()
{
    //create undirected weighted graph
    int n = 5;
    int e= 5;
    vector<pair<int,int>>edges;
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(0,2));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(1,2));
    edges.push_back(make_pair(4,3));

    unordered_map<int, list<int>> adjc;
    for(int i =0; i <edges.size(); i++)
    {
        int u  = edges[i].first;
        int v = edges[i].second;
        adjc[u].push_back(v);
        adjc[v].push_back(u);
    }

    //requaired datastructures
    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    int parent = -1;
    unordered_map<int,bool> vis;
    vector<int> articulation_p(n,0);


    //initialize discovery and low as -1
    for(int i =0 ; i < n;i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    //Now start DFS
    for( int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i, parent, disc, low, vis, adjc, articulation_p, timer);
        }
    }

    //print articluation point
    cout<<"Articlulation Time is as Follow: "<< endl;
    for (int i = 0; i < n; i++)
    {
        if(articulation_p[i] != 0)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}