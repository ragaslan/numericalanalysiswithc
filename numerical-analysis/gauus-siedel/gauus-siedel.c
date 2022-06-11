#include<stdio.h>
#include<math.h>
#define SIZE 30

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

void swap_row(float arr[SIZE][SIZE],int boyut,int row1,int row2){
	int i,j;
	float temp;
	for(j=0;j<boyut;j++){
		temp = arr[row1][j];
		arr[row1][j] =  arr[row2][j];
		arr[row2][j] =  temp;
	}
}

float get_x(float arr[SIZE][SIZE],float y,float z){
	float x;
	x = (arr[0][3] - (arr[0][1] * y + arr[0][2] * z)) / arr[0][0];
	return x;
}

float get_y(float arr[SIZE][SIZE],float x,float z){
	float y;
	y = (arr[1][3] - (arr[1][0] * x + arr[1][2] * z)) / arr[1][1];
	return y;
}

float get_z(float arr[SIZE][SIZE],float x,float y){
	float z;
	z = (arr[2][3] - (arr[2][0] * x + arr[2][1] * y)) / arr[2][2];
	return z;
}

int main(){
	// ax+by+cz = d denklemlerini çözme
	// degisken ve denklem sayýsý ayný olmalý
	int i,j;
	float arr[SIZE][SIZE];
	for(i=0;i<3;i++){
		printf("%d) Sirasiyla ax + by + cz = d  (a,b,c,d) degerlerini girin :",i+1);
		scanf("%f %f %f %f",&arr[i][0],&arr[i][1],&arr[i][2],&arr[i][3]);
	}
	
	// buyuk olan olmayana gore swap
	for(i=0;i<2;i++){
		int max=-pow(10,2);
		int satir=-1;
		for(j=i;j<3;j++){
			if(arr[j][i] > max){
				satir = j;
				max = arr[j][i];
			}
		}
		swap_row(arr,4,i,satir);
	}
	
	// yerine koyup yenileri elde etme
	float x,y,z;
	float delta_x,delta_y,delta_z;
	delta_x = 1000;
	delta_y = 1000;
	delta_z = 1000;
	int iter = 0;
	printf("Baslangic x y z degerlerinizi giriniz: ");
	scanf("%f %f %f",&x,&y,&z);
	printf("hata payini giriniz: ");
	float hata;
	scanf("%f",&hata);
	while(delta_x >= hata || delta_y >= hata || delta_z >= hata){
		iter++;
		float newx = get_x(arr,y,z);
		float newy = get_y(arr,newx,z);
		float newz = get_z(arr,newx,newy);
		delta_x = fabs(newx - x);
		delta_y = fabs(newy - y);
		delta_z = fabs(newz - z);
		x = newx;
		y = newy;
		z = newz;
	}
	printf("%d. iterasyon sonucunda x -> %f  y -> %f z -> %f ",iter,x,y,z);
	
	
	
	
	return 0;
}
