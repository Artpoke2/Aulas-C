// Estrutura da Pilha Questão 2 (A) =======================================================================
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

// Funções da Pilha ===
void initStack(Stack* stack) {
    stack->top = NULL;
}

int isStackEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("A Pilha está Vazia.\n");
        return -1;
    }

    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void printStack(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("A Pilha está Vazia.\n");
        return;
    }

    Node* current = stack->top;
    printf("Pilha: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void clearStack(Stack* stack) {
    while (!isStackEmpty(stack)) {
        pop(stack);
    }
}

int getTop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("A Pilha está Vazia.\n");
        return -1;
    }
    return stack->top->data;
}

// =====================================================================
