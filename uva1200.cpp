#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

inline int char2int(char* list,int len){
	
	int sum=0;
	for(int i=len-1;i>=0;i--){
		sum+=(list[i]-48)*(int)pow(10,len-1-i);
	}
	return sum;
}


int main(void){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,digits;cin>>n;cin.ignore();
	char c;
	string equation;
	char* num_list= new char[1000];
	//num_list[0]='1';num_list[1]='2';num_list[2]='3';
	//cout<<char2int(num_list,3);
	int x_coef,const_coef;
	bool positive;
	bool left;
	
	for(int i=0;i<n;i++){
		
		digits=0;
		x_coef=0;
		const_coef=0;
		positive=true;
		left=true;
		getline(cin,equation);
		
		for(int j=0;j<equation.length();j++){
		
			switch(equation[j]){
				case 'x':
					if(digits==0){
						if(positive)
							x_coef+=1;
						else
							x_coef-=1;
						break;
					}
					else{
					
						if(positive)
							{x_coef+=char2int(num_list,digits);}
						else if(!positive)
							{x_coef-=char2int(num_list,digits);}
					}
					digits=0;
					delete[] num_list;
					num_list=new char[1000];
					break;
				case '+':
					if(positive)
						{const_coef+=char2int(num_list,digits);}
					else
						{const_coef-=char2int(num_list,digits);}
					
					digits=0;
					delete[] num_list;
					num_list=new char[1000];
						 
					if(left)
						positive=true;
					else
						positive=false;
					break;
				case '-':
					if(positive)
						{const_coef+=char2int(num_list,digits);}
					else
						{const_coef-=char2int(num_list,digits);}
						
					digits=0;
					delete[] num_list;
					num_list=new char[1000];
						
					if(left)
						positive=false;
					else
						positive=true;
					break;
				case '=':
					if(digits!=0){
						if(positive)
							{const_coef+=char2int(num_list,digits);}
						else
							{const_coef-=char2int(num_list,digits);}
						
						digits=0;
						delete[] num_list;
						num_list=new char[1000];
					}
					left=false;
					positive=false;
					break;
					
				default:
					num_list[digits++]=equation[j];
			}
			
			/*
			cout<<equation<<endl;
			cout<<equation[j]<<endl;
			cout<<"x coef:"<<x_coef<<endl;
			cout<<"const coef:"<<const_coef<<endl;
			system("pause");
			*/
			
		}
		
		if(digits!=0){
			if(positive){
				const_coef+=char2int(num_list,digits);
							
			}
			else{
				const_coef-=char2int(num_list,digits);
							
			}
		}
		
		
		if(x_coef==0 && const_coef==0){
			cout<<"IDENTITY"<<endl;
		}
		else if(x_coef!=0 && const_coef==0){
			cout<<0<<endl;
		}
		else if(x_coef==0 && const_coef!=0){
			cout<<"IMPOSSIBLE"<<endl;
		}
		else{
			//cout<<x_coef<<endl;
			//cout<<const_coef<<endl;
			double ansd = ((-const_coef)/x_coef);
			int ans;
			if(ansd<0){
				ans = floor(ansd-1);
			}
			else{
				ans = floor(ansd);
			}
			cout<<ans<<endl;
		}
			
	}
	
	return 0;
}

