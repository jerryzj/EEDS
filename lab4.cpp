#include <iostream>
#include <cstdio>

using namespace std;

struct data{
	int x1,y1,x2,y2;	//location info
};

int main(void){
	int row,col,count,x1,x2,y1,y2;
	int **map;
	char wall,path;
	data *file;

	cin>>row;
	cin>>col;
	cin>>wall;
	cin>>path;
	cin>>count;
//debug
	cout<<"read basic info finish"<<endl;
	file = new data[count];
//debig
	cout<<"create database finish"<<endl;
	for (int i = 0; i < count; i++){
		scanf("%d,%d,%d,%d",&file[i].x1,&file[i].y1,&file[i].x2,&file[i].y2);
	}
//debug
	cout<<"read data finish"<<endl;
	map = new int*[row];
	for(int i=0;i<row;i++){
		map[i] = new int[col];
	}
//debug
	cout<<"map created"<<endl;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			map[i][j]=1;
		}
	}
//debug
	cout<<"map set default=wall"<<endl;
	map[1][0]=0;				//set entry
	map[row-1][col-1]=0;		//set exit
//debug
	cout<<"entry set"<<endl;
	for (int i = 0; i < count;i++){
 	cout<<"for loop"<<endl;
	cout<<"info copy"<<endl;
		if((map[file[i].x1][file[i].y1]==0 || map[file[i].x2][file[i].y2==0])&& !(map[file[i].x1][file[i].y1]==0 && map[file[i].x2][file[i].y2==0])){
			if (file[i].x1==file[i].x2){
				for (int j = file[i].y1; i <= file[i].y2; j++){
					map[file[i].x1][j]=0;
				}
			}
			else{
				for (int k = file[i].x1; k < file[i].x2; k++){
					map[k][file[i].y1]=0;
				}
			}
			
		}
		else{

		}
	}

	for (int i = 0; i < col; i++){
		for (int j = 0; j < row; j++){
			if (map[i][j]==1){
				cout<<wall;
			}
			else{
				cout<<path;
			}
			if (i==col-1){
				cout<<endl;
			}
		}
	}
	return 0;
}
