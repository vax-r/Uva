#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

#define SIZE 201
vector<int> Adj_list[SIZE];

bool BiColored(int& num_of_vertex){
    queue<int> Q;
    bool* Visit=new bool[num_of_vertex];
    int* depth=new int[num_of_vertex];
    memset(Visit,false,sizeof(bool)*num_of_vertex);

    int root=0,cur_vertex,child_v;
    depth[root]=1;
    Visit[root]=true;
    Q.push(root);
    while(!Q.empty()){
        cur_vertex=Q.front();
        Q.pop();
        for(int i=0;i<Adj_list[cur_vertex].size();i++){
            child_v=Adj_list[cur_vertex][i];
            if(!Visit[child_v]){
                depth[child_v]=depth[cur_vertex]+1;
                Visit[child_v]=true;
                Q.push(child_v);
            }
            else if(Visit[child_v] && depth[child_v]==depth[cur_vertex]){
                return false;
            }
        }
    }    
    
    delete[] Visit;
    delete[] depth;
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,l,head,tail;

    while(cin>>n && n!=0){
        for(int i=0;i<SIZE;i++)
            Adj_list[i].clear();
        cin>>l;
        for(int i=0;i<l;i++){
            cin>>head>>tail;
            Adj_list[head].push_back(tail);
            Adj_list[tail].push_back(head);
        }
        if(BiColored(n))
            cout<<"BICOLORABLE."<<endl;
        else
            cout<<"NOT BICOLORABLE."<<endl;

    }




    return 0;
}