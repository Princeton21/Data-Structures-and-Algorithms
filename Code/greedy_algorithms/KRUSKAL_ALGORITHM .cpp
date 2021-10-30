
#include<bits/stdc++.h>
using namespace std;

int find(int a){
   if(a==parent[a])return a;
   return find(parent[a]);
}


int kruskal(vector<int>&edges){

  int cnt = 0;
  int i = 0;
  vector<vector<int>>res;
    
  while(cnt<v-1 and i<e){

    int x = find(edges[i][1]);
    int y = find(edges[i][2]);
    if(x!=y){
       res.push_back(edges[i]);
       union(x,y);                                 //DISJOINT SET UNION   
    } 
  }

  //KHATAM
}




int main(){

int v;cin>>v;                   //NO OF VERTICES
vector<int>edges;
int e;cin>>e;                   //NO OF EDGES

for(int i=0;i<n;i++){
  
   int s,e,w;cin>>s>>e>>w;
   edges.push_back({w,s,e});
}

sort(edges.begin(),edges.end());


return 0;
}
