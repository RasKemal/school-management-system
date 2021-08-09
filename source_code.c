#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
	int dersID;
	char dersadi [30];
	int derskredisi;
	int kontenjan;
	int ogretimuyeID;
}dersler;
typedef struct{
	int ogretimuyeID;
	char ogretimad [30];
	char ogretimsoyad [30];
	char unvan [30];
}ogretimuyesi;
typedef struct{
	int ogrenciID;
	char ad [30];
	char soyad [30];
	int derssayisi;
	int kredi;
}ogrenci;
typedef struct{
	int no;
	int ogrID;
	int dID;
	char tarih[15];
	int durum;
}kayit;


void dosya_sinif_listesi(){
	dersler d; kayit k;
	int n,m,flag=0;
	FILE *data=fopen("dersler.txt","r");
	FILE *fp=fopen("ogrenciderskayit.txt","r");
	FILE *fw;
	printf("Lutfen sinifinin listesini istediginiz ogretim uyesinin IDsini giriniz:");
	scanf("%d",&n);
	printf("\nOgretim uyesinin verdigi derslerin kodlari:\n");
	while(!feof(data)){
		fscanf(data,"%d %s %d %d %d\n",&d.dersID,d.dersadi,&d.derskredisi,&d.kontenjan,&d.ogretimuyeID);
		if(n == d.ogretimuyeID){
			printf("%d ", d.dersID);
		}
	}
	fseek(data,0,SEEK_SET);
	printf("\nLutfen sinif listesini istediginiz dersin kodunu giriniz:");
	scanf("%d",&m);
	fw = fopen("DERSKODU_SÝNÝFLÝSTESÝ.txt","w");
	while(!feof(data)){
		fscanf(data,"%d %s %d %d %d\n",&d.dersID,d.dersadi,&d.derskredisi,&d.kontenjan,&d.ogretimuyeID);
		if(d.ogretimuyeID == n && d.dersID == m){
			flag = 1;
			while(!feof(fp)){
				fscanf(fp,"%d %d %d %s %d\n",&k.no,&k.ogrID,&k.dID,k.tarih,&k.durum);
				if(m == k.dID && k.durum == 1){
					fprintf(fw,"%d\n",k.ogrID);
				}
			}
		}
	}
	if(flag==0){
		printf("\nID veya kod bilgilerini girerken hata yaptiniz, tekrar denemek icin tiklayiniz.\n\n");
		getch();
		}
	printf("\nSinif listesi basariyla dosyaya yazildi.\n");
	fclose(data); fclose(fp); fclose(fw);
	getch();
	
}

void ders_sinif_listesi(){
	kayit k;
	int flag=0;
	int n;
	FILE *data=fopen("ogrenciderskayit.txt","r");
	printf("Lutfen sinif listesini gormek istediginiz dersin kodunu giriniz:");
	scanf("%d",&n);
	printf("\n**SINIF LISTESI(IDLER)**\n");
	while(!feof(data)){
		fscanf(data,"%d %d %d %s %d\n",&k.no,&k.ogrID,&k.dID,k.tarih,&k.durum);
		if(n == k.dID){
			printf("\n%d\n",k.ogrID);
			flag = 1;
			}
		}
	if(flag==0){
		printf("\nBoyle bir ders bulunmuyor,tekrar denemek icin tiklayiniz.\n\n");
		getch();
	}
  	fclose(data);
  	getch();
}



void ogrenci_ders_listele(){
	kayit k;
	int flag=0;
	int n,p;
	FILE *data=fopen("ogrenciderskayit.txt","r+");
	printf("Lutfen derslerini listelemek istediginiz ogrencinin IDsini giriniz:");
	scanf("%d",&n);
	printf("\n*DERSLER*\n");
	while(!feof(data)){
		fscanf(data,"%d %d %d %s %d\n",&k.no,&k.ogrID,&k.dID,k.tarih,&k.durum);
		if(n == k.ogrID && k.durum == 1){
			p = k.dID;
			printf("\n%d\n",p);
			flag=1;
		}
	}
	if(flag==0){
		printf("\nBoyle bir ogrenci bulunmuyor, tekrar denemek icin tiklayiniz.\n\n");
		getch();
	 }
	fclose(data);
	getch();
			
}


void ogretimuyesi_ders_listele(){
	dersler d;
	int n,flag=0;
	FILE *data=fopen("dersler.txt", "r");
	printf("Lutfen derslerini listelemek istediginiz ogretim uyesinin IDsini giriniz:");
	scanf("%d",&n);
	printf("\n**VERILEN DERSLER**\n");
	while(!feof(data)){
		fscanf(data,"%d %s %d %d %d\n",&d.dersID,d.dersadi,&d.derskredisi,&d.kontenjan,&d.ogretimuyeID);
		if(n == d.ogretimuyeID){
			printf("\n%s\n",d.dersadi);
			flag=1;
		}
	}
	if(flag == 0){
		printf("\nBoyle bir ogretim uyesi bulunmuyor, tekrar denemek icin tiklayiniz.\n\n");
		getch();
		}
	fclose(data);
	getch();
}



void ogrenci_ders_sil(){
	int n,m,flag=0,kredi;
	kayit k; dersler d; ogrenci o;
	FILE *data=fopen("ogrenciderskayit.txt", "r+");
	printf("Dersi silinecek ogrencinin ID'sini giriniz:");
	scanf("%d",&n);
	printf("Silinecek dersin kodunu giriniz:");
	scanf("%d",&m);
	FILE *fp=fopen("tmp.txt","w");
	while(!feof(data)){
		fscanf(data,"%d %d %d %s %d\n",&k.no,&k.ogrID,&k.dID,k.tarih,&k.durum);
		if(k.ogrID == n && k.dID == m){
			if(k.durum == 1){
			flag=1;
			fprintf(fp,"%d %d %d %s %d\n",k.no,k.ogrID,k.dID,k.tarih,0);
			
			printf("\nKaydiniz silinmistir.(Devam etmek icin tuslayiniz)\n");
			getch();
		}else{
			printf("\nBu derse kayitli degilsiniz.(Devam etmek icin tuslayiniz)\n");
			getch();
		}
		}else{
			fprintf(fp,"%d %d %d %s %d\n",k.no,k.ogrID,k.dID,k.tarih,k.durum);
		}
	}
	fclose(data); fclose(fp);
	remove("ogrenciderskayit.txt");
	rename("tmp.txt","ogrenciderskayit.txt");
	if(flag == 1){
		FILE *fw = fopen("ogrenciler.txt","r");
		FILE *fq = fopen("tmp.txt","w");
		FILE *fd = fopen("dersler.txt","r");
		while(!feof(fd)){
			 fscanf(fd,"%d %s %d %d %d\n",&d.dersID,d.dersadi,&d.derskredisi,&d.kontenjan,&d.ogretimuyeID);
			 if(m == d.dersID){
			 	kredi = d.derskredisi;
			 }
		}
		while(!feof(fw)){
			fscanf(fw,"%d %s %s %d %d\n",&o.ogrenciID,o.ad,o.soyad,&o.derssayisi,&o.kredi);
			if(n == o.ogrenciID){
				fprintf(fq,"%d %s %s %d %d\n",o.ogrenciID,o.ad,o.soyad,o.derssayisi-1,o.kredi-kredi);
			}else{
			fprintf(fq,"%d %s %s %d %d\n",o.ogrenciID,o.ad,o.soyad,o.derssayisi,o.kredi);
			}
		}
		
		fclose(fw); fclose(fq); fclose(fd);
		remove("ogrenciler.txt");
		rename("tmp.txt","ogrenciler.txt");
	}
	
}

void ogrenci_ders_ekle(){
	int n, m,maxders=4,maxkredi=20,p,flag1=0,flag2=0,bayrak=0,no=1;
	char tarih[15];
	ogrenci o; dersler d; kayit k;
	FILE *data=fopen("dersler.txt","r");
	FILE *fp=fopen("ogrenciler.txt","r");
	printf("Lutfen bugunun tarihini giriniz:");
	scanf("%s",tarih);
	printf("Lutfen ogrenci IDsi giriniz:");
	scanf("%d",&n);
	printf("Lutfen almak istediginiz dersin kodunu giriniz:");
	scanf("%d",&m);
	FILE *fw=fopen("tmp.txt","w");
	while(!feof(data)){
		fscanf(data,"%d %s %d %d %d\n",&d.dersID,d.dersadi,&d.derskredisi,&d.kontenjan,&d.ogretimuyeID);
		if(m == d.dersID){
			flag1 = 1;
			p = d.derskredisi;
		}
	}
	FILE *fq = fopen("ogrenciderskayit.txt","a+");
	while(!feof(fp)){
		fscanf(fp,"%d %s %s %d %d\n",&o.ogrenciID,o.ad,o.soyad,&o.derssayisi,&o.kredi);
		if(n != o.ogrenciID){
			fprintf(fw,"%d %s %s %d %d\n",o.ogrenciID,o.ad,o.soyad,o.derssayisi,o.kredi);
		}else{
			flag2=1;
			if(o.kredi+p <= maxkredi && o.derssayisi+1 <= maxders){
			fprintf(fw,"%d %s %s %d %d\n",o.ogrenciID,o.ad,o.soyad,o.derssayisi+1,o.kredi+p);
			while(!feof(fq)){
				fscanf(fq,"%d %d %d %s %d\n",&k.no,&k.ogrID,&k.dID,k.tarih,&k.durum);
				no = k.no+1;
			}
			fprintf(fq,"%d %d %d %s %d\n",no,n,m,tarih,1);
			printf("\nDers basariyla sisteme kaydedildi.(Devam etmek icin tuslayiniz)\n");
			getch();
			}else{
				printf("\nMaksimum kredi limitine ulastiniz.(Devam etmek icin tuslayiniz)\n");
				getch();
				fprintf(fw,"%d %s %s %d %d\n",o.ogrenciID,o.ad,o.soyad,o.derssayisi,o.kredi);
			}
		}
	}
	if(flag1!=1 || flag2!=1){
		printf("\nHatali Giris.(Devam etmek icin tuslayiniz)\n");
		getch();
	}
	fclose(data); fclose(fp); fclose(fw); fclose(fq);
	remove("ogrenciler.txt");
	rename("tmp.txt","ogrenciler.txt");
}
	


void ogrenci_sil(){
	int n,flag=0,flag1=0;
	ogrenci o; kayit k;
	FILE *data=fopen("ogrenciler.txt", "r");
	FILE *fw;
	fw = fopen("tmp.txt", "w");
	if(data == NULL){
		printf("\nHATA\n");
	}
	printf("Silmek istediginiz ogrencinin id'sini giriniz:");
	scanf("%d",&n);
	while(!feof(data)){
		fscanf(data,"%d %s %s %d %d\n",&o.ogrenciID,o.ad,o.soyad,&o.derssayisi,&o.kredi);
		if(o.ogrenciID != n){
			fprintf(fw,"%d %s %s %d %d\n",o.ogrenciID,o.ad,o.soyad,o.derssayisi,o.kredi);
		}else{
			flag=1;
		}
	}
	if(flag == 0){
		printf("\nGirdiginiz id'ye ait bir ogrenci bulunamadi.(Devam etmek icin tuslayiniz)\n\n");
		getch();
		}else{
			flag1=1;
			printf("\nSilme islemi basarili.(Devam etmek icin tuslayiniz)\n\n");
			getch();
		}
	fclose(data);
	fclose(fw);
	remove("ogrenciler.txt");
	rename("tmp.txt","ogrenciler.txt");
	if(flag1==1){
		FILE *fp =fopen("ogrenciderskayit.txt","r");
		FILE *fq=fopen("tmp.txt","w");
		while(!feof(fp)){
			fscanf(fp,"%d %d %d %s %d\n",&k.no,&k.ogrID,&k.dID,k.tarih,&k.durum);
			if(n == k.ogrID){
				fprintf(fq,"%d %d %d %s %d\n",k.no,k.ogrID,k.dID,k.tarih,0);
			}else{
				fprintf(fq,"%d %d %d %s %d\n",k.no,k.ogrID,k.dID,k.tarih,k.durum);
				}
			}
			fclose(fp); fclose(fq);
			remove("ogrenciderskayit.txt");
			rename("tmp.txt","ogrenciderskayit.txt");
	}
}

void ogretimuyesi_sil(){
	int n,flag=0,dersID,flag1=0;
	ogretimuyesi k; dersler d;
	FILE *data=fopen("ogruyesi.txt", "r");
	FILE *fw;
	FILE *fp=fopen("dersler.txt","r");
	if(data == NULL){
		printf("HATA");
	}
	printf("Silmek istediginiz ogretim uyesinin id'sini giriniz:");
	scanf("%d",&n);
	while(!feof(fp)){
		fscanf(fp,"%d %s %d %d %d\n",&d.dersID,d.dersadi,&d.derskredisi,&d.kontenjan,&d.ogretimuyeID);
		if(n == d.ogretimuyeID){
			flag=1;
		}
	}
	if(flag==0){
		fw = fopen("tmp.txt", "w");
		while(!feof(data)){
			fscanf(data,"%d %s %s %s\n",&k.ogretimuyeID,k.ogretimad,k.ogretimsoyad,k.unvan);
			if(k.ogretimuyeID != n){
				fprintf(fw,"%d %s %s %s\n",k.ogretimuyeID,k.ogretimad,k.ogretimsoyad,k.unvan);
			}else{
				flag1=1;
				printf("\nSilme islemi basariyla gerceklesti.(Devam etmek icin tuslayiniz)\n\n");
				getch();
			}
		}
		if(flag1==0){
			printf("\nGirdiginiz IDye ait ogretim uyesi bulunamadi.(Devam etmek icin tuslayiniz)\n\n");
			getch();
		}
		fclose(data);
		fclose(fw); fclose(fp);
		remove("ogruyesi.txt");
		rename("tmp.txt","ogruyesi.txt");
	}else{
		printf("\nSilmek istediginiz ogretim uyesine tanimli ders veya dersler var, once dersleri siliniz sonra tekrar deneyiniz.(Devam etmek icin tuslayiniz)\n\n");
		getch();
	}
}


void ders_sil(){
	int n,flag=0,kredi,dersID,flag1=0,i=0,counter=0;
	int ogrID[500];
	dersler d; ogrenci o; kayit k;
	FILE *data=fopen("dersler.txt", "r");
	FILE *fw,*fp,*fq,*fk;
	fw = fopen("tmp.txt", "w");
	if(data == NULL){
		printf("HATA");
	}
	printf("Silmek istediginiz dersin kodunu giriniz:");
	scanf("%d",&n);
	while(!feof(data)){
		fscanf(data,"%d %s %d %d %d\n",&d.dersID,d.dersadi,&d.derskredisi,&d.kontenjan,&d.ogretimuyeID);
		if(d.dersID == n){
			dersID = d.dersID;
			kredi = d.derskredisi;
			flag = 1;
			}else{
			fprintf(fw,"%d %s %d %d %d\n",d.dersID,d.dersadi,d.derskredisi,d.kontenjan,d.ogretimuyeID);
		}
	}
	if(flag==0){
		printf("\nGirdiginiz IDye ait ders bulunamadi.(Devam etmek icin tuslayiniz)\n\n");
		getch();
	}else{
		printf("\nSilme islemi basariyla gerceklesti.(Devam etmek icin tuslayiniz)\n\n");
		flag1=1;
		getch();
	}
	fclose(data);
	fclose(fw);
	remove("dersler.txt");
	rename("tmp.txt","dersler.txt");
	if(flag1==1){
		fw = fopen("tmp.txt","w");
		fq = fopen("ogrenciderskayit.txt","r");
		while(!feof(fq)){
			fscanf(fq,"%d %d %d %s %d\n",&k.no,&k.ogrID,&k.dID,k.tarih,&k.durum);
			if(n == k.dID){
				fprintf(fw,"%d %d %d %s %d\n",k.no,k.ogrID,k.dID,k.tarih,0);
			}else{
				fprintf(fw,"%d %d %d %s %d\n",k.no,k.ogrID,k.dID,k.tarih,k.durum);
			}
		}
		fclose(fw); fclose(fq);
		remove("ogrenciderskayit.txt");
		rename("tmp.txt","ogrenciderskayit.txt");
	}
	
}


void ogretimuyesi_ekle(){
	FILE *data=fopen("ogruyesi.txt", "a+");
	ogretimuyesi k;
	int id,c=0;
	id = k.ogretimuyeID;
	if(data == NULL){
		printf("HATA");
	}
	printf("ID:");
	scanf("%d",&id);
	while(!feof(data)){
	fscanf(data,"%d %s %s %s", &k.ogretimuyeID, k.ogretimad, k.ogretimsoyad, k.unvan);
	if(id == k.ogretimuyeID){
			c=1;
		}
	}
	fseek(data,0,SEEK_SET);
	printf("\nOgretim Uyesi Adi:");
	scanf("%s",k.ogretimad);
	printf("\nOgretim Uyesi Soyadi:");
	scanf("%s",k.ogretimsoyad);
	printf("\nOgretim Uyesi Unvani:");
	scanf("%s",k.unvan);
	if(c == 0){
		fprintf(data,"\n%d %s %s %s", id, k.ogretimad, k.ogretimsoyad, k.unvan);
		printf("\nEkleme islemi basarili.(Devam etmek icin tiklayiniz)\n");
		getch();
	}else{
		printf("\nEkleme islemi basarisiz, bu ID'de bir ogretim uyesi zaten mevcut.(Devam etmek icin tiklayiniz)\n");
		getch();
	}
	fclose(data);
	
}
void ogrenci_ekle(){
	FILE *data=fopen("ogrenciler.txt","a+");
	ogrenci o;
	int id,k=0;
	id = o.ogrenciID;
	if(data == NULL){
		printf("HATA");
	}
	o.kredi = 0; o.derssayisi = 0;
	printf("ID:");
	scanf("%d",&id);
	while(!feof(data)){
	fscanf(data,"%d %s %s %d %d\n", &o.ogrenciID, o.ad, o.soyad, &o.derssayisi, &o.kredi);
	if(id == o.ogrenciID){
			k=1;
		}
	}
	printf("\nAd :");
	scanf(" %s", o.ad);
	printf("\nSoyad :");
	scanf(" %s", o.soyad);
	if(k == 0){
		fprintf(data,"%d %s %s %d %d\n", id, o.ad, o.soyad, o.derssayisi, o.kredi);
		printf("\nEkleme islemi basarili.(Devam etmek icin tiklayiniz)\n");
		getch();
	}else{
		printf("\nEkleme islemi basarisiz, bu ID'de bir ogrenci zaten mevcut.(Devam etmek icin tiklayiniz)\n");
		getch();
	}
	fclose(data);
	
}

void ders_ekle(){
	FILE *data=fopen("dersler.txt","a+");
	FILE *fp=fopen("ogruyesi.txt","r");
	dersler d; ogretimuyesi k;
	int id,x=0,id2,c=0;
	id = d.dersID;
	if(data == NULL){
		printf("HATA");
	}
	printf("Ders ID :");
	scanf("%d", &id);
	while(!feof(data)){
	fscanf(data,"%d %s %d %d %d",&d.dersID,d.dersadi,&d.derskredisi,&d.kontenjan,&d.ogretimuyeID);
	if(id == d.dersID){
			x=1;
		}
	}
	fseek(data,0,SEEK_SET);
	printf("\nDers Ad :");
	scanf(" %s", d.dersadi);
	printf("\nDers Kredi :");
	scanf(" %d", &d.derskredisi);
	printf("\nKontenjan :");
	scanf("%d", &d.kontenjan);
	printf("\nDersi Verecek Ogretim Uye ID:");
	scanf("%d", &d.ogretimuyeID);
	id2 = d.ogretimuyeID;
	while(!feof(fp)){
	fscanf(fp,"%d %s %s %s", &k.ogretimuyeID, k.ogretimad, k.ogretimsoyad, k.unvan);
	if(id2 == k.ogretimuyeID){
			c=1;
		}
	}
	if(c == 1){
		if(x == 0){
			fprintf(data,"\n%d %s %d %d %d", id, d.dersadi, d.derskredisi, d.kontenjan, d.ogretimuyeID);
			printf("\nEkleme islemi basarili.(Devam etmek icin tiklayiniz)\n");
			getch();
		}else{
			printf("\nEkleme islemi basarisiz, bu ID'de bir ders zaten mevcut.(Devam etmek icin tuslayiniz)\n");
			getch();
			}
	}else{
		printf("\nEkleme islemi basarisiz, bu ID'ye sahip bir ogretim uyesi yok.(Devam etmek icin tuslayiniz)\n");
		getch();
	}
	fclose(data); fclose(fp);
	
}
int main(){
	int flag=1;
	while(flag>0){
		printf("\nOgrenci eklemek icin -> 1\n");
		printf("\nOgrenci silmek icin -> 2\n");
		printf("\nDers eklemek icin -> 3\n");
		printf("\nDers silmek icin -> 4\n");
		printf("\nOgretim uyesi eklemek icin -> 5\n");
		printf("\nOgretim uyesi silmek icin -> 6\n");
		printf("\nOgrenciye ders eklemek icin -> 7\n");
		printf("\nOgrenciden ders silmek icin -> 8\n");
		printf("\nOgrencinin aldigi dersleri goruntulemek icin -> 9\n");
		printf("\nOgretim uyesinin verdigi dersleri goruntulemek icin -> 10\n");
		printf("\nBir dersin sinif listesini goruntulemek icin -> 11 \n");
		printf("\nBir ogretim gorevlisinin verdigi bir dersin sinif listesini dosyaya bastirmak icin -> 12\n");
		printf("\nCikis icin 0'a basiniz.\n");
		scanf(" %d", &flag);
		switch(flag){
			case 1:
				ogrenci_ekle();
				break;
			case 2:
				ogrenci_sil();	
				break;
			case 3:
				ders_ekle();	
				break;
			case 4:
				ders_sil();
				break;
			case 5:
				ogretimuyesi_ekle();
				break;
			case 6:
				ogretimuyesi_sil();	
				break;
			case 7:
				ogrenci_ders_ekle();
				break;
			case 8:
				ogrenci_ders_sil();
				break;
			case 9:
				ogrenci_ders_listele();
				break;
			case 10:
				ogretimuyesi_ders_listele();
				break;
			case 11:
				ders_sinif_listesi();
				break;
			case 12:
				dosya_sinif_listesi();
				break;
			default: 
				printf("Bilinmeyen islem..");
				break;
		}
	}
	return 0;
}
