#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


int *c;
int n,m;

inline int lowbit(int i){
	return i&(-i);
}

inline void Update(int index,int value){
	for(int i=index;i<(n+m);i+=lowbit(i)){
		c[i]+=value;
	}
}

inline int Query(int index){
	int sum=0;
	
	for(int i=index;i>0;i-=lowbit(i)){
		sum+=c[i];
	}
	return sum;
}

int main(void){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int cases;
	//int n,m;
	int *movies_pos;
	int *a;
	int *out;
	
	cin>>cases;
	
	for(int i=0;i<cases;i++){
		cin>>n>>m;
			
		movies_pos = new int[n+m];
		memset(movies_pos,0,(n+m)*sizeof(int));
		c = new int[n+m];
		memset(c,0,(n+m)*sizeof(int));
		a = new int[m+1];
		out = new int[m];
		
		//頂端為陣列最尾端，c紀錄的是該電影下面有幾片 
		for(int j=1;j<=n;j++){
			movies_pos[j]=n+1-j;
			Update(movies_pos[j],1);
		}
		
		for(int j=1;j<=m;j++){
			cin>>a[j];
		}
		
		
		
		int top=n;
		
		for(int j=1;j<=m;j++){
			//cout<<Query(movies_pos[a[j]])<<endl;
			cout<<Query(top)-Query(movies_pos[a[j]]);
			//cout<<Query(top);
			if(j!=m)
				cout<<" ";
			else
				cout<<endl;
			
			Update(movies_pos[a[j]],-1);
			movies_pos[a[j]]=++top;
			Update(top,1);
		}
		
		
		
		delete[] movies_pos;
		delete[] a;
		delete[] out;
	}	
	
	
	return 0;
}

