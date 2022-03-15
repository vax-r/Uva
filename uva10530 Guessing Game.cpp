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
	
	string High = "too high";
	string Low = "too low";
	string right = "right on";
	string response;
	
	int guess;
	bool Ans[11];
	memset(Ans,true,sizeof(Ans));
	
	/*
	for(int i=0;i<11;i++){
		cout<<Ans[i]<<" ";
	}cout<<endl;
	
	memset(Ans+10,false,sizeof(bool)*(11-10));
	for(int i=0;i<11;i++){
		cout<<Ans[i]<<" ";
	}cout<<endl;
	*/
	
	
	while(cin>>guess && guess!=0){
		response.clear();
		cin.ignore();
		getline(cin,response);
		
		if(strcmp(response.c_str(),High.c_str())==0){
			memset(Ans+guess,false,sizeof(bool)*(11-guess));
		}
		else if(strcmp(response.c_str(),Low.c_str())==0){
			memset(Ans,false,sizeof(bool)*(guess+1));
		}
		else{
			if(Ans[guess]){
				cout<<"Stan may be honest"<<endl;
			}
			else{
				cout<<"Stan is dishonest"<<endl;
			}
			memset(Ans,true,sizeof(Ans));//re-initialize the game
		}
		
	}
	
	
	return 0;
}

