#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

long long int sum;

inline void SWAP(long long int& a, long long int& b){
	long long int temp;
	temp=a;
	a=b;
	b=temp;
}

inline void ShowList(long long int* list, int start, int end){
	for(int i=0;i<(end-start);i++)
		cout<<list[i]<<" ";
	cout<<endl;
}

inline long long int* Merge(long long int* list1,long long int* list2,int start1,int end1,int start2,int end2){
	long long int* Res;
	long long int count=0;

	if(start1==end1 && start2==end2)
		{Res=NULL;}
	else if(start1==end1 && start2!=end2)
		{Res=list2;}
	else if(start1!=end1 && start2==end2)
		{Res=list1;}
	else{
		int len=end1-start1+end2-start2;
		Res=new long long int[len];
		
		int l1=start1,l2=start2,i=0;
		while(l1<end1 && l2<end2 && i<len){
			if(list1[l1]<=list2[l2]){
				Res[i++]=list1[l1++];
			}
			else if(list2[l2]<list1[l1]){
				count=(end1-l1);
				sum+=count;
				Res[i++]=list2[l2++];
			}
		}
		
		while(l1<end1)
			Res[i++]=list1[l1++];
		while(l2<end2)
			Res[i++]=list2[l2++];
		
	}
	
	return Res;	
}

inline void MergeSort(long long int* list,int start,int end){
	
	long long int* Res;
	
	if(start==end-1)return;
	
	int key=floor((start+end)/2);
	MergeSort(list,start,key);
	MergeSort(list,key,end);
	Res=Merge(list,list,start,key,key,end);
	
	for(int i=start;i<end;i++){
		list[i]=Res[i-start];
	}
	delete[] Res;
	
}


int main(void){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;

	long long int* seq1;
	
	while(cin>>n && n!=0){
		sum=0;
		seq1 = new long long int[n];
		for(int i=0;i<n;i++)
			cin>>seq1[i];
		MergeSort(seq1,0,n);
		cout<<sum<<endl;
		
		delete[] seq1;
	}
	
	return 0;
}

