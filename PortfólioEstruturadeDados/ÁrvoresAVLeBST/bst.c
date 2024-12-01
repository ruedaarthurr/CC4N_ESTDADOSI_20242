#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura do nó da árvore
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* newNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// Função para inserir um valor na árvore binária de busca
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return newNode(value);
    }
    
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Função para imprimir a árvore em ordem (in-order traversal)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

// Função para liberar a memória da árvore
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    srand(time(NULL));  // Inicializa o gerador de números aleatórios

    Node* root = NULL;

    // Inserindo 50 números aleatórios na árvore
    for (int i = 0; i < 50; i++) {
        int value = rand() % 1000;  // Número aleatório entre 0 e 999
        root = insert(root, value);
    }

    // Imprimindo a árvore em ordem
    printf("Valores na árvore em ordem: \n");
    inorder(root);
    printf("\n");

    // Liberando a memória alocada
    freeTree(root);

    return 0;
}
