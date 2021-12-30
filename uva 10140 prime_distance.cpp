#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <string>
using namespace std;

#define SIZE_LIM 1000000

int main(void){
	
	bool *prime=new bool[SIZE_LIM];
	prime[0] = false; prime[1] = false;
	for(int i=2;i<SIZE_LIM;i++)
		prime[i] = true;
	
	for(int i=2;i<SIZE_LIM;i++){
		for(int j=i+i;j<SIZE_LIM;j+=i){
			if(prime[i]){
				prime[j] = false;
			}
		}
	}
	
	int L,U,closest_dis,farest_dis,dis;
	int closest_pair[2],farest_pair[2];
	bool found=false;
	
	while(cin>>L>>U){
		
		while(!prime[L] || !prime[U]){
			if(!prime[L])
				L++;
			if(!prime[U])
				U--;
			if(L==U)
				break;
		}
		
		if(L==U){
			found=false;
		}
		else{
			found=true;
		}
		
		if(found){
			closest_pair[0] = L; closest_pair[1] = U; closest_dis = closest_pair[1]-closest_pair[0];
			farest_pair[0] = L; farest_pair[1] = L; farest_dis = 0;
			int i1=L,j1=L;
			
			for(int ind=L+1;ind<=U;ind++){
				if(!prime[ind])
					continue;
				else{
					i1=j1;
					j1=ind;
					dis=j1-i1;
					if(closest_dis > dis){
						closest_dis = dis;
						closest_pair[0] = i1;
						closest_pair[1] = j1;
					}
					if(farest_dis < dis){
						farest_dis = dis;
						farest_pair[0] = i1;
						farest_pair[1] = j1;
					}
				}	
			}
			
			printf("%d,%d are closest, %d,%d are most distant.",closest_pair[0],closest_pair[1],farest_pair[0],farest_pair[1]);
			cout<<endl;	
			
		}
		else{
			cout<<"There are no adjacent primes."<<endl;
		}
		
		
		
	}
	
	return 0;
}

