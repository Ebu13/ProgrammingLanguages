#include <stdio.h>
#include <stdlib.h>

struct data {
    char data_type[10];
    char index_type[3];
    int alt;
    int ust;
    char variable_name[100];
    int size;
};

main(){
	printf("(float x[500])\n\nYukaridaki parantezdeki gibi diziyi girin :\n\n");
	char dizi[150];
	char size[10];
	int i,j=0;
    fflush(stdin);
    fgets(dizi, 150, stdin);
    struct data c1;
    c1.alt=0;
    for(i=0;dizi[i]!=' ';i++){
    	c1.data_type[i]=dizi[i];
	}
	while(dizi[i]!='['){
		i++;
		if(dizi[i]!='['){
			c1.variable_name[j]=dizi[i];
		}
		j++;
	}
	j=0;
	while(dizi[i]!=']'){
		i++;
		size[j]=dizi[i];
		j++;		
	}
	size[j]=NULL;
	size[j-1]=NULL;
	
	int sayi=0;
	i=0;
	while(size[i]!=NULL){
		sayi*=10;
		sayi+=(((int)size[i])-48);
		i++;
	}
	c1.size=sayi;
	c1.ust=c1.size-1;
	
	printf("%s isimli degiskenin:\n\n\nDizi\n%s\nint\n%d\n%d\n",c1.variable_name,c1.data_type,c1.alt,c1.ust);
	printf("indeks giriniz:");
	int ind;
	scanf("%d",&ind);
	
	
	if(c1.data_type[0]=='i'){
		int i[c1.size];
		
		
		
	}
	else if(c1.data_type[0]=='c'){
		char c[c1.size];
		
		
	}
	else if(c1.data_type[0]=='f'){
		float f[c1.size];
		
		float *ptr = &f[ind]; 
			
    	int offset = (ptr - f) / sizeof(float);
    	
    	printf("%d",offset);
	}
	else if(c1.data_type[0]=='l'){
		long l[c1.size];
		
		
	}
	else if(c1.data_type[0]=='s'){
		short s[c1.size];
		
		
	}
	else if(c1.data_type[0]=='d'){
		double d[c1.size];
		
		
	}
	
	
	return 0;
}
