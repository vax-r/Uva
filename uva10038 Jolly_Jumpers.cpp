#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <memory.h>
using namespace std;

int main(void){
	
	int* contain;
	int* inputs;
	int n, diff;
	bool Jolly;
	
	while(cin>>n){
		Jolly=true;
		contain = new int[n];
		memset(contain,0,sizeof(int)*n);
		
		inputs = new int[n];
		for(int i=0;i<n;i++)
			cin>>inputs[i];
		
		for(int i=1;i<n;i++){
			diff=abs(inputs[i]-inputs[i-1]);
			if(diff>=1 && diff<n && contain[diff]==0){
				contain[diff]=1;
			}
			else{
				Jolly=false;break;
			}
		}
		
		if(Jolly){
			cout<<"Jolly"<<endl;
		}
		else{
			cout<<"Not jolly"<<endl;
		}
		
		delete[] contain;
		delete[] inputs;
	}
	
	return 0;
}

