#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura do nó da árvore AVL
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    int height;  // A altura do nó (necessária para balanceamento)
} Node;

// Função para criar um novo nó
Node* newNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    node->height = 1;  // Novo nó é sempre inserido como folha
    return node;
}

// Função para obter a altura de um nó
int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Função para calcular o fator de balanceamento (balance factor)
int balanceFactor(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Função para rotacionar para a direita
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Realizando a rotação
    x->right = y;
    y->left = T2;

    // Atualizando as alturas
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    // Retornando o novo nó raiz
    return x;
}

// Função para rotacionar para a esquerda
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Realizando a rotação
    y->left = x;
    x->right = T2;

    // Atualizando as alturas
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    // Retornando o novo nó raiz
    return y;
}

// Função para balancear o nó
Node* balance(Node* node) {
    int balance = balanceFactor(node);

    // Caso 1: Se o nó ficou desbalanceado para a esquerda (Left-Left)
    if (balance > 1 && node->value < node->left->value) {
        return rightRotate(node);
    }

    // Caso 2: Se o nó ficou desbalanceado para a direita (Right-Right)
    if (balance < -1 && node->value > node->right->value) {
        return leftRotate(node);
    }

    // Caso 3: Se o nó ficou desbalanceado para a esquerda-direita (Left-Right)
    if (balance > 1 && node->value > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso 4: Se o nó ficou desbalanceado para a direita-esquerda (Right-Left)
    if (balance < -1 && node->value < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Retorna o nó sem alterações se ele estiver balanceado
    return node;
}

// Função para inserir um valor na árvore AVL
Node* insert(Node* node, int value) {
    // Passo 1: Realizar a inserção normal (como em uma árvore binária de busca)
    if (node == NULL) {
        return newNode(value);
    }

    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    } else {
        // Não permitir valores duplicados
        return node;
    }

    // Passo 2: Atualizar a altura do nó atual
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // Passo 3: Balancear o nó e retornar a árvore balanceada
    return balance(node);
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

    // Inserindo 50 números aleatórios na árvore AVL
    for (int i = 0; i < 50; i++) {
        int value = rand() % 1000;  // Número aleatório entre 0 e 999
        root = insert(root, value);
    }

    // Imprimindo a árvore em ordem
    printf("Valores na árvore AVL em ordem: \n");
    inorder(root);
    printf("\n");

    // Liberando a memória alocada
    freeTree(root);

    return 0;
}
