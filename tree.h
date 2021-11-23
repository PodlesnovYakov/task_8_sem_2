#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
struct tree
{
    int id;
    int ves;
    tree *left;
    tree *right;

};
void add(tree*&root,int x)
{

    if(root == NULL)
    {
        root = new tree;
        root->id = x;
        root->ves = rand() % 3 - 1;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        if(root->id < x)
        {
            add(root->right,x);
        }
        else
        {
            add(root->left,x);
        }

    }

}
void show(tree *root, int n)
{
    if (root != NULL)
    {
        show(root->left, n + 1);
        cout << setw(n*3)<< root->id <<"("<<root->ves<<")"<< endl;
        show(root->right, n + 1);
    }
}
tree* poisk(tree*root)
{
    if(root->left == NULL)
    {
        return root;
    }
    else
    {
        poisk(root->left);
    }
}
void pop(tree *&root,int x)
{
    if(x > root->id)
    {
        pop(root->right,x);
    }
    else if(x < root->id)
    {
        pop(root->left,x);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            tree *kmp = root;
            root = NULL;
            delete(kmp);
        }
        else
        {
            if(root->left == NULL && root->right != NULL)
            {
                tree *smp = root;

                root->ves = root->right->ves;
                root->id = root->right->id;
                root = root->right;
                delete(smp);
            }
            else if(root->right == NULL && root->left != NULL)
            {
                tree *tmp = root;
                root->ves = root->left->ves;
                root->id = root->left->id;
                root = root->left;
                delete(tmp);
            }
            else
            {

                root->id = poisk(root->right)->id;
                root->ves = poisk(root->right)->ves;
                pop(root->right,root->id);

            }
        }
    }
}
void indz(tree *root,int s,int *a,int i)
{
    if(root->left != NULL && root->right != NULL)
    {
        s +=root->ves;
        a[i] = root->id;
        indz(root->left,s,a,i+1);
        indz(root->right,s,a,i+1);

    }
    else if(root->left != NULL && root->right == NULL)
    {
        s +=root->ves;
        a[i] = root->id;
        indz(root->left,s,a,i+1);
    }
    else if(root->left == NULL && root->right != NULL)
    {
        s +=root->ves;
        a[i] = root->id;
        indz(root->right,s,a,i+1);
    }
    else
    {
        s+=root->ves;
        a[i] = root->id;
        if(s == 0)
        {
            for(int j = 0;j < i+1;j++){
                cout << a[j]<<" ";
            }
            cout<<endl;
        }
    }
}

#endif // TREE_H_INCLUDED
