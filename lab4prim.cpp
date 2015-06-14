#include <iostream>
#include <cstdbool>
#include <cmath>
using namespace std;

struct data{
	int x1,y1,x2,y2,pt1,pt2;
};
void added_map(int x1,int y1,int x2,int y2,bool **map);
void added_tree(int ptr1,int ptr2,bool *tree,int row);
bool search(int ptr,bool *tree,int tree_size);

int main(void){
	int row,col,count,added=0,tree_size;
	bool **map;
	bool *tree;
	string wall,path;
	data *file;

	cin>>row;
	cin>>col;
	cin>>wall;
	cin>>path;
	cin>>count;
	file = new data[count];
	tree = new bool[(row*col)];
	tree_size = row*col;

	for (int i = 0; i < count; i++){
		int x1,y1,x2,y2;
		cin>>x1;
		cin>>y1;
		cin>>x2;
		cin>>y2;
		file[i].x1=x1;
		file[i].y1=y1;
		file[i].x2=x2;
		file[i].y2=y2;
		file[i].pt1 = (y1*row)+x1;
		file[i].pt2 = (y2*row)+x2;
	}
	map = new bool*[row];				//create 2D array map
	for(int i=0;i<row;i++){
		map[i] = new bool[col];
	}
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			map[i][j]=true;			//set default = wall
			tree[(i*j)]=0;
		}
	}
	added_map(file[0].x1,file[0].y1,file[0].x2,file[0].y2,map);
	tree[file[0].pt1]=1;
	tree[file[0].pt2]=1;
	while(added < (count-1)){
		for(int i=0;i<count;i++){
			bool result1=search(file[i].pt1,tree,tree_size);
			bool result2=search(file[i].pt2,tree,tree_size);
			if((result1==true && result2==false) || (result1==false && result2==true)){
				added_map(file[i].x1,file[i].y1,file[i].x2,file[i].y2,map);
				++added;
				added_tree(file[i].pt1,file[i].pt2,tree,row);
			}
		}
	}
	map[1][0]=0;			//set entry
	map[row-2][col-1]=0;		//set exit
	/////////////Print Map////////////
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

void added_map(int x1,int y1,int x2,int y2,bool **map){
	if (x1==x2){	//case like (1,1)to (1,3)
		for (int j = y1; j <= y2; j++){
			map[x1][j]=false;
		}
	}
	else{		//case like (3,1)to (5,1) 
		for (int k = x1; k <= x2; k++){
			map[k][y1]=false;
		}
	}
}

bool search(int ptr,bool *tree,int tree_size){
	for (int i = 0; i < tree_size; i++){
		if(tree[ptr]==1 ) return true;
	}
	return false;
}

void added_tree(int ptr1,int ptr2,bool *tree,int row){
	if(abs(ptr2-ptr1)%row==0){
		for(int i = 0;i < (abs(ptr2-ptr1)/row); i++){
			tree[ptr1+(i*row)]=true;
		}
	}	
	else{
		if(ptr1<ptr2){
			for (int i = ptr1; i <= ptr2; i++){
				tree[i]=true;
			}
		}
		else{
			for (int i = ptr2; i <= ptr1; i++){
				tree[i]=true;
			}
		}
	}	
}