// ==========================================================================================

//Questão 2  ================================================================================

#include <stdio.h>
#include <stdlib.h>
#include "2_pilha.h"
#include "2_fila.h"
#include "2_arvore.h"

// Função principal
int main() {
    int opcao, subOpcao;
    Stack pilha;
    Queue fila;
    TreeNode *arvore = NULL;

    do {
        printf("► Escolha a Estrutura a ser Executada:\n");
        printf("[1] Executar Pilha\n");
        printf("[2] Executar Fila\n");
        printf("[3] Executar Árvore\n");
        printf("[0] Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                initStack(&pilha);
                do {
                    printf("\nEstrutura da Pilha\n");
                    printf("[1] Empilhar\n");
                    printf("[2] Desempilhar\n");
                    printf("[3] Imprimir Pilha\n");
                    printf("[4] Limpar Pilha\n");
                    printf("[5] Imprimir Topo da Pilha\n");
                    printf("[0] Voltar\n");
                    printf("Opção: ");
                    scanf("%d", &subOpcao);

                    switch (subOpcao) {
                        case 1:
                            printf("Digite o Valor a ser Empilhado: ");
                            int value;
                            scanf("%d", &value);
                            push(&pilha, value);
                            break;
                        case 2:
                            printf("Valor Desempilhado: %d\n", pop(&pilha));
                            break;
                        case 3:
                            printStack(&pilha);
                            break;
                        case 4:
                            clearStack(&pilha);
                            printf("A Pilha foi Limpa.\n");
                            break;
                        case 5:
                            printf("Topo da Pilha: %d\n", getTop(&pilha));
                            break;
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opção inválida.\n");
                    }
                } while (subOpcao != 0);
                break;
            case 2:
                initQueue(&fila);
                do {
                    printf("\nEstrutura da Fila\n");
                    printf("[1] Enfileirar\n");
                    printf("[2] Desenfileirar\n");
                    printf("[3] Imprimir Fila\n");
                    printf("[4] Limpar Fila\n");
                    printf("[5] Maior Elemento da Fila\n");
                    printf("[6] Menor Elemento da Fila\n");
                    printf("[0] Voltar\n");
                    printf("Opção: ");
                    scanf("%d", &subOpcao);

                    switch (subOpcao) {
                        case 1:
                            printf("Digite o Valor a ser Enfileirado: ");
                            int value;
                            scanf("%d", &value);
                            enqueue(&fila, value);
                            break;
                        case 2:
                            printf("Valor Desenfileirado: %d\n", dequeue(&fila));
                            break;
                        case 3:
                            printQueue(&fila);
                            break;
                        case 4:
                            clearQueue(&fila);
                            printf("A Fila foi Limpa.\n");
                            break;
                        case 5:
                            printf("Maior Elemento da Fila: %d\n", getQueueMax(&fila));
                            break;
                        case 6:
                            printf("Menor Elemento da Fila: %d\n", getQueueMin(&fila));
                            break;
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opção inválida.\n");
                    }
                } while (subOpcao != 0);
                break;
            case 3:
                do {
                    printf("\nEstrutura da Árvore\n");
                    printf("[1] Inserir Elemento\n");
                    printf("[2] Imprimir em Ordem\n");
                    printf("[3] Buscar Elemento\n");
                    printf("[4] Imprimir Sub-Árvore Direita, Raiz, Sub-Árvore Esquerda\n");
                    printf("[5] Maior Elemento da Árvore\n");
                    printf("[0] Voltar\n");
                    printf("Opção: ");
                    scanf("%d", &subOpcao);

                    switch (subOpcao) {
                        case 1:
                            printf("Digite o Valor a ser Inserido na Árvore: ");
                            int value;
                            scanf("%d", &value);
                            arvore = insert(arvore, value);
                            break;
                        case 2:
                            printf("Árvore em Ordem: ");
                            inOrderTraversal(arvore);
                            printf("\n");
                            break;
                        case 3:
                            printf("Digite o Valor a ser Buscado: ");
                            int searchValue;
                            scanf("%d", &searchValue);
                            if (findElement(arvore, searchValue)) {
                                printf("O Elemento está Presente na Árvore.\n");
                            } else {
                                printf("O Elemento não está Presente na Árvore.\n");
                            }
                            break;
                        case 4:
                            printf("Sub-Árvore Direita, Raiz, Sub-Árvore Esquerda: ");
                            inOrderTraversal(arvore);
                            printf("\n");
                            break;
                        case 5:
                            printf("Maior Elemento da Árvore: %d\n", findMax(arvore));
                            break;
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opção inválida.\n");
                    }
                } while (subOpcao != 0);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
