#include <iostream>
#include <cstdio>
using namespace std;

struct data{
	int x1,y1,x2,y2;
};

int main(void){
	int row,col,count;
	int *map;
	char wall,path;
	data *file;

	cin<<row;
	cin<<col;
	cin<<wall;
	cin<<path;
	cin<<count;

	file = new data[count];
	for (int i = 0; i < count; i++){
		scanf("%d,%d,%d,%d",file[i].x1,file[i].y1,file[i].x2,file[i].y2);
	}
	map = new int[row][col];

	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			map[i][j]=1;
		}
	}
	map[1][0]=0;				//set entry
	map[row-1][col-1]=0;		//set exit
	for (int i = 0; i < count;){
		if(map[data[i].x1][data[i].y1]==0 || map[data[i].x2][data[i].y2==0]){
			if (data[i].x1==data[i].x2){
				for (int j = y1; i <= y2; j++){
					map[x1][j]=0;
				}
			}
			else{
				for (int k = x1; k < x2; k++){
					map[k][y1]=0;
				}
			}
			i++;
		}
		else{
			i++;
		}
	}
	for (int i = 0; i < col; i++){
		for (int j = 0; j < row; j++){
			if (map[i][j]==1){
				cout>>wall;
			}
			else{
				cout>>path;
			}
			if (i==col-1){
				cout>>endl;
			}
		}
	}
	return 0;
}