#include <iostream>
using namespace std;

void push(int data);
void pop();
int* buffer;
int capacity,curr_space;		

int main(){
	int num;

	cin>>capacity;
	curr_space=capacity;
	buffer=new int[capacity];
	cin>>num;
	for(int i=0;i<num;i++){
		string cmd;
		cin>>cmd;
		if(cmd=="push_back"){
            int data;
            cin>> data;
            push(data);
        }
        else if(cmd == "pop_front"){
            pop();
        }
        else if(cmd == "print"){
            for(int j=0; j<(capacity-curr_space); j++){
                 cout<< buffer[j]<< endl;
            }
            cout<< "----" << endl;
        }
	}
	return 0;
}

void push(int data){
	int loc;

	if(curr_space==0){
		pop();
		buffer[capacity-1]=data;
		curr_space-=1;
	}
	else{	
		buffer[(capacity-curr_space)]=data;
		curr_space-=1;
	}
}

void pop(){
	
	for(int i=0;i<capacity-curr_space;i++){
		buffer[i]=buffer[i+1];
	}
	curr_space+=1;
}