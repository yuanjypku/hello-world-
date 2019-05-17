#include<iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;
template<class T>
class BinaryTree;
template<class T>//模板类用法：除了在命名、构造函数的名字、析构函数的名字 的时候，其他情况下都必须加<T>的
class BinaryTreeNode//二叉树节点类
{
	friend class BinaryTree<T>;
	friend void CreatTree(BinaryTreeNode<T> *root);
private:
	T element;
	BinaryTreeNode<T> *leftChild;
	BinaryTreeNode<T> *rightChild;
public:
	BinaryTreeNode();
	BinaryTreeNode(T ele);
	BinaryTreeNode(T ele, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right);
	void setValue(T ele);
	void setleftChild(BinaryTreeNode<T> *left);
	void setrightChild(BinaryTreeNode<T> *right);
	BinaryTreeNode<T> * getleftChild();
	BinaryTreeNode<T> * getrightChild();
	T getValue();
	bool isLeaf();
	int Degree();
};
template<class T>
BinaryTreeNode<T>::BinaryTreeNode()//缺省构造函数
{
	leftChild = rightChild = NULL;
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(T ele)//仅填值的构造函数
{
	element = ele;
	leftChild = rightChild = NULL;
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(T ele, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right)//构造函数
{
	element = ele;
	leftChild = left;
	rightChild = right;
}
template<class T>
void BinaryTreeNode<T>::setValue(T ele)//设置值
{
	element = ele;
}
template<class T>
void BinaryTreeNode<T>::setleftChild(BinaryTreeNode<T> *left)//设置左子树
{
	leftChild = left;
}
template<class T>
void BinaryTreeNode<T>::setrightChild(BinaryTreeNode<T> *right)//设置右子树
{
	rightChild = right;
}
template<class T>
BinaryTreeNode<T> * BinaryTreeNode<T>::getleftChild()//获得左儿子的指针
{
	return leftChild;
}
template<class T>
BinaryTreeNode<T> * BinaryTreeNode<T>::getrightChild()//获得右儿子的指针
{
	return rightChild;
}
template<class T>
T BinaryTreeNode<T>::getValue()//取值
{
	return element;
}
template<class T>
bool BinaryTreeNode<T>::isLeaf()//判断是否是树叶
{
	if (leftChild == NULL && rightChild == NULL)
		return 1;
	else
		return 0;
}
template<class T>
int BinaryTreeNode<T>::Degree()//算节点的度
{
	if (leftChild == NULL && rightChild == NULL)
		return 0;
	else if (leftChild != NULL && rightChild != NULL)
		return 2;
	else
		return 1;
}
template<class T>
class BinaryTree//二叉树类
{
private:
	BinaryTreeNode<T> *root;
public:
	BinaryTree();
	~BinaryTree();
	bool isEmpty() const;
	void Visit(BinaryTreeNode<T> *node);
	void CreatTree(BinaryTreeNode<T> * &root);//建立树
	void ClearTree(BinaryTreeNode<T> *root);//释放空间
	BinaryTreeNode<T> *getRoot() const;
	void breadthFirstOrder(BinaryTreeNode<T> *root);//广度优先遍历以root为根节点的子树
	void preOrder(BinaryTreeNode<T> *root);//先序遍历以root为根节点的子树
	void inOrder(BinaryTreeNode<T> *root);//中序遍历以root为根节点的子树
	void postOrder(BinaryTreeNode<T> *root);//后序遍历以root为根节点的子树
	int CountNode(BinaryTreeNode<T> *root);//计算叶节点
	int Height(BinaryTreeNode<T> *root);//计算高度
};
template<class T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
}
template<class T>
BinaryTree<T>::~BinaryTree()
{
	//delete []root;
	ClearTree(root);
}
//广度优先搜索的删除算法，依然是从上往下删。 
template<class T>
void BinaryTree<T>::ClearTree(BinaryTreeNode<T> *root)
{
	using std::queue;
	queue<BinaryTreeNode<T> *> nodeQueue;
	BinaryTreeNode<T> *pointer = root;
	if (pointer != NULL)
		nodeQueue.push(pointer);
	while (!nodeQueue.empty())
	{
		pointer = nodeQueue.front();
		nodeQueue.pop();
		if (pointer->leftChild != NULL)
			nodeQueue.push(pointer->leftChild);
		if (pointer->rightChild != NULL)
			nodeQueue.push(pointer->rightChild);
		delete pointer;
	}
}
template<class T>
BinaryTreeNode<T> *BinaryTree<T>::getRoot()const
{
	return root;
}
template<class T>//广度优先搜索！！注意 
void BinaryTree<T>::breadthFirstOrder(BinaryTreeNode<T> *root)
{
	using std::queue;
	queue<BinaryTreeNode<T> *> nodeQueue;
	BinaryTreeNode<T> *pointer = root;
	if (pointer != NULL)
		nodeQueue.push(pointer);
	while (!nodeQueue.empty())
	{
		pointer = nodeQueue.front();
		nodeQueue.pop();
		Visit(pointer);
		if (pointer->leftChild != NULL)
			nodeQueue.push(pointer->leftChild);
		if (pointer->rightChild != NULL)
			nodeQueue.push(pointer->rightChild);
	}
}
template<class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *root)
{
	if (root != NULL)
	{
		Visit(root);
		//填空 
		preOrder(root->leftChild);
		preOrder(root->rightChild);
		//填空
	}
}
template<class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> *root)
{
	if (root != NULL)
	{
		//填空 
		inOrder(root->leftChild);
		Visit(root);
		inOrder(root->rightChild);
		//填空 
	}
}
template<class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *root)
{
	if (/*填空*/root != NULL)
	{
		/*填空*/
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		/*填空*/
		Visit(root);
	}
}
template<class T>
void BinaryTree<T>::Visit(BinaryTreeNode<T> *node)
{
	cout << node->element;
}
template<class T>
void BinaryTree<T>::CreatTree(BinaryTreeNode<T> * &root)
{//填空 
	char ele;
	cin >> ele;
	if (ele != '#')
	{
		root = new BinaryTreeNode<T>;
		root->element = ele;
		CreatTree(root->leftChild);
		CreatTree(root->rightChild);
	}
}//填空 

//应用递归思想：二叉树的叶子数等于根结点左子树叶子数与根结点右子树叶子数之和；
//二叉树的高度等于根结点左子树高度与根结点右子树高度的最大值加1. 
template<class T>
int BinaryTree<T>::CountNode(BinaryTreeNode<T> *root)
{
	using std::queue;
	int count = 0;
	queue<BinaryTreeNode<T> *> nodeQueue;
	BinaryTreeNode<T> *pointer = root;
	if (pointer != NULL)
		nodeQueue.push(pointer);
	while (!nodeQueue.empty())
	{
		pointer = nodeQueue.front();
		nodeQueue.pop();
		//Degree()函数在pointer左右子树为null时为0
		//有一个子树为null时为1
		//两个子树都不为null时为2
		if (pointer->Degree() == 0)
			/*填空*/
			count++;
		if (pointer->leftChild != NULL)
			nodeQueue.push(pointer->leftChild);
		if (pointer->rightChild != NULL)
			nodeQueue.push(pointer->rightChild);
	}
	return count;
}
template<class T>
int BinaryTree<T>::Height(BinaryTreeNode<T> *root)
{
	if (root == NULL)
		return 0;
	int left = Height(root->leftChild);
	int right = Height(root->rightChild);
	if (left > right)
		return left + 1;
	else
		return right + 1;
}
//代码很长，大家只要把填空部分写了就好
//填空部分很多，但基本能举一反三
//虽然没有广度优先和深度前序的要求，但给了大家代码，同学们可以自行阅读
//代码C++语法较多，同学们有问题可以在上机课提问，填写代码基本避免C++语法
// cin >> 相当于 scanf, cout << 相当于printf， endl 相当于 \n
int main()
{
	int num;
	BinaryTree<char> tree;
	BinaryTreeNode<char> *root = tree.getRoot();
	//创建树
	tree.CreatTree(root);

	//中序遍历
	tree.inOrder(root);
	cout << endl;
	//后序遍历
	tree.postOrder(root);
	cout << endl;

	cout << tree.CountNode(root) << endl;
	cout << tree.Height(root) << endl;
	//while (100);
	system("pause");
	return 0;
}
