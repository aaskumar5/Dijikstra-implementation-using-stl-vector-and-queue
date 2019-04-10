//https://www.spoj.com/problems/EZDIJKST/
//This question is direct implementation of Dijikstra

#include<bits/stdc++.h>
using namespace std;
int v,k,x,y,w,s,e,c;
void Dijikstra(vector<pair<int,int>> g[],vector<int> & dist)
{
    vector<bool> visit(v+1,false);
    //for better understanding of next line https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> >  pq;  //greater will create min heap with respect to first element of pair
    pq.push({dist[s]=0,s}); //as greater function sort using first element so keep first one as distance
    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        pq.pop();
        visit[p.second]=1;
        for(auto i : g[p.second])
        {
            if(!visit[i.first] && p.first+i.second<dist[i.first] )
            {
                pq.push({dist[i.first]=p.first+i.second,i.first});
            }
        }
    }

}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin>>t;
    while(t--)
    {
         cin>>v>>k;
        vector<pair<int,int>> g[v+1];
        vector<int> dist(v+1,INT_MAX);
        for(int i=0;i<k;++i)
        {
            cin>>x>>y>>c;
            g[x].push_back({y,c});
        }
        cin>>s>>e;
        Dijikstra(g,dist);
        dist[e]<INT_MAX ? cout<<dist[e]<<'\n' : cout<<"NO\n";

    }
}
