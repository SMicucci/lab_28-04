#include <stdio.h>
#include <math.h>

float maxarray(float array[],int indice);
float minarray(float array[],int indice);
float mean(float array[],int indice);

int main()
{
    int num,i; float err,test,true_val,true_err,dummy[2];
    printf("Inserire numero di misurazioni del campione misurato:\t");scanf("%d",&num);
    float mis[num];
    printf("Inserisci le misure ottenute:\n");
    for ( i = 0; i < num; i++)
    {
        printf("-\t");scanf("%f",&mis[i]);
    }
    printf("inserisci valore dell'errore del mezzo di misurazione:\t");scanf("%f",&err);
    printf("\n\t");
    test=(maxarray(mis,num)-minarray(mis,num))/2;
    dummy[0]=test;dummy[1]=err;
    true_err=maxarray(dummy,2);
    true_val=mean(mis,num);
    printf("il valore medio e':\t%f, il suo errore e':\t%f\n\n",true_val,true_err);
    return 0;
}

float maxarray(float array[],int indice)
{
    int i; float res;
    for ( i = 0; i < indice; i++)
    {
        if (i==0)
            res=array[i];
        if (array[i]>res)
            res=array[i];
    }
    return res;
}

float minarray(float array[],int indice)
{
    int i; float res;
    for ( i = 0; i < indice; i++)
    {
        if (i==0)
            res=array[i];
        if (array[i]<res)
            res=array[i];
    }
    return res;
}

float mean(float array[],int indice)
{
    float sum=0,res; int i;
    for ( i = 0; i < indice; i++)
    {
        sum+= array[i];
    }
    res=sum/indice;
    return res;
}