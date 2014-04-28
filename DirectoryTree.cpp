// DirectoryTree.cpp : �������̨Ӧ�ó������ڵ㡣
//֮���Գ�֮ΪĿ¼��������Ϊ��unix��ϵͳ�У�Ŀ¼��һ���򵥵ĳ�����ʽ��������
//����ʵ����һ���򵥵�Ŀ¼�ṹ��û�в����ɾ��

#include <iostream>
#include <string>

using namespace std;

/*�������ֵܱ�ʾ��*/
typedef struct TreeNode
{
	string name;//��Ŀ¼��
	struct TreeNode *firstChild;//����
	struct TreeNode *nextSibling;//���ֵ�
}TreeNode;

/**
* ����Ŀ¼��
* @ root ��ָ��
* @ return ����Ŀ¼���ĸ��ڵ��ָ��
*/
TreeNode *createTree(TreeNode *root);


/**
* �������Ŀ¼��
* @ root ��ָ��
* @ level ����
*/
void traverseTreePre(TreeNode *root,int level);


/**
* ��������Ŀ¼��
* @ root ��ָ��
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
	root = new TreeNode();//Ϊ�µĽڵ����ռ�
	cin>>name>>flagL>>flagR;//name �ڵ��name��flagL�������Ƿ�Ϊ�յı�ʶ��flagR�����ֵ��Ƿ�Ϊ�յı�ʶ
	root->name = name;
	if(flagL == 1)
	{//���Ӳ�Ϊ��
		root->firstChild = createTree(root->firstChild);
	}
	else
	{//����Ϊ��
		root->firstChild = NULL;
	}
	if(flagR == 1)
	{//���ֵܲ�Ϊ��
		root->nextSibling = createTree(root->nextSibling);
	}
	else
	{//���ֵ�Ϊ��
		root->nextSibling = NULL;
	}
	return root;
}

void traverseTreePre(TreeNode *root,int level)
{
	for(int i = 0; i < level; i++)
		cout<<"	";
	cout<<root->name<<endl;//�����ʽ���ƣ��������

	if(root->firstChild != NULL)
	{//����
		traverseTreePre(root->firstChild,level+1);
	}
	if(root->nextSibling != NULL)
	{//���ֵ�
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
	cout<<root->name<<endl;//�����ʽ���ƣ��������
	if(root->nextSibling != NULL)
	{
		traverseTreeBack(root->nextSibling,level);
	}
}

/**
��������
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
