#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct lottery{
	unsigned long long sum;		//store integer after compound all the ticket numbers		
	int content[6];				//store ticket information
	char info='N';				//store result after analysis
	int info1;					//store match information
}LOTTERY;

/****FUNCTION DECLARATIONS****/
//SCAN:Scan input data
//PRINT:Here I apply Function Overloading to print analysis result
//SORTROW:Sort ticket numbers from small to large
//SORTCOL:Sort tickets by first number(if same,check next)from small to large
//ANALYZE:Check whether win the prize or not
//SORTR:Sort function use recursive to implement(also use function overloading to sort long long int)
//SORTI:Sort function use iterative to implement(also use function overloading to sort long long int)

void SCAN(int a,LOTTERY b[9999]);		
void PRINT(int a,LOTTERY b[9999]);
void PRINT(int a,LOTTERY b[9999],int c);
void SORTROW(int a,LOTTERY b[9999],char type);
void SORTCOL(int a,LOTTERY b[9999],char type);
void ANALYZE(int a,LOTTERY b[9999],int c,LOTTERY d[9999]);
void SORTR(int i,int *array,int size);
void SORTR(int i,long long *array,int size,int c);
void SORTI(int *a,int b);
void SORTI(long long *a,int b,int c);

int main (void){
	LOTTERY p[9999],q[9999];
	char algotype;
	int num1,num2;
	
	scanf("%c\n%d\n",&algotype,&num1);
	SCAN(num1,p);
	scanf("%d",&num2);
	SCAN(num2,q);
	SORTROW(num1,p,algotype);	
	SORTROW(num2,q,algotype);
	SORTCOL(num1,p,algotype);
	ANALYZE(num1,p,num2,q);
	printf("%c\n",algotype);
	PRINT(num1,p);
	PRINT(num2,q,1);

	return 0;
}

void SCAN(int a,LOTTERY b[9999]){
	for(int i=0;i<a;i++){
		scanf("%d %d %d %d %d %d\n",&b[i].content[0],&b[i].content[1],&b[i].content[2],&b[i].content[3],&b[i].content[4],&b[i].content[5]);
	}
	return;
}

void PRINT(int a,LOTTERY b[9999]){
	printf("%d\n",a);
	for(int i=0;i<a;i++){
		printf("%.2d %.2d %.2d %.2d %.2d %.2d\n",b[i].content[0],b[i].content[1],b[i].content[2],b[i].content[3],b[i].content[4],b[i].content[5]);
	}
}

void PRINT(int a,LOTTERY b[9999],int c){
	printf("%d\n",a);
	for(int i=0;i<a-1;i++){
        printf("%.2d %.2d %.2d %.2d %.2d %.2d",b[i].content[0],b[i].content[1],b[i].content[2],b[i].content[3],b[i].content[4],b[i].content[5]);
		if(b[i].info=='Y'){
			printf(" %c %d\n",b[i].info,b[i].info1);
		}
		else if(b[i].info=='N'){
			printf(" %c\n",b[i].info);
		}
    }   
	printf("%.2d %.2d %.2d %.2d %.2d %.2d",b[a-1].content[0],b[a-1].content[1],b[a-1].content[2],b[a-1].content[3],b[a-1].content[4],b[a-1].content[5]);
	if(b[a-1].info=='Y'){
    	printf(" %c %d",b[a-1].info,b[a-1].info1);
    }
    else if(b[a-1].info=='N'){
        printf(" %c",b[a-1].info);
    }
}

void SORTROW(int a,LOTTERY b[9999],char type){
	for(int i=0;i<a;i++){
		switch (type){
			case'S':sort(b[i].content,b[i].content+6); break;
			case'R':SORTR(0,b[i].content,6);		   break;
			case'I':SORTI(b[i].content,6);			   break;
			default:sort(b[i].content,b[i].content+6);
		}
		b[i].sum=b[i].content[0]*pow(10,10)+b[i].content[1]*pow(10,8)+b[i].content[2]*pow(10,6)+b[i].content[3]*pow(10,4)+b[i].content[4]*pow(10,2)+b[i].content[5];
	}
}

void SORTCOL(int a,LOTTERY b[9999],char type){
	long long sum[a];
	
	for(int i=0;i<a;i++){
		sum[i]=b[i].sum;
	}
	switch (type){
            case'S':sort(sum,sum+a); break;
            case'R':SORTR(0,sum,a,0);break;
            case'I':SORTI(sum,a,0);  break;
            default:sort(sum,sum+a);
    }
	for(int i=0;i<a;i++){
		b[i].content[0]=(sum[i]/pow(10,10));
		b[i].content[1]=(sum[i]/100000000)%100;
		b[i].content[2]=(sum[i]/1000000)%100;
		b[i].content[3]=(sum[i]/10000)%100;	
		b[i].content[4]=(sum[i]/100)%100;	
		b[i].content[5]=(sum[i]%100);
		b[i].sum=sum[i];
	}
}

void ANALYZE(int a,LOTTERY b[9999],int c,LOTTERY d[9999]){
	for(int i=0;i<a;i++){
		for(int j=0;j<c;j++){
			if(b[i].sum==d[j].sum ){
				d[j].info='Y';
				d[j].info1=i+1;
			}
		}
	}
}

void SORTR(int i,int *array,int size){
    if(i<size){
        int j;
        int temp=array[i];

        for(j=i;j>0 && array[j-1]>temp;j--){
            array[j]=array[j-1];
		}
        array[j]=temp;
        SORTR(++i,array,size);
    }
}

void SORTR(int i,long long *array,int size,int c){
    if(i<size){
        int j;
        long long temp=array[i];

        for(j=i;j>0 && array[j-1]>temp;j--){
            array[j]=array[j-1];
        }
        array[j]=temp;
        SORTR(++i,array,size,c);
    }   
}

void SORTI(int *a,int b){
	for(int i=0;i<b;i++){
		int j=i;
		for(int k=i+1;k<b;k++){
			if(a[k]<a[j]) j=k;
		}
		swap(a[i],a[j]);
	}
}

void SORTI(long long *a,int b,int c){
    for(int i=0;i<b;i++){
        int j=i;
        for(int k=i+1;k<b;k++){
            if(a[k]<a[j]) j=k;
        }
        swap(a[i],a[j]);
    }
}
