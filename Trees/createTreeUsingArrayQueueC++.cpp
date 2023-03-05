#include <iostream>

using namespace std;

class Node{

public:
	Node* lchild;
	int data;
	Node* rchild;
};

class Queue{
private:
	int size;
	int front;
	int rear;
	Node** Q;

public:
	Queue(int size);
	~Queue();
	bool isFull();
	bool isEmpty();
	void enqueue(Node* x);
	Node* dequeue();
};

Queue::Queue(int size){

	this->size = size;
	front      = -1;
	rear       = -1;
}

Queue::~Queue() {

	delete [] Q;
}

bool Queue::isEmpty(){

	if (front == rear) {

		return true;
	}
	return false;
}

bool Queue::isFull() {

	if (rear == size -1) {

		return true;
	}

	return false;
}

void Queue::enqueue(Node* x){

	if (isFull()){

		cout << "Queue Overflow" <<endl;
	}
	else{

		rear++;
		Q[rear] = x;
	}
}

Node* Queue::dequeue() {
    Node* x = nullptr;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}

class Tree{

private:
	Node* root;

public:
	Tree() { root = nullptr; }
	//~Tree();
	void CreateTree();
	void Preorder() { Preorder(root); }
	void Preorder(Node* p);
	void Inorder() { Inorder(root); }
	void Inorder(Node* p);

	void Postorder() { Postorder(root); }
	void Postorder(Node *p);

	void Levelorder() { Levelorder(root); }
	void Levelorder(Node* p);
	int Height() { return Height(root); }
	int Height(Node* p);
	Node* getRoot() { return root; }
};

void Tree::CreateTree() {

	Node* p;
	Node* t;
	int x;

	Queue q(25);
	root = new Node;

	cout << "Enter root value: " <<flush;
	cin >> x;

	root->data = x;
	root->lchild = nullptr;
	root->rchild = nullptr;

	q.enqueue(root);

	while (! q.isEmpty()) {

		p = q.dequeue();

		cout << "Enter left chile of " << p->data << ": " << flush;
		cin >> x;

		if (x != -1) {

			t = new Node;
			t->data = x;
			t->lchild = nullptr;
			t->rchild = nullptr;
			p->lchild = t;
			q.enqueue(t);
		}

		cout << "Enter right child value of " << p->data << ": " << flush;
		cin >> x;

		if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
	}
}

void Tree::Preorder(Node* p) {

	if (p) {

		cout << p->data << ", " << flush;
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

void Tree::Inorder(Node* p) {

	if (p) {

		Inorder(p->lchild);
		cout << p->data << ", " <<flush;
		Inorder(p->rchild);
	}
}

void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

void Tree::Levelorder(Node *p) {
    Queue q(100);
    cout << root->data << ", " << flush;
    q.enqueue(root);
 
    while (! q.isEmpty()){
        p = q.dequeue();
        if (p->lchild){
            cout << p->lchild->data << ", " << flush;
            q.enqueue(p->lchild);
        }
        if (p->rchild){
            cout << p->rchild->data << ", " << flush;
            q.enqueue(p->rchild);
        }
    }
}

int Tree::Height(Node* p) {

	int l = 0;
	int r = 0;

	if (p == nullptr) {

		return 0;
	}

	l = Height(p->lchild);
	r = Height(p->rchild);

	if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}

int main() {

	Tree t;

	t.CreateTree();

	return 0;
}









