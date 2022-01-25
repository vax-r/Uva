#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int mod;

bool cmp(int a,int b){
	
	if((a%mod)==(b%mod)){
		if(abs(a%2)!=abs(b%2)){
			return abs(a%2);
		}
		else{
			if(abs(a%2)){
				return a>b;
			}
			else{
				return a<b;
			}
		}
	}
	else{
		return a%mod < b%mod;
	}
}

int main(void){
	
	int n,m;
	int* inputs;
	
	
	while(cin>>n>>m){
		cout<<n<<" "<<m<<endl;
		if(n==0 && m==0)
			break;
			
		mod=m;
		inputs=new int[n];
		for(int i=0;i<n;i++){
			cin>>inputs[i];
		}
				
		sort(inputs,inputs+n,cmp);
		
		for(int i=0;i<n;i++){
			cout<<inputs[i]<<endl;
		}
		
		delete[] inputs;
	}
	
	return 0;
}

