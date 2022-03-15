#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int len1,len2;

int CmpChar(char& a,char& b){
	if(a==b)
		return 0;
	else
		return 1;
}

int Min_of3(int& a,int& b,int& c){
	int min=a;
	if(min>b)
		min=b;
	if(min>c)
		min=c;
	return min;
}

int Transform(string X,string Y){
	int C[len1+1][len2+1];
	memset(C,0,sizeof(C));
	C[0][0]=0;
	
	for(int i=1;i<len2+1;i++)
		C[0][i]=i;	
	for(int i=1;i<len1+1;i++)
		C[i][0]=i;
	
	
	int add_bj,delete_ai,trans;
	for(int i=1;i<len1+1;i++){
		for(int j=1;j<len2+1;j++){
			add_bj=C[i][j-1]+1;
			delete_ai=C[i-1][j]+1;
			trans=C[i-1][j-1]+CmpChar(X[i-1],Y[j-1]);
			C[i][j]=Min_of3(add_bj,delete_ai,trans);
		}
	}
	
	return C[len1][len2];	
}


int main(void){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string X,Y;
	
	while(cin>>len1 && cin>>X){
		cin>>len2;
		cin>>Y;
		
		cout<<Transform(X,Y)<<endl;		
		
		X.clear();
		Y.clear();
	}
	
	
	
	return 0;
}

