#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <string>
using namespace std;

int main(void){
	
	string s[100];
	int i;
	for(i=0;i<100;i++)
		s[i].clear();
	
	
	int str_num=0,max_len=0;
	i=0;
	
	while(getline(cin,s[i])){
		++i;
	}
	str_num=i;
	
	i=0;
	max_len=s[0].length();
	while(!s[i].empty()){
		if(max_len<s[i].length()){
			max_len=s[i].length();
		}
		++i;
	}
	
	i=0;
	bool print=false;
	while(i<max_len){
		print=false;
		for(int j=str_num-1;j>=0;j--){
			if(i<s[j].length()){
				cout<<s[j][i];
				print=true;
			}
			if(i>=s[j].length() && !print){
				cout<<' ';
			}
		}
		cout<<endl;
		++i;
	}
	
	return 0;
}

