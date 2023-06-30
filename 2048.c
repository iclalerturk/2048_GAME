#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print_matrix(int N, int matrix[][4]){
	int i,j;
	for(i=0;i<N;i++){
		printf("-----------------\n");
		printf("|");
		for(j=0;j<N;j++){			
			if(matrix[i][j]==0){
				printf("   |");
			}
			else{
				printf(" %d |",matrix[i][j]);	
			}			
		}
		printf("\n");
	}
	printf("-----------------\n");
	printf("\n");
}
void zero_matrix(int N, int matrix[][4]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrix[i][j]=0;					
		}
	}
}
void creat_mat(int N, int matrix[][4]){
	int i,j,count=0;	
	while(count<2){
		i=rand() % N;
		j=rand() % N;
		if(matrix[i][j]==0){
			matrix[i][j]=2;
			count++;
		}		
	}	
}
void new_element(int N, int matrix[][4]){
	int i,j,count=0;	
	while(count<1){
		i=rand() % N;
		j=rand() % N;
		if(matrix[i][j]==0){
			matrix[i][j]=(rand() % 2 + 1) * 2;
			count++;
		}		
	}
}
void count_element1(int *k, int matrix[][4], int coordinate[][2]){
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(matrix[i][j]!=0){
				coordinate[*k][0]=i;
				coordinate[*k][1]=j;
				(*k)++;
			}								
		}
	}
}
void count_element2(int *k, int matrix[][4], int coordinate[][2]){
	int i,j;
	for(i=3;i>=0;i--){
		for(j=3;j>=0;j--){
			if(matrix[i][j]!=0){
				coordinate[*k][0]=i;
				coordinate[*k][1]=j;
				(*k)++;
			}								
		}
	}
}
void up(int k, int *scor, int matrix[][4], int coordinate[][2]){
	int i,j,m,count;
	int temp[8][2];
	count=0;
	for(i=0;i<k;i++){
		if(coordinate[i][0]>0){
			m=coordinate[i][0]-1;						
			while(matrix[m][coordinate[i][1]]==0 && m>0){
				m--;
			}
			if(matrix[m][coordinate[i][1]]==0){
				matrix[m][coordinate[i][1]]=matrix[coordinate[i][0]][coordinate[i][1]];
				matrix[coordinate[i][0]][coordinate[i][1]]=0;
			}
			else if(matrix[m][coordinate[i][1]]==matrix[coordinate[i][0]][coordinate[i][1]]){
				if(count==0){
					matrix[m][coordinate[i][1]]=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
					temp[count][0]=m;
					temp[count][1]=coordinate[i][1];
					(*scor)+=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
					matrix[coordinate[i][0]][coordinate[i][1]]=0;	
										
				}
				else{
					if(matrix[m][coordinate[i][1]]==matrix[temp[count-1][0]][temp[count-1][1]]){
						matrix[m+1][coordinate[i][1]]=(matrix[coordinate[i][0]][coordinate[i][1]]);
						matrix[coordinate[i][0]][coordinate[i][1]]=0;
					}
					else{
						matrix[m][coordinate[i][1]]=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
						temp[count][0]=m;
						temp[count][1]=coordinate[i][1];
						(*scor)+=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
						matrix[coordinate[i][0]][coordinate[i][1]]=0;	
					}	
					
				}
			}
			else{
				matrix[m+1][coordinate[i][1]]=matrix[coordinate[i][0]][coordinate[i][1]];
				if((m+1)!=coordinate[i][0]){
					matrix[coordinate[i][0]][coordinate[i][1]]=0;
				}
			
			}	
		}
													
	}
}
void down(int k, int *scor, int matrix[][4], int coordinate[][2]){
	int i,j,m,count;
	int temp[8][2];
	count=0;
	for(i=0;i<k;i++){
		if(coordinate[i][0]<3){
			m=coordinate[i][0]+1;						
			while(matrix[m][coordinate[i][1]]==0 && m<3){
				m++;
			}
			if(matrix[m][coordinate[i][1]]==0){
				matrix[m][coordinate[i][1]]=matrix[coordinate[i][0]][coordinate[i][1]];
				matrix[coordinate[i][0]][coordinate[i][1]]=0;	
			}
			else if(matrix[m][coordinate[i][1]]==matrix[coordinate[i][0]][coordinate[i][1]]){
				if(count==0){
					matrix[m][coordinate[i][1]]=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
					temp[count][0]=m;
					temp[count][1]=coordinate[i][1];
					(*scor)+=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
					matrix[coordinate[i][0]][coordinate[i][1]]=0;	
										
				}
				else{
					if(matrix[m][coordinate[i][1]]==matrix[temp[count-1][0]][temp[count-1][1]]){
						matrix[m-1][coordinate[i][1]]=(matrix[coordinate[i][0]][coordinate[i][1]]);
						matrix[coordinate[i][0]][coordinate[i][1]]=0;
					}
					else{
						matrix[m][coordinate[i][1]]=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
						temp[count][0]=m;
						temp[count][1]=coordinate[i][1];
						(*scor)+=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
						matrix[coordinate[i][0]][coordinate[i][1]]=0;	
					}	
					
				}
				count++;
			}
			else{
				matrix[m-1][coordinate[i][1]]=matrix[coordinate[i][0]][coordinate[i][1]];
				if((m-1)!=coordinate[i][0]){
					matrix[coordinate[i][0]][coordinate[i][1]]=0;
				}
				
			}	
		}		
										
	}
}
void right(int k, int *scor, int matrix[][4], int coordinate[][2]){
	int i,j,m,count;
	int temp[8][2];
	count=0;
	for(i=0;i<k;i++){
		if(coordinate[i][1]<3){
			m=coordinate[i][1]+1;						
			while(matrix[coordinate[i][0]][m]==0 && m<3){
				m++;
			}
			if(matrix[coordinate[i][0]][m]==0){
				matrix[coordinate[i][0]][m]=matrix[coordinate[i][0]][coordinate[i][1]];
				matrix[coordinate[i][0]][coordinate[i][1]]=0;	
			}	
			else if(matrix[coordinate[i][0]][m]==matrix[coordinate[i][0]][coordinate[i][1]]){
				if(count==0){
					matrix[coordinate[i][0]][m]=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
					temp[count][0]=m;
					temp[count][1]=coordinate[i][0];
					(*scor)+=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
					matrix[coordinate[i][0]][coordinate[i][1]]=0;	
										
				}
				else{
					if(matrix[coordinate[i][0]][m]==matrix[temp[count-1][1]][temp[count-1][0]]){
						matrix[coordinate[i][0]][m-1]=(matrix[coordinate[i][0]][coordinate[i][1]]);
						matrix[coordinate[i][0]][coordinate[i][1]]=0;
					}
					else{
						matrix[coordinate[i][0]][m]=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
						temp[count][0]=m;
						temp[count][1]=coordinate[i][0];
						(*scor)+=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
						matrix[coordinate[i][0]][coordinate[i][1]]=0;	
					}	
					
				}
				count++;
			}		
			else{
				matrix[coordinate[i][0]][m-1]=matrix[coordinate[i][0]][coordinate[i][1]];
				if((m-1)!=coordinate[i][1]){
					matrix[coordinate[i][0]][coordinate[i][1]]=0;
				}				
			}			
		}			
										
	}
}
void left(int k, int *scor, int matrix[][4], int coordinate[][2]){
	int i,j,m,count;
	int temp[8][2];
	count=0;
	for(i=0;i<k;i++){
		if(coordinate[i][1]>0){
			m=coordinate[i][1]-1;						
			while(matrix[coordinate[i][0]][m]==0 && m>0){
				m--;
			}
			if(matrix[coordinate[i][0]][m]==0){
				matrix[coordinate[i][0]][m]=matrix[coordinate[i][0]][coordinate[i][1]];
				matrix[coordinate[i][0]][coordinate[i][1]]=0;	
			}			
			else if(matrix[coordinate[i][0]][m]==matrix[coordinate[i][0]][coordinate[i][1]]){									
				if(count==0){
					matrix[coordinate[i][0]][m]=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
					temp[count][0]=m;
					temp[count][1]=coordinate[i][0];
					(*scor)+=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
					matrix[coordinate[i][0]][coordinate[i][1]]=0;	
										
				}
				else{
					if(matrix[coordinate[i][0]][m]==matrix[temp[count-1][1]][temp[count-1][0]]){
						matrix[coordinate[i][0]][m+1]=(matrix[coordinate[i][0]][coordinate[i][1]]);
						matrix[coordinate[i][0]][coordinate[i][1]]=0;
					}
					else{
						matrix[coordinate[i][0]][m]=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
						temp[count][0]=m;
						temp[count][1]=coordinate[i][0];
						(*scor)+=(matrix[coordinate[i][0]][coordinate[i][1]])*2;
						matrix[coordinate[i][0]][coordinate[i][1]]=0;	
					}	
					
				}
				count++;
			}		
			else{
				matrix[coordinate[i][0]][m+1]=matrix[coordinate[i][0]][coordinate[i][1]];
				if((m+1)!=coordinate[i][1]){
					matrix[coordinate[i][0]][coordinate[i][1]]=0;
				}
			}
		}		
										
	}
}
int main (){
	srand(time(NULL));
	int k=0, scor=0,count,i,j;
	char move;
	int matrix[4][4], coordinate[16][2];
	printf("2048 GAME\n");
	zero_matrix(4,matrix);
	creat_mat(4,matrix);
	print_matrix(4,matrix);
	printf("up: u\ndown: d\nright: r\nleft: l");
	k=0;
	count_element1(&k,matrix,coordinate);
	while(k<16 && scor<2048){
		k=0;
		printf("\nmove: ");
		scanf(" %c",&move);		
		if(move=='u'){
			count_element1(&k,matrix,coordinate);
			up(k,&scor,matrix,coordinate);
			new_element(4,matrix);
			print_matrix(4,matrix);
			printf("\nscor: %d\n",scor);			
		}
		else if(move=='d'){
			count_element2(&k,matrix,coordinate);
			down(k,&scor,matrix,coordinate);
			new_element(4,matrix);
			print_matrix(4,matrix);
			printf("\nscor: %d\n",scor);
		}
		else if(move=='r'){
			count_element2(&k,matrix,coordinate);
			right(k,&scor,matrix,coordinate);
			new_element(4,matrix);
			print_matrix(4,matrix);
			printf("\nscor: %d\n",scor);
		}
		else if(move=='l'){
			count_element1(&k,matrix,coordinate);
			left(k,&scor,matrix,coordinate);
			new_element(4,matrix);
			print_matrix(4,matrix);
			printf("\nscor: %d\n",scor);
		}
		else{
			printf("\nwrong access!!!\n");
		}
		k=0;
		count_element1(&k,matrix,coordinate);
		count=0;
		if(k==16){
			for(i=0;i<4;i++){
				for(j=1;j<4;j++){
					if(matrix[i][j]==matrix[i][j-1]){
						count++;
					}					
				}
			}
			for(i=0;i<4;i++){
				for(j=1;j<4;j++){
					if(matrix[j][i]==matrix[j-1][i]){
						count++;
					}					
				}
			}
			if(count>0){
				k=0;
			}
		}	
	}
	if(k==16){
		if(scor==2048){
			printf("\nCONGRATULATIONS!!!");
            printf("You reached 2048.");
		}
		else{
			printf("\nGAME OVER");
            printf("\nYour scor is: %d",scor);
		}
	}
	if(scor==2048){
			printf("\nCONGRATULATIONS!!!");
            printf("You reached 2048.");
	}
	return 0;
}
