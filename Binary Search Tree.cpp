#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *insert(node *root, int value)
{
    if(root==NULL){
        root=(node*)malloc(sizeof(node));
        root->data=value;
        root->left=NULL;
        root->right=NULL;
    }
    else if(value<root->data){
        root->left=insert(root->left,value);
    }
    else if(value>=root->data){
        root->right=insert(root->right,value);
    }
    return root;
}

void preorder(node *root)
{
    if(root==NULL){
        return;
    }
    cout<<root->data<<'\t';
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<'\t';
    inorder(root->right);
}

void postorder(node *root)
{
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<'\t';
}

//int f;

/*int search(node *root,int value)
{
    if(root==NULL){
        return f;
    }
    if(value==root->data){
        f++;
        return f;
    }
        search(root->left,value);
        search(root->right,value);
}*/


bool search(node *root, int value)
{
    if(root!=NULL){
        if(root->data==value){
            return true;
        }
        else if(root->data>value){
            return search(root->left,value);
        }
        else{
            return search(root->right,value);
        }
    }
    return false;
}


node *max_finder(node *root)
{
    if(root->right==NULL){
        return root;
    }
    return max_finder(root->right);
}

node *min_finder(node *root)
{
    if(root->left==NULL){
        return root;
    }
    return min_finder(root->left);
}


node *Delete(node *root,int value)
{
    if(root == NULL){
        return root;
    }
    else if(value < root->data){
        root->left = Delete(root->left, value);
    }
    else if(value > root->data){
        root->right = Delete(root->right, value);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
            return root;
        }
    else if(root-> left == NULL){
            node *temp = root;
            root = root->right;
            free(temp) ;
            return root;
        }
    else if(root->right == NULL){
            node *temp = root;
            root = root->left;
            free(temp) ;
            return root;
        }
    else{
            node *temp = min_finder(root-> right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
            return root;
        }
    }
}

int main()
{
    int n=0,value;
    node *root;
    root=NULL;
    cout<<"\t\t<<Tree ADT>>\n"<<endl;
    while(n!=9){
        cout<<"\n1. Insert data in tree\n2. Display data in preorder\n3. Display data in inorder\n";
        cout<<"4. Display data in postorder\n5. search\n6. Find Max\n7. Find Min\n8. Delete\n9. Exit\n\nYour choice:";
        cin>>n;
        switch(n)
        {
            case 1:
                cout<<"Input data: ";
                cin>>value;
                root=insert(root,value);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                //f=0;
                cout<<"Enter value to search :";
                cin>>value;
                if(search(root,value)==false){
                    cout<<"\nValue does not exist.\n";
                }
                else{
                    cout<<"\nValue exists.\n";
                }
                break;
            case 6:
                cout<<"\nMax: "<<max_finder(root)->data<<endl;
                break;
            case 7:
                cout<<"\nMin: "<<min_finder(root)->data<<endl;
                break;
            case 8:
                cout<<"\nEnter value to delete: ";
                cin>>value;
                root=Delete(root,value);
                break;
            case 9:
                return 0;

        }
    }
}
