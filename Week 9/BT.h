#pragma once
#include<conio.h>
// Dynamic Array Implementation

struct TreeNode {
	int info;
	TreeNode* left, * right, * parent;
	TreeNode() {}
	TreeNode(int value) :info(value), left(NULL), right(NULL), parent(NULL) {}
};

typedef TreeNode* NP;

class BT {
public:
	
	NP root;
	int nodeCount;

	BT();
	BT(int info);
	~BT();
	void deleteBT(NP node);
	/*  BT(BT left, int info, BT right); */
	bool IsEmpty();
	bool isleft(NP node);
	bool isright(NP node);
	TreeNode* maketree(int info);
	void setleft(NP node, int info);
	void setright(NP node, int info);
	void preorder(NP node);
	void inorder(NP node);
	void postorder(NP node);
	NP search(NP node,int value);
	NP sibling(NP node);
	NP getRoot();
};