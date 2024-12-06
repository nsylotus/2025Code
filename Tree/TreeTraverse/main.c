#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef int ElementType;

typedef struct Tree {
    struct Tree *lchild;
    ElementType data;
    struct Tree *rchild;
} Tree;

Tree *InitTree(int data);

void PreOrder(Tree *tree);

void InOrder(Tree *tree);

void PostOrder(Tree *tree);

Tree *InitTree(int data) {
    Tree *root = (Tree *) malloc(sizeof(Tree));
    root->data = data;
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
}

void PreOrder(Tree *tree) {
    if (tree == NULL) {
        return;
    }
    printf("%d", tree->data);
    PreOrder(tree->lchild);
    PreOrder(tree->rchild);
}

void InOrder(Tree *tree) {
    if (tree == NULL) {
        return;
    }
    InOrder(tree->lchild);
    printf("%d", tree->data);
    InOrder(tree->rchild);
}

void PostOrder(Tree *tree) {
    if (tree == NULL) {
        return;
    }
    PostOrder(tree->lchild);
    PostOrder(tree->rchild);
    printf("%d", tree->data);
}

int main(int argc, char const *argv[]) {
    SetConsoleOutputCP(65001);
    Tree *tree = InitTree(1);
    tree->lchild = InitTree(2);
    tree->rchild = InitTree(3);
    tree->lchild->lchild = InitTree(4);
    tree->lchild->rchild = InitTree(5);
    tree->rchild->lchild = InitTree(6);
    tree->rchild->rchild = InitTree(7);
    printf("先序遍历为:");
    PreOrder(tree);
    printf("中序遍历为:");
    InOrder(tree);
    printf("后序遍历为:");
    PostOrder(tree);
    return 0;
}