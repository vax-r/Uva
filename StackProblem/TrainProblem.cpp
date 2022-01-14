#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <set>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

#define SIZE 4



void Swap_1(char &a,char &b){
	char temp=a;
	a=b;
	b=temp;
}


void Permutation(char* a, int start, int end,set<char*>& permutation){
	
	char* result=new char[SIZE];
	
	if(start==end){
		strcpy(result,a);
		permutation.insert(result);
	}
	else{
		for(int i=start;i<end;i++){
			Swap_1(a[start],a[i]);
			Permutation(a,start+1,end,permutation);
			Swap_1(a[start],a[i]);
		}
	}

	
}

bool TrainProblem(char* In,char* Out){
	stack<char> s;
	int j=0;
	for(int i=0;i<SIZE;i++){
		s.push(In[i]);
		while(!s.empty() && s.top()==Out[j]){
			s.pop();
			j++;
		}
	}
	if(s.empty()){
		return true;
	}
	else{
		return false;
	}
}

int main(int argc, char** argv) {
	
	char* In=new char[SIZE];
	set<char*> All_permutations;All_permutations.clear();
	

	
	while(cin>>In){
		Permutation(In,0,SIZE,All_permutations);//get all possible outcome
		for(set<char*>::iterator it=All_permutations.begin();it!=All_permutations.end();it++){
			if(TrainProblem(In,*it)){
				cout<<*it<<" is a possible outcome.\n";
			}
			else{
				cout<<*it<<" is an impossible outcome.\n";
			}
		}
		All_permutations.clear();
	}
	return 0;
}
