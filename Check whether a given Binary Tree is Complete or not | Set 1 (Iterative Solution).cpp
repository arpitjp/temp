// C++ program to check if a given
// binary tree is complete or not
#include <bits/stdc++.h>
using namespace std;

#define MAX_Q_SIZE 500

/* A binary tree node has data, 
pointer to left child and a 
pointer to right child */
class node
{
public:
	int data;
	node *left;
	node *right;
};

/* function prototypes for functions 
needed for Queue data structure. A 
queue is needed for level order tarversal */
node **createQueue(int *, int *);
void enQueue(node **, int *, node *);
node *deQueue(node **, int *);
bool isQueueEmpty(int *front, int *rear);

/* Given a binary tree, return 
true if the tree is complete 
else false */
bool isCompleteBT(node *root)
{
	if(root==NULL)
		return 1;
	queue<node *> q;

	q.push(root);
	bool flag = 0;
	node *t;
	while (!q.empty())
	{
		t = q.front();
		q.pop();
		if (flag == 0) //not on leaves yet
		{
			if(t->left == NULL)
			{
				if(t->right == NULL)
					flag = 1;
				else
					return 0;
			}else
			{
				q.push(t->left);
				if(t->right==NULL)
					flag = 1;
				else
					q.push(t->right);
			}
		}
		else if(flag==1)//on leaves
		{
			if(t->left != NULL || t->right != NULL)
			{
				return 0;
			}
		}
	}
	return 1;
}

/*UTILITY FUNCTIONS*/
node **createQueue(int *front, int *rear)
{
	node **queue = new node *();

	*front = *rear = 0;
	return queue;
}

void enQueue(node **queue, int *rear, node *new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}

node *deQueue(node **queue, int *front)
{
	(*front)++;
	return queue[*front - 1];
}

bool isQueueEmpty(int *front, int *rear)
{
	return (*rear == *front);
}

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
node *newNode(int data)
{
	node *Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

/* Driver code*/
int main()
{
	/* Let us construct the following Binary Tree which 
		is not a complete Binary Tree 
				1 
			/ \ 
			2 3 
			/ \ \ 
		4 5 6 
		*/

	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);

	if (isCompleteBT(root) == true)
		cout << "Complete Binary Tree";
	else
		cout << "NOT Complete Binary Tree";

	return 0;
}

// This code is contributed by rathbhupendra
