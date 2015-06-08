#include <iostream>
using namespace std;

struct data{
	int x1,y1,x2,y2;	//location info
};

int main(void){
	int row,col,count;
	int **map;
	string wall,path;
	data *file;

	cin>>row;
	cin>>col;
	cin>>wall;
	cin>>path;
	cin>>count;
	file = new data[count];
	for (int i = 0; i < count; i++){
		cin>>file[i].x1;
		cin>>file[i].y1;
		cin>>file[i].x2;
		cin>>file[i].y2;
	}
	map = new int*[row];				//create 2D array map
	for(int i=0;i<row;i++){
		map[i] = new int[col];
	}
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			map[i][j]=1;			//set default = wall
		}
	}
	map[1][0]=0;			//set entry
	map[row-2][col-1]=0;		//set exit
	for (int i = 0; i < count;i++){
		if(map[file[i].x1][file[i].y1]==1 || map[file[i].x2][file[i].y2]==1){		
			if (file[i].x1==file[i].x2){	//case like (1,1)to (1,3)
				for (int j = file[i].y1; j <= file[i].y2; j++){
					map[file[i].x1][j]=0;
				}
			}
			else{		//case like (3,1)to (5,1) 
				for (int k = file[i].x1; k <= file[i].x2; k++){
					map[k][file[i].y1]=0;
				}
			}
		}
	}
	for (int i = 0; i < row; i++){			//print map
		for (int j = 0; j < col; j++){
			if(map[i][j]==1){
				cout<<wall;
			}
			else cout<<path;
			if(j==col-1) cout<<endl;
		}
	}
	return 0;
}
