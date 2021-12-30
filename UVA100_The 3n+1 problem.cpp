#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

long long int Get_cycle_len(long long int num);

int main(void) {
	long long int x,y,i, j,len=0,max,cycle_len,temp;
	
	
	
	while (cin >> x >> y) {
		
		if(x>y){
			i=y;
			j=x;
		}
		else{
			i=x;
			j=y;
		}
		
		len = (j - i + 1);
		max = Get_cycle_len(i);
		
		for (long long int k = 1; k < len; k++) {
			cycle_len = Get_cycle_len(i + k);
			if (max < cycle_len) {
				max = cycle_len;
			}
		}

		cout << x << " " << y << " " << max << endl;

	}

	return 0;
}

long long int Get_cycle_len(long long int num) {
	long long int cycle_len = 1;

	while (num != 1) {
		if (num % 2 != 0) {
			num = num * 3 + 1;
			cycle_len++;
		}
		else {
			num /= 2;
			cycle_len++;
		}
	}


	return cycle_len;
}