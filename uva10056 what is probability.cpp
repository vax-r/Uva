#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int S;cin>>S;
	double n,I,round;
	double p;
	
	while(S--){
		cin>>n>>p>>I;
		double q=1-p;
		
		if(p==0)
			cout<<"0.0000";
		else
			printf("%.4f",(pow(q,I-1)*p)/(1-pow(q,n)));
		cout<<endl;
	}
	
	return 0;
}

