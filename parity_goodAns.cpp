#include<algorithm>
#include<string>
using namespace std;
int main(){
	int n;
	while(cin>>n,n){
		cout<<"The parity of ";
		string s;
		int parity=0;
		while(n){s.push_back('0'+n%2);parity+=n%2;n/=2;}
		reverse(s.begin(),s.end());
		for(int k=0;k<s.size();k++)cout<<s[k];
		cout<<" is "<<parity<<" (mod 2)."<<endl;
	}
	return 0;
}