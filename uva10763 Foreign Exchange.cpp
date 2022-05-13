#include <iostream>
#include <map>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long int n,local,foreign,ans;
    while(cin>>n && n!=0){
        ans=0;
        map<pair<int,int>,int> Exchange;
        Exchange.clear();
        for(int i=0;i<n;i++){
            cin>>local>>foreign;
            Exchange[{local,foreign}]++;
        }

        for(auto &s:Exchange){
            pair<int,int> p=s.first;
            if(Exchange[{p.second,p.first}]==s.second)
                ans+=s.second;
        }
        if(ans==n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }

    return 0;
}