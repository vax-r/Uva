#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define SIZE 101

int Joseph_Problem_DP(const int n,int& m){
    int Pos[n+1];
    Pos[1]=1;
    for(int i=2;i<=n;i++)
        Pos[i]=(Pos[i-1]+(m-1))%i + 1;

    return Pos[n];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool Turn_off[SIZE],Done;

    int N,m;
    bool find;
    while(cin>>N && N!=0){
        if(N==13)
            m=1;
        else{
            m=2;
            while(Joseph_Problem_DP(N-1,m)!=12)m++;
        }

        cout<<m<<endl;
    }
    return 0;
}