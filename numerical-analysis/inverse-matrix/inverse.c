#include<stdio.h>
#define COL 20
#define ROW 20
#define SIZE 50


void print_array(float arr[],int boyut){
	int i;
	for(i=0;i<boyut;i++){
		printf("%f ",arr[i]);
	}
}
void print_matrix(float arr[SIZE][SIZE],int boyut1,int boyut2){
	int i,j;
	printf("\n");
	for(i=0;i<boyut1;i++){
		for(j=0;j<boyut2;j++){
			printf("%f ",arr[i][j]);
		}
		printf("\n");
	}
}

int pivot_bul(float arr[SIZE][SIZE],int boyut,int sutun){
	int i,flag;
	flag = 0;
	int pivot;
	i=0;
	while(flag == 0 && i < boyut){
		if(arr[i][sutun] != 0){
			flag = 1;
			pivot = i;
		}
		i++;
	}
	if(flag == 1){
		return pivot;
	}else{
		return -1;
	}
}

void swap_row(float arr[SIZE][SIZE],int boyut,int row1,int row2){
	int i,j;
	float temp;
	for(j=0;j<boyut;j++){
		temp = arr[row1][j];
		arr[row1][j] =  arr[row2][j];
		arr[row2][j] =  temp;
	}
}

int main(){
	printf("Lutfen matrisin boyutunu giriniz (nxn) n'i girmen yeterli n: ");
	int n;
	scanf("%d",&n);
	float matrix[SIZE][SIZE];
	int i,j,k;
	float ratio,a;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d. satir %d. sutun girin : ",i+1,j+1);
			scanf("%f",&matrix[i][j]);
		}
	}
	// yanýna birim matrix ekleme
	for(i=0;i<n;i++){
		for(j=n;j<2*n;j++){
			if(i+n == j){
				matrix[i][j] = 1;
			}else{
				matrix[i][j] = 0;
			}
		}
	}
	
	 for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i!=j){
                ratio = matrix[j][i]/matrix[i][i];
                for(k = 0; k < 2*n; k++){
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }
    for(i = 0; i < n; i++){
        a = matrix[i][i];
        for(j = 0; j < 2*n; j++){
            matrix[i][j] /= a;
        }
    }
    
    printf("Matrisin Tersi: \n");
    for(i = 0; i < n; i++){
        for(j = n; j < 2*n; j++){
            printf("%f", matrix[i][j]);
            printf("\t");
        }
        printf("\n");
    }
	

	
	return 0;
}
