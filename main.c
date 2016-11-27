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
    // Declaração de variáveis necessárias para o funcionamento do sistema
    infoVoo airBus[50];
    long int idCliente;
    int numeroVoo;

    // Inicializa variavel para carregar menu
    char opcao;

	while (opcao != 's') {
		opcao = getOpcao();
		clearBuffer(opcao);

		switch (opcao) {
			case 'a':
				printf("Inicializando dados...");
                inicializarDados(airBus);
				break;
			case 'b':
			    printf("Digite somente os numeros da sua identidade:\n");
			    scanf("%li", &idCliente);
			    printf("\nAgora digite o numero do voo:\n");
			    scanf("%d", &numeroVoo);
				printf("Incluindo reserva...");
				incluirReserva(airBus, idCliente, numeroVoo);
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
int inicializarDados(infoVoo airBus[50]){
    int i, j , n = 1000;

    for(i = 0; i < 50; i++) {
        airBus[i].capacidade = 10;
        airBus[i].numeroVoo = n;
        n++;
    }

    printf("\nDados inicializados com sucesso!\n");
}

//-- Incluir reserva
int incluirReserva(infoVoo airBus[50],int idCliente, int numeroVoo) {
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
int excluirReserva(infoVoo airBus[50],int idCliente,int numeroVoo) {
    int i, j;
    for(i=0;i<50; i++) {
        if(numeroVoo==airBus[i].numeroVoo) {
            for(j=0; j<10; j++) {
                if (idCliente==airBus[i].poltrona[i].infoPassageiro) {
                    airBus[i].poltrona[j].infoPassageiro=0;
                    airBus[i].capacidade--;
                    airBus[i].poltrona[j].estadoAssento=0;
                    return 2;
                }
            }
            return 1;
        }
    }
    return 0;
}

//-- Imprimir reserva
void imprimirReserva(infoVoo airBus[50],int opcao,int numeroVoo) {
    int i,j;
    int vooInexistente = 1;
    switch (opcao) {
    case 1:
        printf("Numero do voo: %d\n",numeroVoo);
        for ( i=0; i<50; i++) {
            if (numeroVoo==airBus[i].numeroVoo) {
                vooInexistente=0;
                printf("Numero de reservas do voo: %d\n",airBus[i].capacidade);
                for ( j=0; j<10; j++) {
                    if (airBus[i].poltrona[j].estadoAssento==1) {
                        printf("%li\n",airBus[i].poltrona[j].infoPassageiro);
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
            if (numeroVoo==airBus[i].numeroVoo) {
                vooInexistente=0;
                printf("Numero do voo: %d Reservas: %d\n",airBus[i].numeroVoo,airBus[i].capacidade);
            }
        }
        if (vooInexistente==1) {
            printf("Numero de voo inexistente\n");
        }
        break;

    case 3:
        for ( i=0; i<50; i++) {
            if (numeroVoo==airBus[i].numeroVoo) {
                vooInexistente=0;
                printf("Numero do voo: %d\n",airBus[i].numeroVoo);
                printf("Numero de reservas no voo: %d\n",airBus[i].capacidade);
                for ( j=0; j<10; j++) {
                    if (airBus[i].poltrona[j].estadoAssento==1) {
                        printf("%li\n",airBus[i].poltrona[j].infoPassageiro);
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
