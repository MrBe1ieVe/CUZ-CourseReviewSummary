#include <iostream>      //引用输入输出流
#include <stdio.h>
#include <math.h>
#include <time.h>

using namespace std;
int Andian(int A[3][3],int row,int col);  

void main()
{ 
    int B[3][3]={ {3,5,7},
		          {15,12,13},
				  {5,10,7},
				};
	
	
  
	 if (Andian(B,3,3)==0)
	    cout<<"不存在鞍点!"<<endl;
	

  
}



int Andian(int A[3][3],int row,int col) //不存在鞍点 返回0
{   int flag=0;

	int min=A[0][0],max=A[0][0];
	int i=0,j=0,x=0,y=0;
	while(y<row){
		min=A[y][0];x=0;
		for(i=0;i<col;i++){if(min>A[y][i]){min=A[y][i];x=i;}}
		//printf("%d,%d,%d\n",x,y,min);
		max=min;
		for(j=0;j<row;j++){
			if(max<A[j][x]){flag=0;break;}
			if(j==row-1){flag=1;printf("鞍点坐标为%d,%d，鞍点值为%d\n",x+1,y+1,A[y][x]);}
		}
		if(flag==0)y++;
		else break;
	}




	return flag;
}

