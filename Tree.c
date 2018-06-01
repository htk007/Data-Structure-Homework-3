#include <stdio.h>
#include <Tree.h>

/* Agaca d verisini kok olarak koyar */
void Tree_InsertRoot(Tree *tree, char d) {

	int p;

	p = Memory_New(&tree->memory);
	tree->data  [p] = d;
	tree->parent[p] = -1;

    tree->depth[p]=0;

    tree->maximum_depth = 0;

	PointBag_Insert(&tree->bag, p);
}
/* Agaca d verisini pofc ile belirtilen nodun bir cocugu olarak ekler */
void Tree_InsertLeaf(Tree *tree, int pofc, char d) {

	int p;

	p = Memory_New(&tree->memory);
	tree->data  [p] = d;
	tree->parent[p] = pofc;

	if(tree->leafs[pofc])
        {
            tree->leafs[pofc] = 0;
        }

        tree->leafs[p] = 1;

        tree->depth[p] = tree->depth[tree->parent[p]] +1;

        if(tree->depth[p] > tree->maximum_depth)
            tree->maximum_depth = tree->depth[p];

            tree->height[p] = tree->maximum_depth - tree->depth[p];

	PointBag_Insert(&tree->bag, p);
}

/* Agacin p ile belirtilen yapragini siler */
void Tree_DeleteLeaf(Tree *tree, int p) {

    Memory_Del(&tree->memory, p);
	PointBag_Delete(&tree->bag, p);
    tree->depth[p] = 0;
    tree->height[p]= 0;
    tree->leafs[p] = 0;


}

/* Agacin nodlarini (belirtecleri ile beraber) ekrana yazar */
void Tree_Print(Tree *tree) {

	int i, p, pofc;

	PointBag *bag = &tree->bag;
	for(i=0; i<bag->n; i++) {

		p = bag->data[i];
		pofc = tree->parent[p];
		if(pofc < 0) { printf("%c (%d) -> -\n", tree->data[p], p); }
		else {printf("%c (%d) -> %c (%d)\n", tree->data[p], p, tree->data[pofc], pofc); }
	}
	printf("\n");
	printf("PointBag: ");
	PointBag_print(bag);
	printf("\n");
}

/* TODO: Agacin p ile belirtilen nodu bir yaprak midir? */
int  Tree_IsLeaf(Tree *tree, int p) {

    return tree->leafs[p] == 0? 0:1;
}

/* TODO: Agacin p ile belirtilen nodunun derinligini hesaplar */
int Tree_NodeDepth(Tree *tree, int p) {

    return tree->depth[p];
	/* your code here! */
}

/* TODO: Agacin p ile belirtilen nodunun yuksekligini hesaplar */
int Tree_NodeHeight(Tree *tree, int p) {
    return tree->height[p];
	/* your code here! */
}

/* TODO: Agacin yuksekligini hesaplar */
int  Tree_Height(Tree *tree) {
    return tree->maximum_depth;
	/* your code here! */
}

/* Auxillary methods */
void Tree_initialize(Tree *tree)  {

	Memory_initialize(&tree->memory);
}

void Tree_finalize(Tree *tree) {

	int i, p;

	PointBag *bag = &tree->bag;
	for(i=0; i<bag->n; i++) {

		p = bag->data[i];
		Memory_Del(&tree->memory, p);
	}
}

void Tree_print(Tree *tree) {

	int i, p, pofc;

	PointBag *bag = &tree->bag;
	for(i=0; i<bag->n; i++) {

		p = bag->data[i];
		pofc = tree->parent[p];
		if(pofc < 0) { printf("%c -> -\n", tree->data[p]); }
		else {printf("%c -> %c\n", tree->data[p], tree->data[pofc]); }
	}
	printf("\n");
}

/* Memory methods */
void Memory_initialize(Memory *memory) {

	int p;
	for(p=0; p<TREE_CAPACITY; p++) { memory->occupe[p] = 0; }
}

int  Memory_New(Memory *memory) {

	int p;
	for(p=0; p<TREE_CAPACITY; p++) {
		if(!memory->occupe[p]) { memory->occupe[p] = 1; return p; }
	}
	return -1;
}

void Memory_Del(Memory *memory, int p) {

	memory->occupe[p] = 0;
}

int  Memory_Occupied(Memory *memory, int p) {

	return memory->occupe[p];
}
