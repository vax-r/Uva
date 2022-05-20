#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#define SIZE 50000

bool cmp(int& a,int& b){
    return a<b;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T,S,A,F;
    int x[SIZE],y[SIZE];
    cin>>T;
    while(T--){
        cin>>S>>A>>F;
        for(int i=0;i<F;i++)
            cin>>x[i]>>y[i];
        sort(x,x+F,cmp);
        sort(y,y+F,cmp);
        cout<<"(Street: "<<x[(F-1)/2]<<", Avenue: "<<y[(F-1)/2]<<")"<<endl;

    }

    return 0;
}