#include <iostream>
#include <string>
#include <cstring>
using namespace std;


bool LCS_check(string& s,string& t){
    if(s.length()>t.length())
        return false;
    if(s.length()==t.length()){
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i])
                return false;
        }
        return true;
    }

    bool CHECK;
    int** M=new int*[s.length()+1];
    for(int i=0;i<s.length()+1;i++)
        M[i]=new int[t.length()+1];
    M[0][0]=0;//init
    for(int i=1;i<t.length()+1;i++)
        M[0][i]=0;
    for(int i=1;i<s.length()+1;i++)
        M[i][0]=0;

    for(int i=1;i<s.length()+1;i++){
        for(int j=1;j<t.length()+1;j++){
            if(s[i-1]==t[j-1]){
                M[i][j]=M[i-1][j-1]+1;
            }
            else if(M[i-1][j]>=M[i][j-1]){
                M[i][j]=M[i-1][j];
            }
            else{
                M[i][j]=M[i][j-1];
            }
        }
    }

    if(s.length()==M[s.length()][t.length()])
        CHECK=true;
    else
        CHECK=false;

    for(int i=0;i<s.length()+1;i++)
        delete[] M[i];
    delete[] M;

    return CHECK;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s,t,input;
    bool blank;
    while(getline(cin,input) && input.length()!=0){
        s.clear();t.clear();
        blank=false;
        for(int i=0;i<input.length();i++){
            if(input[i]==' '){
                blank=true;
                continue;
            }
            if(!blank)
                s.push_back(input[i]);
            else
                t.push_back(input[i]);
        }
        if(LCS_check(s,t))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}
