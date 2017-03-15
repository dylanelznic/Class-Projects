//Dylan Elznic
//CS 1510
//Section 1B

#include "mybstree.h"
#include <iostream>

using namespace std;

template <typename T>
int MyBSTree<T>::size() const
{
	int count = 0;
	recursiveSize(m_root, count);
	return count;
}

template <typename T>
void MyBSTree<T>::recursiveSize(TreeNode<T>* t, int& count) const
{
	if(t != NULL)
	{
		count++;
		recursiveSize(t->m_left, count);
		recursiveSize(t->m_right, count);
	}
	
	return;
}

template <typename T>
bool MyBSTree<T>::isEmpty() const
{
	if(m_root != NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template <typename T>
int MyBSTree<T>::height() const
{
	return recursiveHeight(m_root);
}

template <typename T>
int MyBSTree<T>::recursiveHeight(TreeNode<T>* t) const
{
	if(t != NULL)
	{
		int rightHeight = recursiveHeight(t -> m_right);
		int leftHeight = recursiveHeight(t -> m_left);
		if(rightHeight < leftHeight)
		{
			return leftHeight + 1;
		}
		else
		{
			return rightHeight + 1;
		}
	}
	
	return 0;
}

template <typename T>
int MyBSTree<T>::find(const T& x) const
{
	int level = 0;
	if(m_root == NULL)
	{
		return level;
	}
	level++;
	
	if(m_root -> m_data == x)
	{
		return level;
	}
	else
	{
		if(x >= m_root -> m_data)
		{
			recursiveFind(m_root -> m_right, level, x);
		}
		else
		{
			recursiveFind(m_root -> m_left, level, x);
		}
		
		return level;
	}
}

template <typename T>
void MyBSTree<T>::recursiveFind(TreeNode<T> * t, int & level, const T& x) const
{
	level++;
	if(t == NULL)
	{
		level = -level;
		return;
	}
	
	if((t-> m_data == x))
	{
		return;
	}
	
	else
	{
		if(x >= t -> m_data)
		{
			recursiveFind(t -> m_right, level, x);
		}
		else
		{
			recursiveFind(t -> m_left, level, x);
		}
	}
	
	return;
}

template <typename T>
const T& MyBSTree<T>::findMax() const throw (Oops)
{
	Oops  msg("OOPS! : Tree is Empty!!");
	
	if(m_root == NULL)
	{
		throw msg;
	}
	else
	{
		TreeNode<T>* tmp = m_root;
		while(tmp -> m_right != NULL)
		{
			tmp = tmp -> m_right;
		}
		
		return tmp -> m_data;
	}
}

template <typename T>
const T& MyBSTree<T>::findMin() const throw (Oops)
{
	Oops msg("OOPS! : Tree is Empty!!");
	
	if(m_root == NULL)
	{
		throw msg;
	}
	else
	{
		TreeNode<T>* tmp = m_root;
		while(tmp -> m_left != NULL)
		{
			tmp = tmp -> m_left;
		}
		
		return tmp -> m_data;
	}
}

template <typename T>
void MyBSTree<T>::clear()
{
	recursiveClear(m_root);
	m_root = NULL;
}

template <typename T>
void MyBSTree<T>::recursiveClear(TreeNode<T>* t)
{
	if(t != NULL)
	{
		recursiveClear(t -> m_left);
		recursiveClear(t -> m_right);
		delete t;
		t = NULL;
	}
	
	return;
}

template <typename T>
void MyBSTree<T>::insert(const T& x)
{
	recursiveInsert(x, m_root);
	return;
}

template <typename T>
void MyBSTree<T>::recursiveInsert(const T& x, TreeNode<T>* &t)
{
	if(t == NULL)
	{
		t = new TreeNode<T>(x,NULL,NULL);
		m_size++;
	}
	else if(x < t -> m_data)
	{
		recursiveInsert(x, t -> m_left);
	}
	else if(x > t -> m_data)
	{
		recursiveInsert(x, t -> m_right);
	}
	else
	{
		return;
	}
}

template <typename T>
void MyBSTree<T>::remove(const T& x)
{
	recursiveRemove(m_root, x);
	m_size--;
	return;
}

template <typename T>
void MyBSTree<T>::recursiveRemove(TreeNode<T>* &t, const T& x)
{
	if(x < t->m_data)
	{
		recursiveRemove(t->m_left, x);
	}
	else if(x > t->m_data)
	{
		recursiveRemove(t->m_right, x);
	}
	else 
	{
		if(t->m_left == NULL && t->m_right == NULL)
		{
			delete t;
			t=NULL;
		}
		else if(t->m_left == NULL || t->m_right == NULL)
		{
			TreeNode<T> * ch = t->m_right;
			if(ch == NULL)
			{
				ch = t->m_left;
			}
			delete t;
			t = ch;
		}
		else
		{
			t->m_data = getMax(t->m_left);
			recursiveRemove(t->m_left, t->m_data);
		}
	}
}

template <typename T>
void MyBSTree<T>::printPreOrder() const
{
	recursivePrePrint(m_root);
	return;
}

template <typename T>
void MyBSTree<T>::recursivePrePrint(TreeNode<T> * t) const
{
	if(t != NULL)
	{
		cout<<t -> m_data<<endl;
		
		recursivePrePrint(t -> m_left);
		recursivePrePrint(t -> m_right);
	} 
	return;
}

template <typename T>
void MyBSTree<T>::printPostOrder() const
{
	recursivePostPrint(m_root);
	return;
}

template <typename T>
void MyBSTree<T>::recursivePostPrint(TreeNode<T> * t) const
{
	if(t != NULL)
	{
		recursivePostPrint(t -> m_left);
		recursivePostPrint(t -> m_right);
		
		cout<<t -> m_data<<endl;
	} 
	return;
}

template <typename T>
void MyBSTree<T>::print() const
{
	int pad = 0;
	recursivePrint(m_root, pad);
}

template <typename T>
void MyBSTree<T>::recursivePrint(const TreeNode<T>* t, int pad) const
{
	string s(pad, ' ');
	if (t == NULL)
	cout << endl;
	else{
		recursivePrint(t->m_right, pad+4);
		cout << s << t->m_data << endl;
		recursivePrint(t->m_left, pad+4);
	}  
	return;
}

template <typename T>
const T& MyBSTree<T>::getMax(TreeNode<T> * t)
{
	if(t -> m_right == NULL)
	{
		return t -> m_data;
	}
	else 
	{
		return getMax(t -> m_right);
		}
}