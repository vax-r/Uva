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
	
	int T;cin>>T;
	int n,high,max;
	int* stu_score;
	
	while(T--){
		cin>>n;
		stu_score=new int[n];
		for(int i=0;i<n;i++)
			cin>>stu_score[i];
		
		high=stu_score[0];
		max=stu_score[0]-stu_score[1];
		
		for(int i=1;i<n;i++){
			if(high-stu_score[i]>max){
				max=high-stu_score[i];
			}
			if(stu_score[i]>high){
				high=stu_score[i];
			}
		}
		cout<<max<<endl;
		
		delete[] stu_score;
	}
	
	return 0;
}

