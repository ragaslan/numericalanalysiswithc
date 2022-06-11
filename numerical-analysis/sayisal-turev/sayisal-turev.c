#include<stdio.h>
#include<math.h>

#define SIZE 50

int createFunction(int katsayilar[]){
	int maxExp;
	int i,j;
	scanf("%d",&maxExp);
	for(i=maxExp;i>=0;i--){
		printf("bilinmeyen derecesi %d olan katsayi: ",i);
		scanf("%d",&katsayilar[i]);	
	}
	return maxExp+1;	
}
double runFunction(int katsayilar[],int boyut,double degisken){
	int i;
	double result;
	result = 0;
	for(i=boyut-1;i>=0;i--){
		result += katsayilar[i] * pow(degisken,i);
	}
	return result;
}

double ileriTurev(int arr[],int boyut,double h,double x){
	double result;
	result = (runFunction(arr,boyut,x+h) - runFunction(arr,boyut,x)) / h;
	return result;
}
double geriTurev(int arr[],int boyut,double h,double x){
	double result;
	result = (runFunction(arr,boyut,x) - runFunction(arr,boyut,x-h)) / h;
	return result;
}
double merkeziTurev(int arr[],int boyut,double h,double x){
	double result;
	result = (runFunction(arr,boyut,x+h) - runFunction(arr,boyut,x-h)) / (2*h);
	return result;
}

int main(){
	int katsayiDizisi[SIZE];
	printf("Fonksiyon derecesini giriniz ! ");
	int boyut = createFunction(katsayiDizisi);
	double deger;
	printf("Lutfen turevini istediginiz degeri giriniz f'(x) x: ");
	scanf("%lf",&deger);
	double h;
	printf("Lutfen h degerini giriniz f(x+h) : ");
	scanf("%lf",&h);
	printf("\nHesaplanan turev degerleri:");
	printf("\nileri fark ile: %lf",ileriTurev(katsayiDizisi,boyut,h,deger));
	printf("\ngeri fark ile: %lf",geriTurev(katsayiDizisi,boyut,h,deger));
	printf("\nmerkezi fark ile: %lf",merkeziTurev(katsayiDizisi,boyut,h,deger));
	
	return 0;
}
