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
int excluirReserva(infoVoo[50],*idCliente,int numeroVoo)
{
    int i, j;
    for(i=0,i<50; i++)
    {
        if(numeroVoo==infoVoo[i].numeroVoo)
        {
            for(j=0;j<10;j++)
            {
                infoVoo[i].poltrona[j].infoPassageiro=0;
                infoVoo.capacidade--;
                infoVoo.poltrona[j].estadoAssento=0;
            }
            return 2;
        }
        return 1;
    }
    return 0;
}
