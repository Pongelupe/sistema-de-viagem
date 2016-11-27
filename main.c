#include <stdio.h>
#include <string.h>

char getOpcao() {
	char opcao;

	printf("\n-- Menu de opções --");
	printf("\na. Inicializar dados");
	printf("\nb. Incluir reserva");
	printf("\nc. Excluir reserva");
	printf("\nd. Imprimir reserva");
	printf("\n\ns. Sair");

	printf("Escolha a opção desejada: \n");
	scanf("%c", opcao);
	return opcao;
}

void inicializa() {
	// Inicializa variavel para carregar menu
	char opcao = 'x';

	while (opcao != 's') {
		opcao = getOpcao();

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
			default:
				printf("A opção selecionada é invalida, digite novamente");
				break;
		}	
	}
}

int main() {

}