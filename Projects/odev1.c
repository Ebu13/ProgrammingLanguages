#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Ebubekir Sýddýk Nazlý
//02210224005 YZL 2.Sýnýf

//Ödevi kaynak kullanarak yaptým hazýr kütüphaneler ödevde kullanýlmýþtýr.

typedef struct 
{
    int bas;
    int *dizi;
    int boyut;

} yigit;

int dolumu(yigit *s) 
{
    return s->bas == s->boyut - 1;
}

int bosmu(yigit *s)
{
    return s->bas == -1;
}

void yigitekleme(yigit *s, int boyut) 
{
    s->boyut = boyut;
    s->bas = -1;
    s->dizi = (int *) malloc(s->boyut * sizeof(int));
}
void ekle(yigit *s, int data)
{
    if (dolumu(s))
    {
        return;
    }
    s->dizi[++s->bas] = data;
}
int sil(yigit *s)
{
    if (bosmu(s)) 
    {
        return -1;
    }
    return s->dizi[s->bas--];
}

int islem(char *ifade)
{
    yigit s;
    yigitekleme(&s, 100);

    char *token = strtok(ifade, " ");
    while (token != NULL)
    {
        if (isdigit(token[0])) 
        
        {
            int num = atoi(token);
            ekle(&s, num);
        } 
        else if (strchr("+-*/", token[0]) != NULL)
        {
            int op1 = sil(&s);
            int op2 = sil(&s);
            switch (token[0]) {
                case '+':
                    ekle(&s, op2 + op1);
                    break;
                case '-':
                    ekle(&s, op2 - op1);
                    break;
                case '*':
                    ekle(&s, op2 * op1);
                    break;
                case '/':
                    ekle(&s, op2 / op1);
                    break;
            }
        } else if (token[0] == '(') 
        {
            ekle(&s, -1);
        } 
        else if (token[0] == ')')
        {
            int sonuc = 0;
            while (!bosmu(&s) && s.dizi[s.bas] != -1)
            {
                sonuc += sil(&s);
            }
            sil(&s); 
            ekle(&s, sonuc);
        }
        token = strtok(NULL, " ");
    }
    int sonuc = 0;
    while (!bosmu(&s)) 
    {
        sonuc += sil(&s);
    }
    return sonuc;
}

int main() {
	int uzunluk = 100;
    char ifade[uzunluk];
    printf("Her tokendan sonra bir bosluk birakin: \n\n\nLutfen aritmetik islemi girin:");
    fgets(ifade, uzunluk, stdin);
    printf("\nSonuc: %d\n", islem(ifade));
}
