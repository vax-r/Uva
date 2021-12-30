#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

long long int sum_of_digits(long long int num){
	long long int sum=0;
	
	while(num!=0){
		sum+=(num%10);
		num/=10;
	}
	return sum;
}


int main(void){
	
	long long int a,n,sum1=0,sum2=0,smith_num,len;
	
	bool prime_num[50000]={true,true,false};
	for(int i=2;i<50000;i++){
		if(!prime_num[i]){
			for(int j=i+i;j<50000;j+=i){
				prime_num[j]=true;
			}
		}
	}
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>a;
		smith_num=a+1;
		len=smith_num;
		sum1=0;sum2=0;
		
		while(true){
			sum1=sum_of_digits(smith_num);
			sum2=0;
			int sqrt_len=(int)(sqrt(len)+1e-9);
			
			for(int j=2;j<=sqrt_len && smith_num>1;j++){
				if(!prime_num[j]){
					while(smith_num%j==0){
						if(j>=10)
							sum2+=sum_of_digits(j);
						else
							sum2+=j;
						smith_num/=j;
					}
				}
			}
			
			if(smith_num!=len && smith_num>1){
				sum2+=sum_of_digits(smith_num);
			}
			if(sum1==sum2)
				break;
			else
				smith_num=++len;
			
		}
		cout<<len<<endl;
	}
	
	return 0;
}
