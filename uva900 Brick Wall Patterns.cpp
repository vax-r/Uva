#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define SIZE 51

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Block[SIZE];
    Block[1]=1;Block[2]=2;
    for(int i=3;i<=50;i++)
        Block[i]=Block[i-1]+Block[i-2];
    
    int n;
    while(cin>>n && n!=0){
        cout<<Block[n]<<endl;
    }

    return 0;
}