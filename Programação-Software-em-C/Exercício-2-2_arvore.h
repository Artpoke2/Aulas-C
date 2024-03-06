// Estrutura da Árvore Questão 2 (C) ==================================
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Funções da Árvore  ===
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

//Questão 2 (C - I)

int findElement(TreeNode* root, int data) {
    if (root == NULL) {
        return 0;
    } else if (data < root->data) {
        return findElement(root->left, data);
    } else if (data > root->data) {
        return findElement(root->right, data);
    } else {
        return 1;
    }
}

//Questão 2 (C - II)
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->right);
        printf("%d ", root->data);
        inOrderTraversal(root->left);
    }
}

//Questão 2 (C - III)
int findMax(TreeNode* root) {
    if (root == NULL) {
        printf("A Árvore está Vazia.\n");
        return -1;
    } else if (root->right == NULL) {
        return root->data;
    } else {
        return findMax(root->right);
    }
}

// ====================================================================
