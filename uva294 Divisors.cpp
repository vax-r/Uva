#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>

#define MAX_SIZE 1000000001
 
using namespace std;

int* prime_num;

int num_of_Divisor(int n){
	int sum=1,power;
	int bound=int(ceil(sqrt(n)));
	
	for(int i=2;i<=bound+1 && n!=1;i++){
		power=0;
		if(prime_num[i]){
			while(n%i==0){
				n/=i;
				power++;
			}
			sum*=(power+1);
		}
	}
	if(sum==1)
		sum=2;
	
	return sum;
}


int main(void){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int size=50000;
	prime_num=new int[size];
	memset(prime_num,1,sizeof(int)*size);
	
	//建立質數表
	prime_num[1]=0;
	for(int i=2;i<size;i++){
		if(prime_num[i]){
			for(int j=i+i;j<size;j+=i)
				prime_num[j]=0;
		}
	} 
	
	
	
	int N;cin>>N;
	int L,U,D,P;
	for(int i=0;i<N;i++){
		cin>>L>>U;
		D=0;
		int temp;
		for(int j=L;j<=U;j++){
			temp=num_of_Divisor(j);
			if(temp>D){
				P=j;
				D=temp;
			}
		}
		
		cout<<"Between "<<L<<" and "<<U<<", "<<P<<" has a maximum of "<<D<<" divisors."<<endl;
	}
	
	
	return 0;
}

