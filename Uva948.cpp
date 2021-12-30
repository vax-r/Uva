#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int main(void){
	//define Fib numbers
	long long int LEN=1e8;
	bool *Fib=new bool[LEN];
	memset(Fib,false,LEN);
	Fib[0]=true;Fib[1]=true;Fib[2]=true;
	
	long long int i=1,j=2,k=i+j;
	while(k<LEN){
		Fib[k]=true;
		i=j;
		j=k;
		k=i+j;
	}

	
	long long int N;cin>>N;
	long long int num,sum=0,temp,shrink;
	bool Found=false;
	vector<long long int> Fib_base;
	Fib_base.clear();
	
	for(long long int i=0;i<N;i++){
		cin>>num;
		temp=num;
		sum=0;
		Found=false;
		Fib_base.clear();
		
		while(sum!=num){
			
			while(temp>0 && !Found){
				if(Fib[temp]){
					sum+=temp;
					Fib_base.push_back(temp);
				}
				if(sum>num){
					sum-=temp;
					Fib_base.pop_back();
				}
				if(sum==num)
					Found=true;
				temp--;
			}
			if(!Found){
				temp=Fib_base.front()-1;
				Fib_base.clear();
				sum=0;
			}
			
		}
		
		long long int start;
		
		if(Found){
			reverse(Fib_base.begin(),Fib_base.end());
			cout<<num<<" = "<<1;
			start=Fib_base.back()-1;
			Fib_base.pop_back();
			for(long long int j=start;j>0;j--){
				if(Fib_base.back()==j){
					cout<<1;
					Fib_base.pop_back();
				}
				else if(Fib[j])
					cout<<0;
			}
			cout<<" (fib)"<<endl;
		}
		
		
		
	}
	
	return 0;
}
