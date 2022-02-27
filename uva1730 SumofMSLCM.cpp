#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>

#define SIZE 20000001

using namespace std;




inline long long int Get_MSLCM(long long int N){
	
	long long int times,l_num,r_num;
	
	long long int i=1,total=0,local_sum;
	
	while(i<=N){
		local_sum=0;
		
		times=N/i;
		l_num=i;
		r_num=N/times;
		local_sum=(l_num+r_num)*(r_num-l_num+1)/2;
		total+=local_sum*times;
		
		if(l_num==r_num)
			i++;
		else
			i=r_num+1;
	}
	
	total-=1;
	
	return total;
	
}

int main(void){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long int N;
	
	while(cin>>N && N!=0){	
		cout<<Get_MSLCM(N)<<endl;
	}
	
	return 0;
}

