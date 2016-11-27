#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// -- Structs
typedef struct {
    int estadoAssento;
    long int infoPassageiro;
} infoAssento ;

typedef struct {
    int capacidade;
    infoAssento poltrona[10];
    int numeroVoo;
} infoVoo;

// -- Funções para controle de fluxo principal
char getOpcao() {
	char ch;

	printf("\n-- Menu de opcoes --\n");
	printf("\na. Inicializar dados");
	printf("\nb. Incluir reserva");
	printf("\nc. Excluir reserva");
	printf("\nd. Imprimir reserva");
	printf("\n\ns. Sair");

	printf("\n\nEscolha a opcao desejada: ");
	ch = getchar();
	return ch;
}

void clearBuffer(char c) {
	while(c != '\n') {
		scanf("%c", &c);
	}
}

void iniciar() {
	// Inicializa variavel para carregar menu
	char opcao;

	while (opcao != 's') {
		opcao = getOpcao();
		clearBuffer(opcao);

		switch (opcao) {
			case 'a':
				printf("Inicializando dados...");
				break;
			case 'b':
				printf("Incluindo reserva...");
				break;
			case 'c':
				printf("Excluindo reserva...");
				break;
			case 'd':
				printf("Imprimindo reserva...");
				break;
            case 's':
				printf("Encerrando...");
				break;
			default:
			    printf("\n-- Digitado: %c\n", opcao);
				printf("A opcao selecionada e invalida, digite novamente");
				break;
		}
	}
}

//-- Inicializar dados

//-- Incluir reserva
int incluirReserva (infoVoo airBus[50],int idCliente, int numeroVoo) {
    int i, j;

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
                        airBus[i].poltrona[j].infoPassageiro = idCliente;
                        return 2;
                    }
                }
            }
        }
    }
    return 0;
}

//-- Excluir reserva
int excluirReserva(infoVoo a[50],int idCliente,int numeroVoo) {
    int i, j;
    for(i=0;i<50; i++) {
        if(numeroVoo==a[i].numeroVoo) {
            for(j=0; j<10; j++) {
                if (idCliente==a[i].poltrona[i].infoPassageiro) {
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

//-- Imprimir reserva
void imprimirReserva(infoVoo a[50],int opcao,int numeroVoo) {
    int i,j;
    int vooInexistente = 1;
    switch (opcao) {
    case 1:
        printf("Numero do voo: %d\n",numeroVoo);
        for ( i=0; i<50; i++) {
            if (numeroVoo==a[i].numeroVoo) {
                vooInexistente=0;
                printf("Numero de reservas do voo: %d\n",a[i].capacidade);
                for ( j=0; j<10; j++) {
                    if (a[i].poltrona[j].estadoAssento==1) {
                        printf("%li\n",a[i].poltrona[j].infoPassageiro);
                    }
                }
            }
        }
        if (vooInexistente==1) {
            printf("Numero de voo inexistente\n");
        }
        break;

    case 2:
        for ( i=0; i<50; i++) {
            if (numeroVoo==a[i].numeroVoo) {
                vooInexistente=0;
                printf("Numero do voo: %d Reservas: %d\n",a[i].numeroVoo,a[i].capacidade);
            }
        }
        if (vooInexistente==1) {
            printf("Numero de voo inexistente\n");
        }
        break;

    case 3:
        for ( i=0; i<50; i++) {
            if (numeroVoo==a[i].numeroVoo) {
                vooInexistente=0;
                printf("Numero do voo: %d\n",a[i].numeroVoo);
                printf("Numero de reservas no voo: %d\n",a[i].capacidade);
                for ( j=0; j<10; j++) {
                    if (a[i].poltrona[j].estadoAssento==1) {
                        printf("%li\n",a[i].poltrona[j].infoPassageiro);
                    }
                }
            }
        }
        if (vooInexistente==1) {
            printf("Numero de voo inexistente\n");
        }
        break;
    }
}

int main() {
    iniciar();
}
