#ifndef _TREE_H_
#define _TREE_H_

#include <PointBag.h>

#define TREE_CAPACITY 100

/* Data types */
typedef struct memory_data { int occupe[TREE_CAPACITY]; } Memory;
typedef struct tree_data {

	char data  [TREE_CAPACITY];
	int  parent[TREE_CAPACITY];
    int maximum_depth;
    int leafs[TREE_CAPACITY]; //leafleri specific olarak tuttuðumuz alan
    int depth[TREE_CAPACITY]; //Her bir düğümün derinliğini tutacak
    int height[TREE_CAPACITY]; //her bir düğümün yükseklğini tutacak
	PointBag bag;
	Memory memory;
} Tree;

/* Operations */
void Tree_InsertRoot(Tree *tree, char d);
void Tree_InsertLeaf(Tree *tree, int pofc, char d);
void Tree_DeleteLeaf(Tree *tree, int p);
int  Tree_IsLeaf(Tree *tree, int p);
int  Tree_NodeDepth(Tree *tree, int p);
int  Tree_NodeHeight(Tree *tree, int p);
int  Tree_Height(Tree *tree);

/* Auxillary methods */
void Tree_Print(Tree *tree);
void Tree_initialize(Tree *tree);
void Tree_finalize(Tree *tree);
void Tree_print(Tree *tree);
void Memory_initialize(Memory *memory);
int  Memory_New(Memory *memory);
void Memory_Del(Memory *memory, int p);

#endif
