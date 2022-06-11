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
double turev(int katsayilar[],int boyut,double degisken){
	int i;
	double result;
	result = 0;
	for(i=boyut-1;i>=0;i--){
		if(degisken == 0 && i-1 < 0 ){
			result += katsayilar[i] * i * 0;	
		}else{
			result += katsayilar[i] * i * pow(degisken,i-1);	
		}
		
	}
	return result;
}
void print_array(int arr[],int boyut){
	int i;
	for(i=0;i<boyut;i++){
		printf("%d ",arr[i]);
	}
}
int main(){
	int katsayiDizisi[SIZE];
	printf("Fonksiyon derecesini giriniz ! ");
	int boyut = createFunction(katsayiDizisi);
	double altSinir,ustSinir;
	printf("baslangic degerini giriniz x: ");
	scanf("%lf",&altSinir);
	double altDeger = runFunction(katsayiDizisi,boyut,altSinir);
	
	// kökü bulma
	// hata payý al
	double hataPayi;
	printf("Hata payini giriniz: ");
	scanf("%lf",&hataPayi);
	int flag = 0;
	int iter = 0;
	double kok;
	while(flag == 0){
		iter++;
		double altTurev = turev(katsayiDizisi,boyut,altSinir);
		double yeniKok = altSinir - (altDeger / altTurev);
		double yeniDeger = runFunction(katsayiDizisi,boyut,yeniKok);

		if(fabs(yeniKok - altSinir) < hataPayi){
			flag = 1;
			kok = yeniKok;
		}else{
			altSinir = yeniKok;
			altDeger = yeniDeger;
		}
		printf("\n%d iterasyon sonucunda Kok -> %lf dir ve f(%lf) = %lf",iter,yeniKok,yeniKok,runFunction(katsayiDizisi,boyut,yeniKok));
	}
	//printf("%d iterasyon sonucunda Kok -> %lf dir ve f(%lf) = %lf ",iter,kok,kok,runFunction(katsayiDizisi,boyut,kok));
	
	return 0;
}
