#include <stdio.h>
#include <math.h>

double stddev(const double value[],const int number_of_value);
double mean(const double value[],const int number_of_value);

int main(int argc, char const *argv[])
{
    int ipeso, ilunghezza,i,j,choise;
    double peso[ipeso], lunghezza[ilunghezza],x_i=0.0,y_i=0.0,x_i_2=0.0,x_iy_i=0.0;
    double m_peso,m_lunghezza,dev_peso,dev_lunghezza,A,B,dev_A,dev_B,delta;

    //presa input
    printf("Inserire numero di misurazioni delle masse:\t");
    scanf("%d",&ipeso);
    printf("Inserire misure:\n");
    for ( i = 0; i < ipeso; i++)
    {
        printf(" -\t");scanf("%lf",&peso[i]);
    }
    printf("Inserire numero di misurazioni della lunghezza:\t");
    scanf("%d",&ilunghezza);
    printf("Inserire misure:\n");
    for ( i = 0; i < ilunghezza; i++)
    {
        printf(" -\t");scanf("%lf",&lunghezza[i]);
    }

    //calcolo delle misure
    for ( i = 0; i < ipeso; i++)
    {
        x_i=x_i+peso[i];
        x_i_2=x_i_2+(peso[i]*peso[i]);
        y_i=y_i+lunghezza[i];
        x_iy_i=x_iy_i+(peso[i]*lunghezza[i]);
    }
    m_peso=mean(peso,ipeso);m_lunghezza=mean(lunghezza,ilunghezza);
    dev_peso=stddev(peso,ipeso);dev_lunghezza=stddev(lunghezza,ilunghezza);
    //Check risultati
    //printf("\nx_i\t%lf\ny_i\t%lf\nx^2_i\t%lf\nx_i*y_i\t%lf\npeso:\t%lf\t%lf\nlunghezza:\t%lf\t%lf",x_i,y_i,x_i_2,x_iy_i,m_peso,dev_peso,m_lunghezza,dev_lunghezza);
    do
    {
        printf("Vuoi cambiare il valore della devstd della lunghezza?[Si=1,no=0]\t");scanf("%d",&choise);
        if (choise == 1)
        {
            printf("Inserisci nuovo valore:\t");scanf("%lf",&dev_lunghezza);
        }
        
    } while (choise==1||choise==0);

    //Calcolo dei parametri
    delta=ipeso*x_i_2-powf(x_i,2);
    A=(y_i*x_i_2-x_i*x_iy_i)/delta;
    B=(ipeso*x_iy_i-x_i*y_i)/delta;
    dev_A=sqrt(pow(dev_lunghezza,2)*x_i_2/delta);
    dev_B=sqrt(pow(dev_lunghezza,2)*ipeso/delta);

    //Risultati
    printf("\nLa massa vale %lf con errore %lf\nLa lunghezza vale %lf con errore %lf\n\n",m_peso,dev_peso,m_lunghezza,dev_lunghezza);
    printf("La retta ?? y=mx+q con:\n\tm = %lf con errore = %lf\n\tq = %lf con errore = %lf\n\n",B,dev_B,A,dev_A);
    return 0;
}

double stddev(const double value[],const int number_of_value){
    double mean , sum = 0.0 , delta = 0.0 , res ; int i;
    // Calculation of the mean for n value
    for (i = 0; i < number_of_value; i++){
        //simple sum of value
        sum = sum + value[i];
    }
    mean = sum / number_of_value;
    /*Calculation of the standard deviation using the mean self calculated
    Using the formula square root( sum( delta(xi-mean)^2)) / number_of_value )*/
    for ( i = 0; i < number_of_value; i++){
        //sum of the square of delta between value and mean
        delta = delta + pow(value[i] - mean,2);
    }
    res = pow( delta / (number_of_value * (number_of_value - 1)) , 0.5); //cool way to say square root
    return res;    
}

double mean(const double value[],const int number_of_value){
    double mean , sum = 0.0 ; int i;
    // Calculation of the mean for n value
    for (i = 0; i < number_of_value; i++){
        //simple sum of value
        sum = sum + value[i];
    }
    mean = sum / number_of_value;
    return mean;
}