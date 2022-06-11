#include<stdio.h>
#define SIZE 40
// ax + by + cz = d (gibi 3 farklý denklem girdisi ile x y z nin bulunmasý !)

void printMatrix(float matrix[SIZE][SIZE],int boyut1,int boyut2){
	int i,j;
	for(i=0;i<boyut1;i++){
		printf("\n");
		for(j=0;j<boyut2;j++){
			printf("%f ",matrix[i][j]);
		}
	}
	printf("\n");
}
int main(){
	int n;
	printf("Bilinmeyen sayisini giriniz :");
	scanf("%d",&n);
	printf("Lutfen ax + by + cz ....= d formatindaki n denklem icin a b c d ... sayilarini giriniz: \n");
	int i,j,k;
	float matrix[SIZE][SIZE];// [3][4] bizim icin yeterli
	for(i=0;i<n;i++){
		printf("%d. denklemin ax+by+cz.... = d  icin a b c d... sayilari: ",i+1);
		for(j=0;j<n+1;j++){
			scanf("%f",&matrix[i][j]);
		}
	}
	
	for(i = 0; i < n; i++){
		float pivot = matrix[i][i];
		for(j = 0; j < n+1; j++){
            matrix[i][j] = matrix[i][j] / pivot;
        }
        printMatrix(matrix,n,n+1);
        for(k=i+1;k<n;k++){
        	float x = matrix[k][i];
        	for(j = 0; j < n+1; j++){
            	matrix[k][j] /= x;
        	}
        	for(j = 0; j < n+1; j++){
            	matrix[k][j] -= matrix[i][j];
        	}
        	for(j = 0; j < n+1; j++){
            	matrix[k][j] *= x;
        	}
        	printMatrix(matrix,n,n+1);
		}
    }
    float kokler[SIZE];
    for(i=n-1;i>=0;i--){
    	kokler[i] = matrix[i][n];
    	for(j=i+1;j<=n-1;j++){
    		kokler[i] -= kokler[j] * matrix[i][j];
		}
	}
    /*
	kokler[2] = matrix[2][3];
    kokler[1] = matrix[1][3] - matrix[1][2] * kokler[2] ;
    kokler[0] = matrix[0][3] - matrix[0][2] * kokler[2] - matrix[0][1] * kokler[1];
	*/
	for(i=0;i<n;i++){
		printf("\n%d. kok -> %f",i+1,kokler[i]);
	}	
	
	
	return 0;
}
