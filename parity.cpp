#include <iostream>
#include <string>
#include <cstdlib>
#include <bitset>
#include <typeinfo>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

string toBinary(long long int &num);

int main(int argc, char** argv) {
	
	long long int num,parity=0;
	int str_len;
	string Bi_form;
	
	while(cin>>num){
		if(num==0)
			continue;
		
		Bi_form=toBinary(num);
		str_len=Bi_form.length();
		parity=0;
		
		for(long long int i=0;i<str_len;i++){
			parity+=(Bi_form[i]=='0'?0:1);	
		}
		cout<<"The parity of "<<Bi_form<<" is "<<parity<<" (mod 2)."<<endl;
	}
	
	return 0;
}

string toBinary(long long int &num){
	string Binary_form,reverse_form;
	Binary_form.clear();
	reverse_form.clear();
	
	while(num!=0){
		Binary_form+=(num%2==0?"0":"1");
		num/=2;
	}
	
	for(int i=Binary_form.length()-1;i>=0;i--){
		reverse_form+=Binary_form[i];
	}
	
	
	return reverse_form;
}
