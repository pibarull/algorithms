
#include "stdafx.h"
#include <string.h>
#include <stdio.h>
//#include <cstdio>
class Node
{
public:
	Node(int el, Node* parent) : data(el), parent(parent)
	{
		left = NULL;
		right = NULL;
	}
	
	int data, price = 0, amount = 0;
	char *name = "paper";
	Node *left, *right, *parent;
};

template <typename T>
class BinTree
{
	int _size;
	Node* root;

	void add_h(T, char*, int, int, Node*&);
	void inorderTravarsal1(Node*&);
	void* find(T el);
	void* min(Node*&);
	void* max(Node*&);

public:
	BinTree() : root(NULL)
	{};
	int TotalPrice = 0;
	void add(T, char[20], int, int);
	void remove(T, int);
	int size();
	void inorderTravarsal();
	bool find1(T el);

};

template <typename T>
void BinTree<T> ::add(T el, char *name, int amount, int price)
{
	add_h(el, name, amount, price, root);
}


template <typename T>
void BinTree<T> ::add_h(T el, char *name, int amount, int price, Node*& ro)
{
	
	if (find1(el)) {
		Node *current = (Node*)find(el);
		int c_price = current->price;
		if(current->price == price)
			current->amount += amount;
		else
			printf("Error: Cant't be more than 1 product with different prices");
		return;
	}
	
		if (ro == NULL)
		{
			ro = new Node(el, ro);
			ro->name = name;
			ro->amount = amount;
			ro->price = price;
			_size++;
			return;
		}

		if (ro->right == NULL && el > ro->data)
		{
			ro->right = new Node(el, ro);
			ro->right->name = name;
			ro->right->amount = amount;
			ro->right->price = price;
			_size++;
		}

		if (ro->left == NULL && el < ro->data)
		{
			ro->left = new Node(el, ro);
			ro->left->name = name;
			ro->left->amount = amount;
			ro->left->price = price;
			_size++;
		}

		if (el > ro->data)
			add_h(el, name, amount, price, ro->right);
		if (el < ro->data)
			add_h(el, name, amount, price, ro->left);
}

template<typename T>
void* BinTree<T> ::min(Node*& ro)
{
	Node *min = ro;
	while (min != NULL)
		min = min->left;
	return min;

}

template<typename T>
void* BinTree<T> ::max(Node *& ro)
{
	while (ro != NULL)
		ro = ro->right;
	return ro;
}

template<typename T>
 void* BinTree<T> ::find(T el)
{
	Node *current = root;
	while (current != NULL)
	{
		if (el < current->data)
			current = current->left;
		else if (el > current->data)
			current = current->right;
		else
			return current;
	}
	return NULL;
	
}

 template<typename T>
 bool BinTree<T> ::find1(T el)
 {
	 Node *current = root;
	 while (current != NULL)
	 {
		 if (el < current->data)
			 current = current->left;
		 else if (el > current->data)
			 current = current->right;
		 else
			 return true;
	 }
	 return false;

 }

template<typename T>
void BinTree<T>::remove(T el, int amount)
{
	
	Node *current = (Node*)find(el);
		
	Node *parent = current->parent;
	TotalPrice = amount * current->price;

	int c_amount = current->amount - amount;
	//current->amount -= amount;
	if (c_amount < 0) {
		printf("\nError: Amount of product you chose is bigger than is in the shop\n");
		return;
	}
	if(c_amount >= 0)
		current->amount = c_amount;
	
	if (current->amount == 0)
	{

		if (current == NULL)
			return;
		else if (current->left == NULL && current->right == NULL)
		{
			if (parent->data < current->data)
				parent->right = NULL;
			else
				parent->left = NULL;


			delete current;
			current = NULL;
			_size--;
		}
		else if (current->left == NULL || current->right == NULL)
		{
			if (current->left == NULL)
			{
				if (parent->data > current->data)
					parent->left = current->right;
				else
					parent->right = current->right;
				delete current;
				current = NULL;
				_size--;
			}
			else
			{
				if (parent->data > current->data)
					parent->left = current->left;
				else
					parent->right = current->left;
				delete current;
				current = NULL;
				_size--;
			}
		}
		else
		{
			Node* min = current->right;
			if (parent->data < current->data) //мы в правой части
			{
				while (min->left != NULL) //находим минимум в правой ветке
					min = min->left;

				parent->right = min;
				min->left = current->left;
				if (min->parent != current)                   //   30 - current                  min - не потомок current'a
				{											  //    \ 
					min->right = current->right;              //     40 - min - потомок current'a
					min->parent->left = NULL;//min->left = current->left;				         
				}
				//parent->left = min;// (Node*)min(current);
			}
			else											  //мы в левой части   
			{
				while (min->left != NULL)
					min = min->left;
				//parent->right = min;//(Node*)min(current);

				parent->left = min;
				min->left = current->left;
				if (min->parent != current)              //min - не потомок current'а
				{
					min->right = current->right;
					min->parent->left = NULL;
				}
			}
			delete current;
			current = NULL;
			_size--;
		}
	}
}

template<typename T>
int BinTree<T>::size()
{
	return _size;
}

template<typename T>
void BinTree<T>:: inorderTravarsal1(Node*& ro)
{
	if (ro == NULL)
		return;
	
	inorderTravarsal1(ro->left);
	printf("%s, price = %i p, amount = %i ",ro->name, ro->price, ro->amount );
	printf("\n");
	inorderTravarsal1(ro->right);
}

int hash_f(char *name) {
	int id = 0;
	int i = 0;
	while (i <= strlen(name)) {
		id = (id + name[i++] * 211) & 255;
	}
	return id;
}

template<typename T>
void BinTree<T>::inorderTravarsal()
{
	printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
	printf("SHOP:\n\n");
	inorderTravarsal1(root);
	printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
}

int main()
{
	BinTree<int> tree;

	//Зададим изнчачальный каталог магазина
	char *u = "carpet";
	tree.add(hash_f(u), u, 2, 500);
	u = "pen";
	tree.add(hash_f(u), u, 14, 15);
	u = "tabel";
	tree.add(hash_f(u), u, 6, 320);
	u = "carrot";
	tree.add(hash_f(u), u, 400, 30);
	u = "beef";
	tree.add(hash_f(u), u, 20, 450);
	u = "laptop";
	tree.add(hash_f(u), u, 60, 20000);

	char name[20];// = "paper";
	int price = 0, amount;
	
	/*
	price = hash_f("pen");
	printf("id = %i\n\n", price);
	price = hash_f("pencil");
	printf("id = %i\n\n", price);
	price = hash_f("peeeen");
	printf("id = %i\n\n", price);
	price = hash_f("pen123");
	printf("id = %i\n\n", price);
	price = hash_f("pen");
	printf("id = %i\n\n", price);
	*/

	/*scanf_s("%s", name, 20);
	//name = "pen";
	printf("%s", name);
	*/

	for (;;)
	{
		printf("\n");
		int c;
		printf("press:\n");
		printf("0 - exit the shop\n");
		printf("1 - show cathalog\n");
		printf("2 - add something for selling\n");
		printf("3 - buy something\n");
		scanf_s("%i", &c);
		if (c == 0)
			return c;
		else if (c == 1)
			tree.inorderTravarsal();
		else if (c == 2)
		{
			printf("write the thing you wanna add to the shop: ");
			scanf_s("%s", name, 20);
			printf("write the price of this thing: ");
			scanf_s("%i", &price);
			printf("write the amount: ");
			scanf_s("%i", &amount);

			tree.add(hash_f(name), name, amount, price);//hash_f(name), name, amount);
/*
			int id = 0;
			int i = 0;
			while (i !=strlen(name)){
				id = id + name[i] * 256 + name[i++];
				i++;
			}
			tree.add(id, name, amount);*/
		}
		else if(c == 3) {
			//tree.inorderTravarsal();
			printf("choose the thing you wanna buy: ");
			scanf_s("%s", name, 20);
			printf("choose amount: ");
			scanf_s("%i", &amount);
			tree.remove(hash_f(name), amount);//hash_f(name));
			printf("\nTotal price: %i\n", tree.TotalPrice);
		}
		else
			printf("\ntry again\n");
	}

		/*tree.add(10);
		tree.add(60);
		tree.add(80);
		tree.add(110);
		tree.add(30);
		tree.add(90);
		tree.add(40);
		tree.add(45);
		tree.add(70);
		tree.add(120);
		tree.add(20);
		tree.add(15);
		tree.add(25);
		tree.add(5);
		tree.add(35);
		*/

		/*
		tree.inorderTravarsal();
		int a;
		printf("\nWrite what element to remove - ");
		scanf_s("%i", &a);
		tree.remove(a);

		printf("\nAfter removing the element:");
		tree.inorderTravarsal();
		*/
	printf("\n");
	
}


