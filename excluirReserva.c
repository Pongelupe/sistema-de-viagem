#include <stdio.h>
#include <string.h>
//*Os parâmetros que são recebido é uma array de 50 de struct InfoVoo, que engloba o struct infoAssento, identidade *//
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
int excluirReserva(infoVoo a[50],int idCliente,int numeroVoo)
{
    int i, j;
    for(i=0;i<50; i++)
    {
        if(numeroVoo==a[i].numeroVoo)
        {
            for(j=0; j<10; j++)
            {
                if (idCliente==a[i].poltrona[i].infoPassageiro)
                {
                    a[i].poltrona[j].infoPassageiro=0;
                    a[i].capacidade--;
                    a[i].poltrona[j].estadoAssento=0;
                    return 2;
                }
            }
            return 1;
        }
    }
    return 0;
}
