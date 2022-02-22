#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

#define Inrange(x,y) (0<=x && x<ParkSize && 0<=y && y<ParkSize)

using namespace std;

int ParkSize;
int step;

char Park[100][100];
bool walked[100][100];
bool UsedWord[256];
int Min_step[100][100];
int x_move[4]={-1,0,0,1},y_move[4]={0,1,-1,0};


inline void BFS(){
	
	memset(walked,false,sizeof(walked));

	if(!UsedWord[Park[0][0]] || !UsedWord[Park[ParkSize-1][ParkSize-1]])
		{return;}
	
	
	int cur_X=0,future_X,cur_Y=0,future_Y;
	queue <int> Qx,Qy;
	while(!Qx.empty())Qx.pop();
	while(!Qy.empty())Qy.pop();
	
	Qx.push(cur_X);
	Qy.push(cur_Y);
	walked[cur_Y][cur_X]=true;
	Min_step[cur_Y][cur_X]=1;
	
	while(!Qx.empty() && !Qy.empty()){

		cur_X=Qx.front();Qx.pop();
		cur_Y=Qy.front();Qy.pop();
		if(cur_X==ParkSize-1 && cur_Y==ParkSize-1){

			step= min(step,Min_step[cur_Y][cur_X]);
			return;
		}
		for(int i=0;i<4;i++){
			future_X=cur_X+x_move[i];
			future_Y=cur_Y+y_move[i];
			if(Inrange(future_X,future_Y) && !walked[future_Y][future_X] && UsedWord[Park[future_Y][future_X]]){
	
				Min_step[future_Y][future_X]=Min_step[cur_Y][cur_X]+1;
				walked[future_Y][future_X]=true;
				Qx.push(future_X);Qy.push(future_Y);
				
			}
		}
	}
	
	
}


inline void DFS(int i){
	
	
	if(i==10)
		{BFS();return;}
	
	UsedWord['A'+i]=true;
	UsedWord['a'+i]=false;
	DFS(i+1);
	UsedWord['A'+i]=false;
	UsedWord['a'+i]=true;
	DFS(i+1);
}



int main(void){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while(cin>>ParkSize){
		memset(walked,false,sizeof(walked));
		step=2111111111;
		
		for(int i=0;i<ParkSize;i++){
			for(int j=0;j<ParkSize;j++)
				cin>>Park[i][j]; 
		}
		
		DFS(0);//start the process
		
		
		if(step==2111111111)
			cout<<-1<<endl;
		else
			cout<<step<<endl;
		
	}	
	
	
	return 0;
}

