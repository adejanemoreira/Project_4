
#define limparTela system("clear")  // No Windows mude para "cls"

typedef struct {
    int codigo;
    char nome[100];
    char ingrediente[100];
    double valor;
} Pizza_t;

typedef struct {
    int codigo;
    int codigoPizzas[100];
    double valorTotal;
} Pedido_t;

int main() {
    const int quantidadeMaximaPizza = 100;  // Quantidade máxima de tipos de piza

    int posicaoPizza = 0;                   // Posição de inserção de novas pizzas
    int posicaoPizzaPedido = 0;             // Posição de inserção no vetor de códigos do pedido
    int codigoPizza = 0;                    // Código para cadastrar o pedido

    Pizza_t pizzas[quantidadeMaximaPizza];  // Vetor com os tipos de pizza

    Pedido_t pedido;                        // Pedido

    char opcao = ' ';                       // Opção do menu principal

    do {
        limparTela;
        printf("MENU \n");
        printf("[ 1 ] - Cadastrar Pizza \n");
        printf("[ 2 ] - Fazer pedido \n");
        printf("[ 0 ] - Sair \n");
        printf("> ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':   // Cadastrar pizza
                limparTela;
                printf("NOVA PIZZA \n");
                printf("Nome: ");
                scanf(" %[^\n]s", pizzas[posicaoPizza].nome);
                printf("Ingrediente: ");
                scanf(" %[^\n]s", pizzas[posicaoPizza].ingrediente);
                printf("Valor: R$ ");
                scanf(" %lf", &pizzas[posicaoPizza].valor);

                pizzas[posicaoPizza].codigo = posicaoPizza + 1;     // Código sequencial a partir de 1
                posicaoPizza += 1;
                break;

            case '2':   // Fazer pedido
                limparTela;
                if (posicaoPizza == 0) {
                    printf("Não tem pizza no catálogo! \n");

                    if (getchar() == '\n') {
                        getchar();
                    }

                    break;
                }

                printf("NOVO PEDIDO \n");

                // Fica pedindo o código da pizza para adicionar no pedido
                do {
                    printf("Código da pizza [ 1 - %i / [0] - Fim ]: ", posicaoPizza);
                    scanf(" %i", &codigoPizza);

                    if (codigoPizza > 0 && codigoPizza <= posicaoPizza) {
                        pedido.codigoPizzas[posicaoPizzaPedido] = codigoPizza;
                        pedido.valorTotal += pizzas[codigoPizza - 1].valor;
                        posicaoPizzaPedido += 1;
                    }
                } while (codigoPizza != 0 && posicaoPizzaPedido < 100);
                
                pedido.codigo = 1;
                break;
        }
    } while (opcao != '0');

    limparTela;
    printf("--------------------------------------------- \n");
    printf("PEDIDO \n");
    printf("Código: %i \n", pedido.codigo);
    printf(" Valor: R$ %.2f \n", pedido.valorTotal);
    printf("--------------------------------------------- \n");

    return 0;
}