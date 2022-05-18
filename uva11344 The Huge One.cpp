#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;cin>>N;
    string M;
    int s_num,rem,cases;
    string S;
    bool Wonderful;
    while(N--){
        M.clear();S.clear();
        cin>>M;
        Wonderful=true;
        cin>>cases;
        while(cases--){
            cin>>s_num;
            if(!Wonderful)
                continue;
            rem=0;
            for(int j=0;j<M.length();j++)
                rem=(rem*10+M[j]-'0')%s_num;
            if(rem!=0){
                Wonderful=false;
            }
        }
        if(Wonderful)
            cout<<M<<" - Wonderful."<<endl;
        else
            cout<<M<<" - Simple."<<endl;
    }

    return 0;
}