// DirectoryTree.cpp : 定义控制台应用程序的入口点。
//之所以称之为目录树，是因为在unix等系统中，目录的一个简单的抽象形式就是类树
//代码实现了一个简单的目录结构，没有插入和删除

#include <iostream>
#include <string>

using namespace std;

/*左孩子右兄弟表示法*/
typedef struct TreeNode
{
	string name;//该目录名
	struct TreeNode *firstChild;//左孩子
	struct TreeNode *nextSibling;//右兄弟
}TreeNode;

/**
* 创建目录树
* @ root 根指针
* @ return 返回目录树的根节点的指针
*/
TreeNode *createTree(TreeNode *root);


/**
* 先序遍历目录树
* @ root 根指针
* @ level 层数
*/
void traverseTreePre(TreeNode *root,int level);


/**
* 后续遍历目录树
* @ root 根指针
*/
void traverseTreeBack(TreeNode *root,int level);


int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode *root = NULL;
	root = createTree(root);
	cout<<"Pre Order:"<<endl;
	traverseTreePre(root,0);
	cout<<"Back Order:"<<endl;
	traverseTreeBack(root,0);
	return 0;
}


TreeNode *createTree(TreeNode *root)
{
	string name;
	int flagL,flagR;
	root = new TreeNode();//为新的节点分配空间
	cin>>name>>flagL>>flagR;//name 节点的name，flagL：左孩子是否为空的标识，flagR：右兄弟是否为空的标识
	root->name = name;
	if(flagL == 1)
	{//左孩子不为空
		root->firstChild = createTree(root->firstChild);
	}
	else
	{//左孩子为空
		root->firstChild = NULL;
	}
	if(flagR == 1)
	{//右兄弟不为空
		root->nextSibling = createTree(root->nextSibling);
	}
	else
	{//右兄弟为空
		root->nextSibling = NULL;
	}
	return root;
}

void traverseTreePre(TreeNode *root,int level)
{
	for(int i = 0; i < level; i++)
		cout<<"	";
	cout<<root->name<<endl;//输出格式控制，先序访问

	if(root->firstChild != NULL)
	{//左孩子
		traverseTreePre(root->firstChild,level+1);
	}
	if(root->nextSibling != NULL)
	{//右兄弟
		traverseTreePre(root->nextSibling,level);
	}
	//return;
}

void traverseTreeBack(TreeNode *root,int level)
{
	if(root->firstChild != NULL)
	{
		traverseTreeBack(root->firstChild,level + 1);
	}
	for(int i = 0; i < level; i++)
		cout<<"	";
	cout<<root->name<<endl;//输出格式控制，后序访问
	if(root->nextSibling != NULL)
	{
		traverseTreeBack(root->nextSibling,level);
	}
}

/**
测试数据
usr 1 0
mark 1 1
book 1 1
ch1.r 0 1
ch2.r 0 1
ch3.r 0 0
course 1 1
cop3530 1 0
fail96 1 1
sy1.r 0 0
spr97 1 1
sy1.r 0 0
sum97 1 0
sy1.r 0 0
jumk.c 0 0
alex 1 1
junk.c 0 0
bill 1 0
work 0 1
course 1 0
cop3212 1 0
fall96 1 1
grades 0 1
prog1.r 0 1
prog2.r 0 0
fall97 1 0
prog2.r 0 1
prog1.r 0 1
grades 0 0
**/
