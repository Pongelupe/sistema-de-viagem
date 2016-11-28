#include <stdio.h>
#include <string.h>
typedef struct
{
    int estadoAssento;
    long int infoPassageiro;
} infoAssento ;

typedef struct
{
    int capacidade;
    infoAssento poltrona[10];
    int numeroVoo;
} infoVoo;
void imprimirReserva(infoVoo a[50],int opcao,int numeroVoo)
{
    int i,j;
    int vooInexistente = 1;
    switch (opcao)
    {
    case 1:
        printf("Numero do voo: %d\n",numeroVoo);
        for ( i=0; i<50; i++)
        {
            if (numeroVoo==a[i].numeroVoo)
            {
                vooInexistente=0;
                printf("Numero de reservas do voo: %d\n",a[i].capacidade);
                for ( j=0; j<10; j++)
                {
                    if (a[i].poltrona[j].estadoAssento==1)
                    {
                        printf("%li \n",a[i].poltrona[j].infoPassageiro);
                    }
                }
            }
        }
        if (vooInexistente==1)
        {
            printf("Numero de voo inexistente\n");
        }
        break;

    case 2:
        for ( i=0; i<50; i++)
        {
            if (numeroVoo==a[i].numeroVoo)
            {
                vooInexistente=0;
                printf("\nNumero do voo: %d \nReservas: %d\n",a[i].numeroVoo,a[i].capacidade);
            }
        }
        if (vooInexistente==1)
        {
            printf("Numero de voo inexistente\n");
        }
        break;

    case 3:
        for ( i=0; i<50; i++)
        {
            if (numeroVoo==a[i].numeroVoo)
            {
                vooInexistente=0;
                printf("Numero do voo: %d\n",a[i].numeroVoo);
                printf("Numero de reservas no voo: %d\n",a[i].capacidade);
                for ( j=0; j<10; j++)
                {
                    if (a[i].poltrona[j].estadoAssento==1)
                    {
                        printf("%li\n",a[i].poltrona[j].infoPassageiro);
                    }
                }
            }
        }
        if (vooInexistente==1)
        {
            printf("Numero de voo inexistente\n");
        }
        break;
    }
}
