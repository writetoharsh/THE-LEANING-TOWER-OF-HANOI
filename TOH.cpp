#include <bits/stdc++.h>
using namespace std;

int n;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

struct Node* GetNewNode(int data)
{
    struct Node* newNode=new Node();
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node* Insert(struct Node* root, int data)
{
    if(root==NULL)
    {
        return GetNewNode(data);
    }
    else
    {
        root->left=Insert(root->left, data);
    }
    return root;
}

void TowerOfHanoi(struct Node* root, int n)
{
    if(root==NULL)
    {
        return;
    }
    stack<Node*> from;
    stack<Node*> aux;
    queue<Node*> to;
    from.push(root);
    
    int count=1;
    while(!from.empty())
    {
        struct Node* current=from.top();
        aux.push(current);
        if(current->left!=NULL)
        {
            from.push(current->left);
        }
        from.pop();
        cout<<" Move disk "<<count<<" from initital rod to auxiliary rod"<<"\n";
        count=count+1;
        if(count==n+1)
        {
            break;
        }
    }
    
    while(!aux.empty())
    {
        struct Node* temp=aux.top();
        to.push(temp);
        aux.pop();
        cout<<" Move disk "<<n<<" from auxiliary rod to final rod"<<"\n";
        n=n-1;
    }
}

int main()
{
    struct Node* root=NULL;
    int i;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        root=Insert(root, i);
    }
    TowerOfHanoi(root, n);
    return 0;
}
