#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int estadoAssento;
    long int infoPassageiro;
} infoAssento;

typedef struct {
    int capacidade;
    infoAssento poltrona[10];
    int numeroVoo;
} infoVoo;

int incluirReserva (infoVoo airBus[50], int idCliente, int numeroVoo) {
    for (i = 0; i < 50; i++) {
        if (numeroVoo == airBus[i].numeroVoo) {
            if (airBus[i].capacidade == 10) {
                return 1;
            }
            else {
                for (j = 0; j < 10; j++) {
                    if (airBus[i].poltrona[j].estadoAssento == 0) {
                        airBus[i].capacidade++;
                        airBus[i].poltrona[j].estadoAssento = 1;
                        airBus[i].poltrona[j].infoPassageiro = *idCliente;
                        return 2;
                    }
                }
            }
        }
    }
    return 0;
}
