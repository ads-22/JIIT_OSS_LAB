#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int>>> m;
    public:
    void addEdge(T u,T v,int dist,bool bidir=true){
        m[u].push_back(make_pair(v,dist));
        if(bidir)
            m[v].push_back(make_pair(u,dist));
    }
    void printAdj(){
        // iterate over all keys in the map
        for(auto j:m){
            cout<<j.first<<"->";
            for(auto l:j.second){
                cout<<'('<<l.first<<","<<l.second<<')';
            }
            cout<<endl;
        }
    }
    void dijsktraSSSP(T src){
        // We need distance array for every node.
        unordered_map<T,int> dist;
        // initial dist. will be INFINITY
        for(auto j:m){
            dist[j.first] = INT_MAX;
        }
        // make set to find min. dist
        set<pair<int,T>> s;
        dist[src] = 0;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            // find pair at the front
            auto p = *(s.begin());
            T node = p.second;
            int nodedist = p.first;
            s.erase(s.begin());
            // Iterate over nbrs of current node
            for(auto childpaigr:m[node]){
                if(nodedist+childpair.second<dist[childpair.first]){
                    // updation isn't posssible
                    T dest = childpair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        // node is found
                        s.erase(f);
                    }
                    // Insert new pair
                    dist[dest] = nodedist+childpair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        for(auto d:dist){
            cout<<d.first<<" is located at a distance of "<<d.second<<endl;
        }
    }
};

int main(){
    // Graph<int> g;
    // g.addEdge(1,2,1);
    // g.addEdge(1,3,4);
    // g.addEdge(2,3,1);
    // g.addEdge(3,4,1);
    // g.addEdge(1,4,7);
    // // g.printAdj();
    // g.dijsktraSSSP(1);

    Graph<string> india;
    india.addEdge("Amrister","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3);
    india.addEdge("Agra","Delhi",1);
    india.printAdj();
    india.dijsktraSSSP("Amritsar");
}