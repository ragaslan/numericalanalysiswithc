#include<stdio.h>
#define SIZE 50

float factorial(int n){
	int i = 1;
	while(n >= 1){
		i *= n;
		n--;
	}
	return i;
}

void printMatrix(float matrix[SIZE][SIZE],int size1,int size2){
	int i,j;
	for(i=0;i<size1;i++){
		for(j=0;j<size2;j++){
			printf("%lf\t",matrix[i][j]);
		}
		printf("\n");
	}
}

int main(){
	float A[SIZE][SIZE];
	// x adetini almak
	int n,i,j,k;
	printf("Gireceginiz x adetini girin: ");
	scanf("%d",&n);
	int l = n;
	for(i=0;i<n;i++){
		printf("%d. x degeri : ",i+1);
		scanf("%f",&A[0][i]);
	}
	printf("F(x) degerleri : \n");
	for(i=0;i<n;i++){
		printf("f(%f) degeri : ",A[0][i]);
		scanf("%f",&A[1][i]);
	}
	
	// delta f in baþlamasý
	int flag = 0;
	j = 1;
	while(flag == 0){
		for(i=0;i<n-1;i++){
			A[j+1][i] = A[j][i+1] - A[j][i];
		}
		j++;
		int flag2 = 0;
		k = 0;
		while(flag2 == 0 && k < n){
			if(A[j][k] != 0){
				flag2 = 1;	
			}
			k++;
		}
		n--;
		if(flag2 != 1){
			flag = 1;
		}
	}
	// k deðerini ayarlama
	printf("Sirasiyla istenen x ve baslanan x0 ve h degerlerini giriniz: ");
	float x,x0,h,m;
	float c;
	scanf("%f %f %f",&x,&x0,&h);
	m = (x - x0) / h;
	float result = A[1][0];
	for(i=0;i<j-2;i++){
		float total = A[2+i][0] / factorial(i+1);
		c = 0;
		while(c <= i){
			total *= m-c;
			c++;
		}
		result += total;
	}
	printf("--------------------------\n");
	printMatrix(A,j,l);
	printf("--------------------------");
	printf("\nf(%f) = %f",x,result);
	return 0;
}

