#include <stdio.h>
#include <math.h>

int main()
{
    int imisure,i,j,choise;
    float peso[imisure], lunghezza[imisure],x_i=0.0,y_i=0.0,x_i_2=0.0,x_iy_i=0.0;
    float err_lunghezza,A,B,dev_A,dev_B,delta;

    //presa input
    printf("Inserire numero di misurazioni:\t");scanf("%d",&imisure);
    printf("Inserire valore del peso:\n");
    for ( i = 0; i < imisure; i++)
    {
        printf(" -\t");scanf("%f",&peso[i]);
    }
    printf("Inserire valore della lunghezza:\n");
    for ( i = 0; i < imisure; i++)
    {
        printf(" -\t");scanf("%f",&lunghezza[i]);
    }

    //calcolo delle misure
    for ( i = 0; i < imisure; i++)
    {
        x_i=x_i+peso[i];
        x_i_2=x_i_2+(peso[i]*peso[i]);
        y_i=y_i+lunghezza[i];
        x_iy_i=x_iy_i+(peso[i]*lunghezza[i]);
    }
    printf("Inserisci l'errore massimo della misurazione della lunghezza:\t");scanf("%f",&err_lunghezza);

    //Calcolo dei parametri
    delta=imisure*x_i_2-powf(x_i,2);
    A=(y_i*x_i_2-x_i*x_iy_i)/delta;
    B=(imisure*x_iy_i-x_i*y_i)/delta;
    dev_A=sqrt(pow(err_lunghezza,2)*x_i_2/delta);
    dev_B=sqrt(pow(err_lunghezza,2)*imisure/delta);

    //Risultati
    printf("La retta y=mx+q con:\n\tm = %f con errore = %f\n\tq = %f con errore = %f\n\n",B,dev_B,A,dev_A);
    return 0;
}
