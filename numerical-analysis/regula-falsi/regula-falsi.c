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
	printf("aranicak sinirlari giriniz x y: ");
	scanf("%lf %lf",&altSinir,&ustSinir);
	double altDeger = runFunction(katsayiDizisi,boyut,altSinir);
	double ustDeger = runFunction(katsayiDizisi,boyut,ustSinir);
	// kok varlýgý sorgulama
	if(altDeger * ustDeger < 0){
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
			double yeniKok = ((ustSinir * altDeger) - (altSinir * ustDeger)) / (altDeger - ustDeger);
			double yeniDeger = runFunction(katsayiDizisi,boyut,yeniKok);
			if(((ustSinir - altSinir) / pow(2,iter)) < hataPayi){
				flag = 1;
				kok = yeniKok;
			}
			if(yeniDeger * altDeger < 0){
				ustSinir = yeniKok;
				ustDeger = yeniDeger;
			}else{
				altSinir = yeniKok;
				altDeger = yeniDeger;
			}
		}
		printf("%d iterasyon sonucunda Kok -> %lf dir ve f(%lf) = %lf ",iter,kok,kok,runFunction(katsayiDizisi,boyut,kok));
	}else{
		printf("Bu aralikta [%lf,%lf] kok yok !",altSinir,ustSinir);
	}
	return 0;
}
