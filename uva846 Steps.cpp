#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>

#define MAX_SIZE 1000000001
 
using namespace std;

int main(void){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;cin>>n;
	long long int x,y,dis,t_len,t_step;
	
	while(n--){
		cin>>x>>y;
		dis=y-x;
		t_len=0;
		t_step=0;
		long long int step_size=1;
		bool solved=false;
		
		while(1){
			if(dis==0){
				cout<<0<<endl;
				solved=true;
				break;
			}
			
			if(dis==(t_len+2*step_size)){
				t_step+=2;
				cout<<t_step<<endl;
				solved=true;
				break;
			}
			else if(dis<(t_len+2*step_size)){
				break;
			}
			
			t_len+=2*step_size;
			t_step+=2;
			step_size++;
		}
		
		if(solved)
			continue;
		
		if(t_len+step_size<dis){
			t_step+=2;
		}
		else{
			t_step+=1;
		}
		cout<<t_step<<endl;
		
	}
	
	return 0;
}

