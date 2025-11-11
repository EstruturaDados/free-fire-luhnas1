#include <stdio.h>
#include <string.h>


// Definição da struct Item
struct Item {
    char nome[30];   // Nome do item
    char tipo[20];   // Tipo (Ex: arma, alimento, kit médico)
    int quantidade;  // Quantidade
};

int main() {
    struct Item mochila[10];  // Vetor estático com até 10 itens
    int totalItens = 0;       // Contador de itens cadastrados
    int opcao;                // Controle do menu

    do {
        printf("\n🎒=== CÓDIGO DA ILHA – INVENTÁRIO BÁSICO ===🎮\n");
        printf("1. Adicionar item à mochila\n");
        printf("2. Remover item pelo nome\n");
        printf("3. Listar todos os itens\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpa o ENTER do buffer

        switch (opcao) {
            case 1: {
                if (totalItens < 10) {
                    printf("\n🔹 Adicionar novo item\n");
                    printf("Nome do item: ");
                    fgets(mochila[totalItens].nome, 30, stdin);
                    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = '\0';

                    printf("Tipo do item: ");
                    fgets(mochila[totalItens].tipo, 20, stdin);
                    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = '\0';

                    printf("Quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);
                    getchar(); // limpa o ENTER

                    totalItens++;
                    printf("✅ Item adicionado com sucesso!\n");
                } else {
                    printf("⚠️ Mochila cheia! Capacidade máxima de 10 itens.\n");
                }
                break;
            }

            case 2: {
                if (totalItens == 0) {
                    printf("⚠️ Mochila vazia. Nada para remover.\n");
                } else {
                    char nomeRemover[30];
                    int encontrado = 0;

                    printf("\n🔻 Remover item\n");
                    printf("Digite o nome do item a remover: ");
                    fgets(nomeRemover, 30, stdin);
                    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

                    for (int i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                            // Move os itens seguintes uma posição para trás
                            for (int j = i; j < totalItens - 1; j++) {
                                mochila[j] = mochila[j + 1];
                            }
                            totalItens--;
                            encontrado = 1;
                            printf("🗑️ Item '%s' removido com sucesso!\n", nomeRemover);
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("❌ Item não encontrado.\n");
                    }
                }
                break;
            }

            case 3: {
                if (totalItens == 0) {
                    printf("📦 A mochila está vazia.\n");
                } else {
                    printf("\n📜 ITENS NA MOCHILA:\n");
                    printf("-------------------------------------------------\n");
                    printf("%-20s %-15s %-10s\n", "NOME", "TIPO", "QTD");
                    printf("-------------------------------------------------\n");
                    for (int i = 0; i < totalItens; i++) {
                        printf("%-20s %-15s %-10d\n",
                               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                    }
                    printf("-------------------------------------------------\n");
                }
                break;
            }

            case 4:
                printf("\n🏝️ Saindo do inventário... Até a próxima batalha!\n");
                break;

            default:
                printf("❌ Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
