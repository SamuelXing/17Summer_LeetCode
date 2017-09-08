/*
* Binary Search Tree
* Purpose: implemented a binary search tree and several operations
*
* Author: Samuel Xing, Sep 7, 2017
**/
#include <iostream>

class Tree{
public:
	// initialize a empty tree
	Tree(void): m_root(NULL),m_size(0){}
	
	// destruct tree
	~Tree(void){
		clear();
	}

	// insert data
	void insert(int data){
		insert(new Node(data), m_root);
		++m_size;
	}

	// delete a node in terms of data value, return false if non-exist
	bool erase(int data){
		Node*& node = find(data, m_root);
		if(node){
			insert(node->m_left, node->m_right);
			Node* temp = node;
			node = node->m_right;
			delete temp;
			--m_size;
			return true;
		}
		return false;
	}

	// remove all the nodes that match the data value
	void remove(int data){
		while(erase(data));
	}

	// clear the tree
	void clear(void){
		clear(m_root);
		m_size = 0;
	}

	// update _old value to _new value
	void update(int _old, int _new){
		while(erase(_old))
			insert(_new);
	}

	// determine if data exist of not
	bool find(int data){
		return find(data, m_root) != NULL;
	}

	// inorder traverse
	bool travel(void){
		travel(m_root);
		std::cout << std::endl;
	}

	// get tree size
	size_t size(void){
		return m_size;
	}

	// get tree height
	size_t height(void){
		return height(m_root);
	}

private:
	class Node
	{
	public:
		Node(int data): m_data(data), 
			m_left(NULL), m_right(NULL){}
		~Node(){}
		int m_data;
		Node* m_left;   //left tree
		Node* m_right;	//right tree
	};

	// insert a node to the Tree
	void insert(Node* node, Node*& tree)
	{
		if(!tree)
			tree = node;
		else if(node){
			if(node->m_data < tree->m_data)
				insert(node, tree->m_left);
			else
				insert(node, tree->m_right);
		}
	}

	// find a value in tree, 
	// return the Node that contains the data
	Node*& find(int data, Node*& tree){
		if(!tree)
			return tree;
		else if(data == tree->m_data)
		{
			return tree;
		}
		else if(data< tree->m_data)
		{
			return find(data, tree->m_left);
		}
		else if(data >= tree->m_data)
		{
			return find(data, tree->m_right);
		}
	}

	// clear the tree
	void clear(Node*& tree){
		if(tree){
			clear(tree->m_left);
			clear(tree->m_right);
			delete tree;
			tree = NULL;
		}
	}

	// traverse the tree - inorder
	void travel(Node*& tree){
		if(tree){
			travel(tree->m_left);
			std::cout << tree->m_data << ' ';
			travel(tree->m_right);
		}
	}

	// calculate the height of the tree
	size_t height(Node* tree){
		if(tree){
			size_t lh = height(tree->m_left);
			size_t rh = height(tree->m_right);
			return (lh > rh ? lh : rh) + 1;
		}
		return 0;
	}

	Node* m_root;		//root node
	size_t m_size;		//tree size
};

int main(void){
	Tree tree;
	tree.insert(50);
	tree.insert(100);
	tree.insert(20);
	tree.insert(60);
	tree.insert(80);
	tree.insert(90);
	tree.insert(77);
	tree.travel();

	std::cout << "Tree Size: " << tree.size() << " "
			  << "Tree Height: " << tree.height()<< std::endl;

	tree.erase(77);
	tree.travel();
	tree.insert(77);
	tree.insert(70);
	tree.insert(77);
	tree.insert(70);
	tree.travel();
	tree.remove(70);
	tree.travel();
	tree.insert(55);
	tree.insert(55);
	tree.travel();
	tree.update(55, 65);
	tree.travel();
	std::cout << std::boolalpha << tree.find(50) << std::endl;
	std::cout << tree.find(55) <<std::endl;
	tree.clear();
	tree.travel();
	return 0;
}
