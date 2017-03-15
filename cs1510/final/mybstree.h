//Dylan Elznic
//CS 1510
//Section 1B

	#ifndef MYBSTREE_H
	#define MYBSTREE_H
	#include "abstractbstree.h"
	
	template <typename T>
	class TreeNode
	{
		public:
		T m_data;
		TreeNode<T>* m_right;
		TreeNode<T>* m_left;
		
		TreeNode<T>(){m_right = NULL; m_left = NULL;}
		TreeNode<T>(T data, TreeNode<T>* left, TreeNode<T>* right){
			m_data = data;
			m_left = left;
			m_right = right;
		}
		
		TreeNode<T>* clone(const TreeNode<T>* t)
		{
			if(t == NULL)
			{
				return NULL;
			}
			else
			{
				return new TreeNode<T>(t -> m_data, clone(t->m_left), clone(t->m_right));
			}
		}
		
	};
	
	template <typename T>
	class MyBSTree: public AbstractBSTree<T>
	{
		public:
		int m_size;
		TreeNode<T>* m_root;
		
		MyBSTree(){m_size = 0; m_root = NULL;}
		
		
		
		/* --- Big Three --- */
		
		const  MyBSTree<T>& operator=(const MyBSTree<T>& rhs)
		{
			m_root = rhs.m_root -> clone(rhs.m_root);
			
			return *this;
		}
		
		MyBSTree(const MyBSTree<T>& rhs)
		{
			if(&rhs != this)
			{
				m_root = rhs.m_root -> clone(rhs.m_root);
			}
		}
		
		~MyBSTree()
		{
			clear();
		}
		
		/* --- Accessor Operations --- */
		
		int size() const;
		
		bool isEmpty() const;
		
		int height() const;
		
		int find(const T& x) const;
		
		const T& findMax() const throw (Oops);
		
		const T& findMin() const throw (Oops);
		
		const T& getMax(TreeNode<T> * t);
		
		/* --- Mutator Operations --- */
		
		void clear();
		
		void insert(const T& x);
		
		void remove(const T& x);
		
		/* --- Output Operations ---*/
		
		void printPreOrder() const;
		
		void printPostOrder() const;
		
		void print() const;
		
		private:
		
		/* --- Recursive Operations --- */
		
		void recursiveSize(TreeNode<T>* t, int& count) const;
		
		int recursiveHeight(TreeNode<T>* t) const;
		
		void recursiveFind(TreeNode<T> * t, int & level, const T& x) const;
		
		void recursiveClear(TreeNode<T>* t);
		
		void recursiveInsert(const T& x, TreeNode<T>* &t);
		
		void recursiveRemove(TreeNode<T>* &t, const T& x);
		
		void recursivePrePrint(TreeNode<T> * Node) const;
		
		void recursivePostPrint(TreeNode<T> * Node) const;
		
		void recursivePrint(const TreeNode<T>* t, int pad) const;
	};
	
	#include "mybstree.hpp"
#endif