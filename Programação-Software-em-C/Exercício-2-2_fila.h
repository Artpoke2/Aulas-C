// Estrutura da Fila Questão 2 (B) =====================================
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Funções da Fila  ===
void initQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("A Fila está Vazia.\n");
        return -1;
    }

    QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    return data;
}

void printQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("A Fila está Vazia.\n");
        return;
    }

    QueueNode* current = queue->front;
    printf("\nFila: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void clearQueue(Queue* queue) {
    while (!isQueueEmpty(queue)) {
        dequeue(queue);
    }
}

int getQueueMax(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("A Fila está Vazia.\n");
        return -1;
    }

    int max = queue->front->data;
    QueueNode* current = queue->front->next;
    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

int getQueueMin(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("A Fila está Vazia.\n");
        return -1;
    }

    int min = queue->front->data;
    QueueNode* current = queue->front->next;
    while (current != NULL) {
        if (current->data < min) {
            min = current->data;
        }
        current = current->next;
    }
    return min;
}

// ====================================================================
