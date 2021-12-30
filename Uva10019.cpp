#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;



int sumOf_Dec2Binary(int num){
	int sum=0;
	
	while(num!=0){
		sum+=(num%2);
		num/=2;
	}
	
	
	return sum;
}

int sumOf_Hex2Binary(int num){
	int sum=0;

	
	while(num!=0){
		sum+=(sumOf_Dec2Binary(num%10));
		num/=10;
	}
	
	return sum;
}


int main(void){
	
	int N,M;
	
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>M;
		cout<<sumOf_Dec2Binary(M)<<" "<<sumOf_Hex2Binary(M)<<endl;
	}
	
	return 0;
}

