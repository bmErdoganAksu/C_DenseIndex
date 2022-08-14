/*Bu yoðun indeksleme programýnda C programlama dilini kullanýyorum.
Bir veri dosyasýnýn anahtar alanýnda yoðun indeksleme kullanarak bir program oluþturuP ve aþaðýdakileri gerçekleþtirdim
Veri dosyasýnda oluþturulan dizini kullanarak aþaðýdaki iþlemleri yaptým.
	1.index Dosyasi Olustur
	2. Kayit Ekle(Veri Dosyasina)
	3. Ara\n\
	4. Sil (Recycle Bin)
	5. Guncelle
	6. Veri Dosyasini Goruntule
	7. index Dosyasini Goruntule
	8. index Dosyasini Sil
	9. Exit
Aþaðýdaki kayýt yapýsýna sahip ilk dosyasýnda anahtar alan olarak ilk numarasýný belirledim
Alan adi
Ogrenci Numarasý
Ders Kodu
Puan*/
/* Dense Index program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Kayit{
	unsigned bit: 1;
	int	ogrNo;
	int ders_kodu;
	int puan;
	struct Kayit *next;//Kayit nesnesinin bir sonraki elemanýný gmsteren pointer
	}*Kayit_ilkEleman_Pointer=NULL;// ilk elemaný tutan pointer

struct dataKayit{
	unsigned bit: 1;
	int ogrNo;
	int ders_kodu;
	int puan;
}dataKayit_ilkEleman_Pointer;

struct index{
unsigned bit: 1;
int ogrNo;
struct Kayit *indexNext;

struct index *onceki;
struct index *sonraki;
}*index_ilkEleman_Pointer=NULL;

struct dataindex
{
	unsigned bit: 1;
	int ogrNo;
}dataIndexPointer;

//Fonksiyonlar
void indexDosyasiOlustur(void);
void kayitEkle(void);
void veriDosyasiniGoster(void);
void indexDosyasiniGoster(void);
int indeksDosyasiniSil();
Kayit *kayitSil();
Kayit *kayitBul();
void kayitGuncelle(void);

void appendindex(int,int);
void writeindex(int,int);//index dosyasýna yaz
void initindex(void);//baþlangýç indexi
void initdata(void);//baþlangýç verisi
void initIndexDosyasiniVeriDosyasinaBagla(void);

void veriDosyasiniYenidenYaz(Kayit *yaz);
void indexDosyasiniYenidenYaz (void);
void displayData2(void);//


int main(void)
{
	int n;
	//system("clear");
	initindex();//ÝNDEX DOSYASINI AÇ FONKSÝYONU
	initdata();//VERÝ DOSYASINI AÇ FONKSÝYONU
	initIndexDosyasiniVeriDosyasinaBagla();

	while(1)
	{
	printf("\n\t1. index Dosyasi Olustur\n\
	2. Kayit Ekle(Veri Dosyasina)\n\
	3. Ara\n\
	4. Sil (Recycle Bin)\n\
	5. Guncelle\n\
	6. Veri Dosyasini Goruntule\n\
	7. index Dosyasini Goruntule\n\
	8. index Dosyasini Sil\n\
	9. Exit\n\
	10. Veri Dosyasi Adres Goruntule\n");

	printf("\tLutfen bir islem numarasi girin...\n");
	fflush(stdin);
	n=0;
	scanf("%d%*c",&n);
	if(n>=1&&n<=10) {
	  switch(n) 
	 { 
	 case 1:  indexDosyasiOlustur();
	 break; 
	
	 case 2: kayitEkle(); 
	 break; 
	 
	 case 3: initIndexDosyasiniVeriDosyasinaBagla();  kayitBul();//search(); 
	 break;
	  
	 
	 case 4: kayitSil();  
	 break; 
	 
	 case 5: kayitGuncelle(); 
	 break;
	 
	 case 6: veriDosyasiniGoster(); 
	 break; 
	 
	 case 7: indexDosyasiniGoster(); 
	 break; 
	 
	 case 8: indeksDosyasiniSil();
	 break; 
	 
	 case 9: exit(0); 
	 break; 
	 
	 case 10: displayData2();
	 break; 
	 
	 
	 default: printf("Gecersiz secim\n"); 
	 } 
	 } 
	 else { printf("Gecersiz secim\n"); 
	 	exit(0); 
	} 
	} 
} 





void indexDosyasiOlustur(void)
{
	FILE *fpI;
	fpI=fopen("index.txt","a+");
	printf("index dosyasi basariyla olusturuldu\n");
}
	
void kayitEkle() { 
	struct Kayit *ilk=Kayit_ilkEleman_Pointer; 
	int i,j=0; 
	FILE *fpD; int n,count,ch,num; 
	fpD=fopen("veri.bin","ab+"); 
	if(fpD==NULL) 
	printf("veri dosyasi acilamiyor\n"); 
	printf("Kac giris yapilacak?\n"); 
	n=0; 
	scanf("%d",&n); 
	for(;n>0;n--)
	{
		if(Kayit_ilkEleman_Pointer==NULL)
		{
		ilk=(struct Kayit *)malloc(sizeof(struct Kayit));
		Kayit_ilkEleman_Pointer=ilk;
		}
		else
		{
			while(ilk->next!=NULL)
			ilk=ilk->next;
			ilk->next=(struct Kayit *)malloc(sizeof(struct Kayit));//next dinamik hafýza oluþturmaya yarar.
			ilk=ilk->next;
		}
		printf("Bir ogrenci numarasi girin:\n");
		scanf("%d",&num);
		
			dataKayit_ilkEleman_Pointer.bit=1;
			ilk->bit=dataKayit_ilkEleman_Pointer.bit;//tempin bit deerini dataKayit_ilkEleman_Pointer in bit deðerine eesitle
			dataKayit_ilkEleman_Pointer.ogrNo=num;
			ilk->ogrNo=dataKayit_ilkEleman_Pointer.ogrNo;
			printf("Bir ders kodu girin: \n");
			scanf("%d",&dataKayit_ilkEleman_Pointer.ders_kodu);
			ilk->ders_kodu=dataKayit_ilkEleman_Pointer.ders_kodu;//ders kodunu klavyeden aldýðýmýz ders koduna esitliyoruz
			printf("Puan girin:\n");
			scanf("%d",&dataKayit_ilkEleman_Pointer.puan);
			ilk->puan=dataKayit_ilkEleman_Pointer.puan;
			//printf("%d",ilk->puan);//PUANI ALIYOR MU DÝYE KONTROL ETMEK ÝCÝN
			ilk->next=NULL;
			writeindex(dataKayit_ilkEleman_Pointer.ogrNo,dataKayit_ilkEleman_Pointer.bit);//ÝNDEX E YAZDIR FONKSÝYONU
			fwrite(&dataKayit_ilkEleman_Pointer,sizeof(dataKayit_ilkEleman_Pointer),1,fpD);
			
	}
	printf("Kayit basariyla eklendi...\n");
	_fcloseall();
} 
		
		
		
//index dosyasýna yaz.---------------------------------------------------------------------------------------------------//
void writeindex(int ogr_No,int bitDegeri)
		{
		struct index *ilk=index_ilkEleman_Pointer;
		FILE *fpI;
		fpI=fopen("index.txt","a+");
		if(fpI==NULL)
		printf("index dosyasi acilamiyor\n");
		
			if(index_ilkEleman_Pointer==NULL)
			{
			ilk=(struct index *)malloc(sizeof(struct index));
			index_ilkEleman_Pointer=ilk;
			}
			else
			{
			while(ilk->sonraki!=NULL)
			ilk=ilk->sonraki;
			ilk->sonraki=(struct index *)malloc(sizeof(struct index));
			ilk=ilk->sonraki;
			}
		dataIndexPointer.bit=bitDegeri;
		ilk->bit=bitDegeri;
		dataIndexPointer.ogrNo=ogr_No;
		ilk->ogrNo=ogr_No;
		ilk->sonraki=NULL;
		fwrite(&dataIndexPointer,sizeof(dataIndexPointer),1,fpI);
		fclose(fpI);
}
//index dosyasýna yaz sonu--------------------------------------------------------------------------------------------------//

//
void initindex()
{
	FILE *fpI;
	fpI=fopen("index.txt","a+");
		if(fpI==NULL)
		printf("index dosyasi acilamiyor\n");
			while(fread(&dataIndexPointer,sizeof(dataIndexPointer),1,fpI)==1)//index dosyasýndaki ilk elemaný oku
			appendindex(dataIndexPointer.bit,dataIndexPointer.ogrNo);//index dosyasýndaki ilk elemanýn bit deðerini ve öðrenci nosunu bu fonk. kullan.
			fclose(fpI);
}

void appendindex(int bitDegeri,int ogr_No){
	struct index *ilk=index_ilkEleman_Pointer;
	FILE *fpI;
	fpI=fopen("index.txt","a+");
		if(fpI==NULL)
		printf("index dosyasi acilamiyor\n");
			if(index_ilkEleman_Pointer==NULL)//index dosyasýnýn ilk elemaný Null ise
			{
			ilk=(struct index *)malloc(sizeof(struct index));//Hafýzada yer aç
			index_ilkEleman_Pointer=ilk;//index dosyasýnýn ilk elemanýný yukarda tanýmlanan "ilk" pointerine eþitle
			}
			else
			{
			while(ilk->sonraki!=NULL)//ilk elemandan bir sonraki boþ deðilse
			ilk=ilk->sonraki;//elemanýn bir sonrakine git
			ilk->sonraki=(struct index *)malloc(sizeof(struct index));//o elaman için hafýzda yer ayýr
			ilk=ilk->sonraki;//ve o elemanýn da bir sonrakine git
			}
	ilk->bit=bitDegeri;//ilk elemanýn bit deðerini girilen bit deðerine eþitle
	ilk->ogrNo=ogr_No;//ilk elemanýn ogrNo sunu girilen ogr_No ya eþitle
	ilk->sonraki=NULL;//bir sonraki elemanla baðý kopar.
	fclose(fpI);
}

void initdata(){
	FILE *fpV;
	fpV=fopen("veri.bin","ab+");
		if(fpV==NULL)
		printf("veri dosyasi acilamiyor\n");
		while(fread(&dataKayit_ilkEleman_Pointer,sizeof(dataKayit_ilkEleman_Pointer),1,fpV)==1)//veri dosayasýndaki ilk elemaný oku
		{
		struct Kayit *ilk=Kayit_ilkEleman_Pointer;//ilk adýndaki pointere bu okuduðun ilk elemaný koy
			if(Kayit_ilkEleman_Pointer==NULL)//ilk veri elemanýný turan pointer boþ ise
			{
			ilk=(struct Kayit *)malloc(sizeof(struct Kayit));//hafýzada ona yer ayýr
			Kayit_ilkEleman_Pointer=ilk;//ve veri dosyasýndaki ilk elamaný ona eþitle
			}
			else
			{
				while(ilk->next!=NULL)//ilk elemandan bir sonraki boþ deðilse
				ilk=ilk->next;//elemanýn bir sonrakine git
				ilk->next=(struct Kayit *)malloc(sizeof(struct Kayit));//ve ona hafizada yer ayir
				ilk=ilk->next;//bir sonraki elemana git
			}
		ilk->bit=dataKayit_ilkEleman_Pointer.bit;//ilk elemanýn bit deðerini girilen bit deðerine eþitle
		ilk->ogrNo=dataKayit_ilkEleman_Pointer.ogrNo;//ilk elemanýn ogrNo sunu girilen ogr_No ya eþitle
		ilk->ders_kodu=dataKayit_ilkEleman_Pointer.ders_kodu;//ilk elemanýn ders kodunu girilen ders_koduna eþitle
		ilk->puan=dataKayit_ilkEleman_Pointer.puan;//ilk elemanýn puanýný girilen puana eþitle
		ilk->next=NULL;//bir sonraki elemaný null yap
		}
	fclose(fpV);
}


//VERÝ DOSYASINI GÖSTER FONKSÝYONU---------------------------------------------------------------------------------------------------------------------//

void veriDosyasiniGoster(){
	struct Kayit *ilk=Kayit_ilkEleman_Pointer;
	if(Kayit_ilkEleman_Pointer==NULL)
	{
	printf("veri dosyasi bos\n");
	return;
	}
	else
	{
	printf("\tVERi DOSYASI GOSTERiLiYOR\n");
	printf("\tOGRENCi NUMARASi\tDERS KODU \t\tPUAN       \n");
		while(ilk!=NULL)//Baðlý listenin ilk elemanýndan baþla listenin sonundaki NULL elemana varýncaya kadar çalýþ
		{
			if(ilk->bit)//ilk elemanýn bit deðeri 1 ise
			{	
			printf("\t%10d  \t%15d \t%10d\n",ilk->ogrNo,ilk->ders_kodu,ilk->puan);
			ilk=ilk->next;//Listede ilk elemandan sonrakine doðru teker teker ilerle
			}
		}
	}
	
	return;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------//

//ÝNDEX DOSYASINI GÖSTER FONKSÝYONU------------------------------------------------------//
void indexDosyasiniGoster(void){
	struct index *ilk=index_ilkEleman_Pointer;
	if(index_ilkEleman_Pointer==NULL)
	{
	printf("index dosyasi bos\n");
	return;
	}
	else
	{
	printf("\tiNDEX DOSYASI GOSTERiLiYOR\n");
	printf("\tOffset\t\tAnahtar\n ");
		while(ilk!=NULL)//Baðlý index listesinin ilk elemanýndan baþla listenin sonundaki NULL elemana varýncaya kadar çalýþ
		{
			if(ilk->bit)//ilk elemanýn bit deðeri 1 ise
			{
			printf("\t%x\t\t%d\n",&ilk->ogrNo, ilk->ogrNo);//& sembolu koyarak ilk numaralarýýn adreslerini bastýrýyoruz.
			}
			ilk=ilk->sonraki;//Listede ilk elemandan sonrakine doðru teker teker ilerle
		}
	}
	return;
}
//---------------------------------------------------------------------------------------------//

// ÝNDEX DOSYASINI VERÝ DOSYASINA BAÐLAMA FONKSÝYONU
void initIndexDosyasiniVeriDosyasinaBagla(void){
	struct Kayit *kayitILK;
	struct index *indexILK=index_ilkEleman_Pointer;
		if(index_ilkEleman_Pointer==NULL){
		printf("index dosyasi bos");
		return;
		}
		else
		{
			while(indexILK!=NULL)//Baðlý index listesinin ilk elemanýndan baþla listenin sonundaki NULL elemana varýncaya kadar çalýþ
			{
			kayitILK=Kayit_ilkEleman_Pointer;
				while(kayitILK!=NULL)
				{
				if(indexILK->bit==1)//indexin ilk elemanýnýn bit degeri 1 ise
				if(indexILK->ogrNo==kayitILK->ogrNo)//indexdeki elemanýn ogrNo, verideki elemanýn ogrNo ya esitse
				indexILK->indexNext=kayitILK;//indexin ilk elemanýndan sonraki elemaný verideki ilk elemana esitle
				kayitILK=kayitILK->next;//verideki elemanýn bir sonrakine geç
				}
			indexILK=indexILK->sonraki;// elemanýn bir sonrakine geç
			}
		}
}

//BUL- SÝL- GUNCELLE FONKSÝYONLARI---------------------------------------------------------------------------------------------------------------------------------------------//
//BUL FONKSÝYONU------------------------------------------------------------------------------------------------//
Kayit *kayitBul(){
	//eski kod
	FILE *fpV;//fp: geçici dosya, fpI: index dosyasý
	fpV=fopen("veri.bin","ab+");
	//eski kod
	int num;
	printf("Lutfen aramak istediginiz ogrenci numarasi girin\n");
	scanf("%d",&num);
	Kayit *ilk;
	Kayit *iter=Kayit_ilkEleman_Pointer;
		
		if(Kayit_ilkEleman_Pointer->ogrNo==num&&num==1){
			ilk=Kayit_ilkEleman_Pointer;
			printf("\tOGRENCi NUMARASi\tDERS KODU\t PUAN       \n");
			printf("\t%10d  %15d  %15d\n",ilk->ogrNo,ilk->ders_kodu,ilk->puan);
			return Kayit_ilkEleman_Pointer;
		}
		if(Kayit_ilkEleman_Pointer->ogrNo==num&&num!=1){
			ilk=Kayit_ilkEleman_Pointer;
			Kayit_ilkEleman_Pointer=Kayit_ilkEleman_Pointer->next;
			return Kayit_ilkEleman_Pointer;
		}
		while(iter->next!=NULL && iter->next->ogrNo!=num){
			iter=iter->next;
		}
		if(iter->next==NULL){
			printf("ogrNo bulunamadi\n");
			return Kayit_ilkEleman_Pointer;
		}
		else{
			printf("\tOGRENCi NUMARASi\tDERS KODU\t PUAN       \n");
			printf("\t%10d  %15d  %15d\n",iter->next->ogrNo,iter->next->ders_kodu,iter->next->puan);
			return Kayit_ilkEleman_Pointer;
		
		}
		fwrite(&Kayit_ilkEleman_Pointer,sizeof(Kayit_ilkEleman_Pointer),1,fpV);//ilk dosyasýna yazdýr
		fcloseall();
}
//BUL FONKSÝYONU SONU-------------------------------------------------------------------------------------------//



//SÝL FONKSÝYONU ----------------------------------------------------------------------------------------------//
Kayit *kayitSil(){
	//eski kod
	FILE *fpV;//fp: geçici dosya, fpI: index dosyasý
	fpV=fopen("veri.bin","ab+");
	//eski kod
	int num;
	printf("Silinecek bir ogrenci numarasi girin\n");
	scanf("%d",&num);
	Kayit *ilk;
	Kayit *iter=Kayit_ilkEleman_Pointer;
	index *temp2;
	index *iter2=index_ilkEleman_Pointer;
	
		if(Kayit_ilkEleman_Pointer->ogrNo==num){
			ilk=Kayit_ilkEleman_Pointer;
			Kayit_ilkEleman_Pointer=Kayit_ilkEleman_Pointer->next;
			free(ilk);
			return Kayit_ilkEleman_Pointer;
		}
		while(iter->next!=NULL && iter->next->ogrNo!=num){
			iter=iter->next;
		}
		if(iter->next==NULL){
			printf("ogrNo bulunamadi\n"); 
			return Kayit_ilkEleman_Pointer;
		}
		else{
			printf("Ogrenci basariyla silindi...\n\n");
			ilk=iter->next;
			iter->next=iter->next->next;
			free(ilk);
			
			
		}
		fwrite(&Kayit_ilkEleman_Pointer,sizeof(Kayit_ilkEleman_Pointer),1,fpV);//veri dosyasýna yazdýr	
			//fwrite (void *tampon-bellek, size_t veriBytý, size_t veriAdeti, FILE *fp);
		//veriDosyasiniYenidenYaz (Kayit_ilkEleman_Pointer);  //veri dosyasýný yeniden yaz
		//indexDosyasiniYenidenYaz (); //index dosyasýný yeniden yaz
		initIndexDosyasiniVeriDosyasinaBagla();
	
		_fcloseall();
	
}

void kayitGuncelle(void){
	if(Kayit_ilkEleman_Pointer==NULL)//Veri dosyasýnda ilk eleman bos ise
	{
		printf("Veri dosyasi bos!\n");
		return;
	}
	else//veri dosyasý boþ deðilse
	{
	int num,dKodu;
	printf("Guncelleme icin bir ogrenci numarasi girin\n");
	scanf("%d",&num);
		struct Kayit* aranan = Kayit_ilkEleman_Pointer; // Initialize aranan
		if(aranan != NULL){
		while (aranan != NULL)
		{
			if(aranan->ogrNo==num){
				//printf("ogrenci bulundu\n");
				printf("Guncellemek istediginiz ders kodunu girin\n");
				scanf("%d",&dKodu);
				if(aranan->ders_kodu==dKodu){
				printf("Yeni puani girin\n");
				scanf("%d",&aranan->puan);
				//veriDosyasiniYenidenYaz(aranan);
				return;
				}
				
			}
			aranan = aranan->next;
		}
		}
		else{
			printf("ogrenci bulunamadi");
		}
		_fcloseall();
		return;
			
	}
}

//BUL- SÝL- GUNCELLE FONKSÝYONLARI SONU---------------------------------------------------------------------------------------------------------------------------------------//












void veriDosyasiniYenidenYaz(Kayit *yaz){ 
	FILE *fp;
	//struct Kayit *YeniILK;
	struct Kayit *ilk=Kayit_ilkEleman_Pointer;
	fp=fopen("temp.dat","ab+");//geçici dosyayý binary olarak oluþtur ve binary okuma yazma modunda ac
	if(fp==NULL)//eger gecici dosya bos ise
	printf("veri dosyasi bos\n");
	while(ilk!=NULL)//dosyadaki son elemana eriþinceye kadar yani ilk elemandan ilerleyerek null olana kadar
	{
	yaz->bit=ilk->bit;//dataKayit sructdaki ilk elemanýn bitini Kayit structtaki ilk elemanýn bitine eþitle
	yaz->ogrNo=ilk->ogrNo;//dataKayit sructdaki ilk elemanýn ogrNosunu Kayit structtaki ilk elemanýn ogrNosuna eþitle
	yaz->ders_kodu=ilk->ders_kodu;//dataKayit sructdaki ilk elemanýn ders kodunu Kayit structtaki ilk elemanýn ders koduna eþitle
	yaz->puan=ilk->puan;//dataKayit sructdaki ilk elemanýn puaninini Kayit structtaki ilk elemanýn puanina eþitle
	fwrite(&yaz,sizeof(yaz),1,fp);//bu dataKayit structta olusturdugun yeni pointeri dosyaya yaz.
	ilk=ilk->next;//veri dosyasýndaki son elemanlari tek tek gez
	}
	remove("veri.bin");
 	rename("temp.dat","veri.bin");
    printf("index dosyasi, yeniden yazma basarili\n");
	_fcloseall();
	return;
}

	
void indexDosyasiniYenidenYaz(void){ 
	FILE *fp;
	struct dataKayit YeniILK;
	struct index *ilk=index_ilkEleman_Pointer;
	fp=fopen("temp.dat","a+");//geçici dosyayý oluþtur ve ac
	if(fp==NULL)//eger gecici dosya bos ise
	printf("index dosyasi acilamiyor\n");
	while(ilk!=NULL)//index dosyasindaki son elemana erisinceye kadar yani ilk elemandan ilerleyerek null olana kadar
	{
	YeniILK.bit=ilk->bit;
	YeniILK.ogrNo=ilk->ogrNo;
	fwrite(&YeniILK,sizeof(YeniILK),1,fp);
	ilk=ilk->sonraki;
	}
 	remove("index.txt");
 	rename("temp.dat","index.txt");
    printf("index dosyasi, yeniden yazma basarili\n");
	_fcloseall();
	return;
}
// YENÝ FONKSÝYONLARIN SONU--------------------------------------------------------------------------------------------------------------//

//ÝNDEX DOSYASINI SÝL FONKSÝYONU-----------------------------------------------------------------------------------------------------------//
int indeksDosyasiniSil(){

  if(remove("index.txt") == 0){
    fprintf(stdout, "index dosyasi basariyla silindi\n");
  } else {
    fprintf(stderr, "index dosyasi silinemedi\n");
    return  -1;
  }

  return 0;
}

//ÝNDEX DOSYASINI SÝL FONKSÝYONU SONU-----------------------------------------------------------------------------------------------------//


//veri dosyasýný adresler degerleriyle göster fonksiyonu------------------------------------------------------//
void displayData2(void){
struct index *ilk=index_ilkEleman_Pointer;
	if(index_ilkEleman_Pointer==NULL)
	{
	printf("Veri dosyasi bos\n");
	return;
	}
	else
	{
	printf("\tVERi DOSYASI GOSTERiLiYOR\n");
	printf("\tAnahtar\t\tOffset\n ");
	while(ilk!=NULL)
	{
	if(ilk->bit)
	{
	printf("\t%d\t\t%x\n",ilk->ogrNo,&ilk->ogrNo);
	}
	ilk=ilk->sonraki;
	}
	}
}
