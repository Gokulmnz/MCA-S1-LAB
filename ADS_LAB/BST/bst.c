// import header files
#include <stdio.h>
#include <stdlib.h>

// Structure creation for nodes of tree
typedef struct Tree_Node
{
    int data;
    struct Tree_Node *Rchild;
    struct Tree_Node *Lchild;
} node;

// Declaring variables
node *root = NULL, *new, *temp, *prt;
int lim;

// creating a Binary Search Tree
void Create()
{
    // User input for limit
    printf("Enter limit of your Tree : ");
    scanf("%d", &lim);

    // insertion of Nodes
    while (lim > 0)
    {
        {
            // Memory allocation
            new = (node *)malloc(sizeof(node));
            new->Rchild = NULL;
            new->Lchild = NULL;

            printf("Enter your data : ");
            scanf("%d", &new->data);

            // If Root is NULL
            if (root == NULL)
                root = new;

            else
            {
                temp = root;

                // Finding where to Insert the node
                while (temp != NULL)
                {
                    prt = temp;
                    if (temp->data < new->data)
                        temp = temp->Rchild;

                    else
                        temp = temp->Lchild;
                }

                // Insert the node
                if (new->data < prt->data)
                    prt->Lchild = new;
                else
                    prt->Rchild = new;
            }
        }
        lim--;
    }
}

// traversing a Binary Search Tree
// 3 Types : Pre Order, Post Order, In order

void in_order(node *root)
{
    // Function Exit at Null  Root Value
    if (root == NULL)
        return;

    // Traversing the Left Subtree
    in_order(root->Lchild);

    // printing the Value
    printf("%d\t", root->data);

    // Traversing the Left Subtree
    in_order(root->Rchild);
}

void pre_order(node *root)
{
    if (root == NULL)
        return;

    printf("%d\t", root->data);
    pre_order(root->Lchild);
    pre_order(root->Rchild);
}

void post_order(node *root)
{
    if (root == NULL)
        return;

    post_order(root->Lchild);
    post_order(root->Rchild);
    printf("%d\t", root->data);
}

// Insertion
void Insert()
{
    new = (node *)malloc(sizeof(node)); // Initializing a Node
    new->Rchild = NULL;
    new->Lchild = NULL;

    printf("Enter your data : ");
    scanf("%d", &new->data);

    if (root == NULL) // For First node of the tree
        root = new;
    else
    {
        temp = root;
        while (temp != NULL)
        {
            prt = temp;
            if (temp->data > new->data)
                temp = temp->Lchild;
            else
                temp = temp->Rchild;
        }

        if (new->data > prt->data)
            prt->Rchild = new;
        else
            prt->Lchild = new;
    }
}

node *search(int s)
{
    node *seach = root;
    while (seach != NULL)
    {
        if (seach->data == s)
            return seach;
        else if (seach->data > s)
            seach = seach->Lchild;
        else
            seach = seach->Rchild;
    }
    return NULL;
}

node *successor(int ele)
{
    node *ptr, *ptr1;
    ptr = search(ele);

    if (ptr->Rchild != NULL)
    {
        ptr1 = ptr->Rchild;
        while (ptr1->Lchild != NULL)
            ptr1 = ptr1->Lchild;
    }
    else
        return NULL;
    return ptr1;
}

void display()
{
}

node *parentof(int dat)
{
    node *pnt = search(dat);
    temp = root;
    while (temp != pnt)
    {
        prt = temp;
        if (temp->data > dat)
            temp = temp->Lchild;
        else
            temp = temp->Rchild;
    }
    if (dat == root->data)
        return NULL;
    return prt;
}

void Delete()
{
    node *dell, *hi, *yt;
    int s;
    printf("Enter the data to be deleted : ");
    scanf("%d", &s);
    dell = search(s);

    // if (parentof(s) == NULL) // If To be deleted Node is Root Node!
    // {
    //     if (dell->Rchild != NULL)
    //     {
    //         temp = successor(s);
    //         prt = paerentof(temp->data);
    //         if (temp->Rchild != NULL)
    //             prt->Lchild = temp->Rchild;
    //         else
    //             prt->Lchild = NULL;
    //         root = temp;
    //         root->Lchild = dell->Lchild;
    //         if (paerentof(temp->data) == root)
    //         {
    //             temp->Rchild = temp->Rchild;
    //         }
    //         else
    //         {
    //             if (temp->Rchild != NULL)
    //                 prt->Lchild = new->Rchild;
    //             else
    //                 prt->Lchild = NULL;
    //             root->Rchild = dell->Rchild;
    //         }
    //     }
    //     else
    //         root = root->Lchild;
    // }

    if (parentof(s) == NULL) // If To be deleted Node is Root Node!
    {
        if (dell->Rchild != NULL)
        {
            temp = successor(root->data);
            new = parentof(temp->data);
            if (parentof(temp->data) == root)
            {
                temp->Rchild = temp->Rchild;
            }
            else
            { // Can Be Replaced as new->Rchild = temp->Rchild
                if (temp->Rchild != NULL)
                    new->Rchild = temp->Rchild;
                else
                    new->Rchild = NULL;
                temp->Rchild = root->Rchild;
            }
            root = temp;
            root->Lchild = dell->Lchild;
        }
        else
            root = root->Lchild;
    }

    else if (dell->Rchild == NULL && dell->Lchild == NULL) // For Deleting from leaf Node!
    {
        temp = parentof(s);
        if (temp->data > dell->data)
            temp->Lchild = NULL;
        else
            temp->Rchild = NULL;
    }

    else if (dell->Rchild != NULL && dell->Lchild != NULL) // For Deleting nodes with 2 Children
    {
        new = successor(s);
        yt = parentof(new->data);
        hi = parentof(s);
        if (parentof(new->data) == dell)
            new->Rchild = new->Rchild;
        else
        {
            if (new->Rchild != NULL)
                yt->Lchild = new->Rchild;
            else
                yt->Lchild = NULL;
            new->Rchild = dell->Rchild;
        }
        new->Lchild = dell->Lchild;

        if (hi->data > new->data)
            hi->Lchild = new;
        else
            hi->Rchild = new;
    }

    else // For Deleting Node with One Child
    {
        temp = parentof(dell->data);
        if (s > temp->data)
        {
            if (dell->Rchild != NULL)
                temp->Rchild = dell->Rchild;
            else
                temp->Rchild = dell->Lchild;
        }
        else
        {
            if (dell->Rchild != NULL)
                temp->Lchild = dell->Rchild;
            else
                temp->Lchild = dell->Lchild;
        }
    }

    free(dell);
}

// Main Function
void main()
{
    int choice, trav, s;
    while (1)
    {
        printf("\n0. Exit\n1. Create\n2. Traversals\n3. Insert\n4. Search\n5. Delete\nChoose : \t");
        scanf("%d", &choice);
        if (choice == 0)
            break;
        switch (choice)
        {
        case 1:
            Create();
            break;
        case 2:
            printf("Which Traversal : In(1)\t Post(2)\t Pre(3)\n");
            scanf("%d", &trav);
            switch (trav)
            {
            case 1:
                in_order(root);
                break;
            case 2:
                post_order(root);
                break;
            case 3:
                pre_order(root);
                break;
            default:
                break;
            }
            break;
        case 3:
            Insert();
            break;
        case 4:
            printf("Enter the Element : ");
            scanf("%d", &s);
            temp = search(s);
            if (temp == NULL)
                printf("Ayooo! Not Found");
            else
                printf("%d is Found in your Tree!", temp->data);
            break;
        case 5:
            Delete();
            break;
        default:
            printf("Instructions Unclear!");
            break;
        }
    }
}