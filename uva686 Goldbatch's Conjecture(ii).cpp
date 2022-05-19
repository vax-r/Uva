#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define SIZE 33000

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bool Prime[SIZE];
    memset(Prime,true,sizeof(Prime));
    Prime[0]=false;Prime[1]=false;
    for(int i=2;i<SIZE;i++){
        if(Prime[i]){
            for(int j=i+i;j<SIZE;j+=i)
                Prime[j]=false;
        }
    }

    int Num,ans;
    while(cin>>Num && Num!=0){
        ans=0;
        if(Num%2==0 and Prime[Num/2])ans++;
        for(int i=2;i<(Num+1)/2;i++){
            if(Prime[i] && Prime[Num-i])ans++;
        }        
        cout<<ans<<endl;
    }

    return 0;
}