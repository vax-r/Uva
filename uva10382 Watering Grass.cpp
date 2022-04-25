#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool Pos_cmp(pair<double,double> &a,pair<double,double> &b){
    if(a.first==b.first)
        return a.second>b.second;
    else
        return a.first<b.first;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    double len,w,Radius,Pos;
    vector<pair<double,double>> v;
    // cin>>n>>len>>w;

    while(cin>>n){
        v.clear();
        cin>>len>>w;

        for(int i=0;i<n;i++){
            cin>>Pos;
            cin>>Radius;
            if(Radius>(w/2.0)){
                double dis=sqrt(Radius*Radius-(w*w/4.0));
                v.push_back({Pos-dis,Pos+dis});
            }
        }

        sort(v.begin(),v.end(),Pos_cmp);
        // cout<<"/////////////////\n";
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }

        int answer=0;
        double stand=0.0;

        for(int i=0;i<v.size();i++){
            if(v[i].first>stand)
                break;
            for(int j=i+1;j<v.size() && v[j].first<=stand;j++){
                if(v[j].second>v[i].second){
                    i=j;
                }
            }
            answer++;
            stand=v[i].second;
            if(stand>=len)
                break;
        }

        // cout<<"Answer is: ";
        if(stand<len)
            cout<<-1<<endl;
        else
            cout<<answer<<endl;
    }

    return 0;
}