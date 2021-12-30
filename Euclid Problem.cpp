#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#define ABS(x) x>=0? x:-x

vector<long long int> GCD_euclid(long long int i,long long int j){
	long long int r,a,b,s0=1,t0=0,s1=0,t1=1,rs,rt,qi;
	vector<long long int> ans;
	
	
	if(i>=j){a=j;b=i;}else{a=i;b=j;}
	r=b%a;

	while(r!=0){
		qi=(b-r)/a;
		rs=s0-qi*s1;
		s0=s1;s1=rs;
		rt=t0-qi*t1;
		t0=t1;t1=rt;
		b=a;a=r;
		r=b%a;	
	}
	
	long long int temp;
	
	if(i>=j){
		ans.push_back(s1);ans.push_back(t1);ans.push_back(a);
	}
	else{
		ans.push_back(t1);ans.push_back(s1);ans.push_back(a);
	}
	
	return ans;
}

int main(void){
	
	long long int a,b;
	
	while(cin>>a>>b){
		cout<<GCD_euclid(a,b)[0]<<" "<<GCD_euclid(a,b)[1]<<" "<<GCD_euclid(a,b)[2]<<endl;
	}
	
	
	return 0;
}