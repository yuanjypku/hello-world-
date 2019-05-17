#include<iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;
template<class T>
class BinaryTree;
template<class T>//ģ�����÷������������������캯�������֡��������������� ��ʱ����������¶������<T>
class BinaryTreeNode//�������ڵ���
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
BinaryTreeNode<T>::BinaryTreeNode()//ȱʡ���캯��
{
	leftChild = rightChild = NULL;
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(T ele)//����ֵ�Ĺ��캯��
{
	element = ele;
	leftChild = rightChild = NULL;
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(T ele, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right)//���캯��
{
	element = ele;
	leftChild = left;
	rightChild = right;
}
template<class T>
void BinaryTreeNode<T>::setValue(T ele)//����ֵ
{
	element = ele;
}
template<class T>
void BinaryTreeNode<T>::setleftChild(BinaryTreeNode<T> *left)//����������
{
	leftChild = left;
}
template<class T>
void BinaryTreeNode<T>::setrightChild(BinaryTreeNode<T> *right)//����������
{
	rightChild = right;
}
template<class T>
BinaryTreeNode<T> * BinaryTreeNode<T>::getleftChild()//�������ӵ�ָ��
{
	return leftChild;
}
template<class T>
BinaryTreeNode<T> * BinaryTreeNode<T>::getrightChild()//����Ҷ��ӵ�ָ��
{
	return rightChild;
}
template<class T>
T BinaryTreeNode<T>::getValue()//ȡֵ
{
	return element;
}
template<class T>
bool BinaryTreeNode<T>::isLeaf()//�ж��Ƿ�����Ҷ
{
	if (leftChild == NULL && rightChild == NULL)
		return 1;
	else
		return 0;
}
template<class T>
int BinaryTreeNode<T>::Degree()//��ڵ�Ķ�
{
	if (leftChild == NULL && rightChild == NULL)
		return 0;
	else if (leftChild != NULL && rightChild != NULL)
		return 2;
	else
		return 1;
}
template<class T>
class BinaryTree//��������
{
private:
	BinaryTreeNode<T> *root;
public:
	BinaryTree();
	~BinaryTree();
	bool isEmpty() const;
	void Visit(BinaryTreeNode<T> *node);
	void CreatTree(BinaryTreeNode<T> * &root);//������
	void ClearTree(BinaryTreeNode<T> *root);//�ͷſռ�
	BinaryTreeNode<T> *getRoot() const;
	void breadthFirstOrder(BinaryTreeNode<T> *root);//������ȱ�����rootΪ���ڵ������
	void preOrder(BinaryTreeNode<T> *root);//���������rootΪ���ڵ������
	void inOrder(BinaryTreeNode<T> *root);//���������rootΪ���ڵ������
	void postOrder(BinaryTreeNode<T> *root);//���������rootΪ���ڵ������
	int CountNode(BinaryTreeNode<T> *root);//����Ҷ�ڵ�
	int Height(BinaryTreeNode<T> *root);//����߶�
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
//�������������ɾ���㷨����Ȼ�Ǵ�������ɾ�� 
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
template<class T>//���������������ע�� 
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
		//��� 
		preOrder(root->leftChild);
		preOrder(root->rightChild);
		//���
	}
}
template<class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> *root)
{
	if (root != NULL)
	{
		//��� 
		inOrder(root->leftChild);
		Visit(root);
		inOrder(root->rightChild);
		//��� 
	}
}
template<class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *root)
{
	if (/*���*/root != NULL)
	{
		/*���*/
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		/*���*/
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
{//��� 
	char ele;
	cin >> ele;
	if (ele != '#')
	{
		root = new BinaryTreeNode<T>;
		root->element = ele;
		CreatTree(root->leftChild);
		CreatTree(root->rightChild);
	}
}//��� 

//Ӧ�õݹ�˼�룺��������Ҷ�������ڸ����������Ҷ����������������Ҷ����֮�ͣ�
//�������ĸ߶ȵ��ڸ�����������߶��������������߶ȵ����ֵ��1. 
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
		//Degree()������pointer��������ΪnullʱΪ0
		//��һ������ΪnullʱΪ1
		//������������ΪnullʱΪ2
		if (pointer->Degree() == 0)
			/*���*/
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
//����ܳ������ֻҪ����ղ���д�˾ͺ�
//��ղ��ֺܶ࣬�������ܾ�һ����
//��Ȼû�й�����Ⱥ����ǰ���Ҫ�󣬵����˴�Ҵ��룬ͬѧ�ǿ��������Ķ�
//����C++�﷨�϶࣬ͬѧ��������������ϻ������ʣ���д�����������C++�﷨
// cin >> �൱�� scanf, cout << �൱��printf�� endl �൱�� \n
int main()
{
	int num;
	BinaryTree<char> tree;
	BinaryTreeNode<char> *root = tree.getRoot();
	//������
	tree.CreatTree(root);

	//�������
	tree.inOrder(root);
	cout << endl;
	//�������
	tree.postOrder(root);
	cout << endl;

	cout << tree.CountNode(root) << endl;
	cout << tree.Height(root) << endl;
	//while (100);
	system("pause");
	return 0;
}