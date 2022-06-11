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
void print_array(double arr[],int boyut){
	int i;
	for(i=0;i<boyut;i++){
		printf("%lf ",arr[i]);
	}
}
int main(){
	int katsayiDizisi[SIZE];
	printf("Fonksiyon derecesini giriniz ! ");
	int boyut = createFunction(katsayiDizisi);
	double altSinir,ustSinir;
	printf("fonksiyonun alt ve ust sinirini giriniz x y: ");
	scanf("%lf %lf",&altSinir,&ustSinir);
	printf("n degerinini giriniz : ");
	int n,j;
	double h,i;
	scanf("%d",&n);
	h = (ustSinir - altSinir) / n;
	double degerler[SIZE];
	i=altSinir;
	j = 0;
	while(i<=ustSinir){
		degerler[j] = runFunction(katsayiDizisi,boyut,i);
		i += h;
		j++;	
	}
	int degerBoyut = j;
	double alan = degerler[0] + degerler[degerBoyut-1];
	int k;
	for(k=1;k<degerBoyut-1;k++){
		if(k % 2 == 0){
			alan += 2 * degerler[k];
		}else{
			alan += 4 * degerler[k];
		}
	}
	alan = alan * (h / 3);
	printf("\n Alan: %lf",alan);
	return 0;
}
