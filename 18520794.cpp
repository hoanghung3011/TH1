#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int n;
struct node
{
	int data;
	node *next;
};
struct list
{
	node *head;
	node *tail;
};
void init(list &l) 
{
	l.head = l.tail = NULL;
}
node* CreateNode(int x)
{
	node *p = new node;
	if (p == NULL) exit(1);
	p->next = NULL;
	p->data = x;
	return p;
}
bool emptyCheck(list l)
{
	if (l.head == NULL) return true;
	return false;
}
void AddFirst(list &l, int new_data)
{
	node *new_node = CreateNode(new_data);
	if (emptyCheck(l)) l.head = l.tail = new_node;
	else
	{
		new_node->next = l.head;
		l.head = new_node;
	}
}
void AddEnd(list &l, int new_data)
{
	node *new_node = CreateNode(new_data);
	if (emptyCheck(l)) AddFirst(l, new_data);
	else
	{
		l.tail->next = new_node;
		l.tail = new_node;
	}
}
node *search(list l, int pre)
{
	node *p = l.head;
	while (p != NULL)
	{
		if (p->data == pre) return p;
		else p = p->next;
	}
	return NULL;
}
void AddAfter(list &l, int new_node, int pre)
{
	node *prev_node = search(l, pre);
	if (prev_node != NULL)
	{
		node *new_node = new node;
		new_node->next = prev_node->next;
		prev_node->next = new_node;
	}
	else cout << "Khong tim thay node co gia tri = gia tri truoc";
}
void SearchK(list l)
{
	int k;
	cout << "Nhap k = " << endl;
	cin >> k;
	node *new_node = search(l, k);
	if (new_node != NULL) cout << "Tim thay k o vi tri : " << new_node->data;
	else cout << "Khong tim thay K ";
}
void delFirst(list &l)
{
	if (!emptyCheck(l))
	{
		node *p = l.head;
		l.head = l.head->next;
		delete p;
	}
}
void delEnd(list &l)
{
	node *prev_node = l.head;
	node *new_node = new node;
	while (prev_node != l.tail) prev_node = prev_node->next;
	new_node = prev_node;
	prev_node = prev_node->next;
	l.tail = new_node;
	l.tail->next = NULL;
	delete(prev_node);
}
void delK(list &l)
{
	int k;
	cout << "Nhap k = " << endl ;
	cin >> k;  
	node *temp = l.head, *prev_node;
	if (temp != NULL && temp->data == k)
	{
		delFirst(l);
		return;
	}
	while (temp != NULL && temp->data != k)
	{
		prev_node = temp;
		temp = temp->next;
	}
	if (temp == NULL) return;
	prev_node->next = temp->next;
}
void inputList(list &l) {
	cout << "\nnhap so phan tu ban dau cua list: "; cin >> n;
	for (int i = 1; i <= n; i++) AddEnd(l, i);
}
void outputList(list l)
{
	node *p = l.head;
	while (p != NULL)
	{	
		cout << " " << p->data << " ";
		p = p->next;
	}
}
void menu() 
{
	list l;
	init(l);
	int k, x, y, choice;
	
	do 
	{
		cout << endl;
		cout << "1. Nhap danh sach" << endl;
		cout << "2. Xuat danh sach" << endl;
		cout << "3. Xoa node chua K" << endl;
		cout << "4. Xoa node dau" << endl;
		cout << "5. Xoa node  cuoi " << endl;
		cout << "6. Tim K" << endl;
		cin >> choice;
		switch (choice) 
		{
		case 0: break;
		case 1: inputList(l); break;
		case 2: outputList(l); break;
		case 3: delK(l); n--; break;
		case 4: delFirst(l); n--; break;
		case 5: delEnd(l); n--; break;
		case 6: SearchK(l); break;
		}
	} while (choice != 0);
}

int main() 
{
	menu();
	return 0;
}
