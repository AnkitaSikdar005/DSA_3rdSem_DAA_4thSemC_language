#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Count the total no of leaf nodes in a binary tree (degree 0)

int countLeaf(struct node *root)
{
    int x, y;
    if (root != NULL)
    {
        x = countLeaf(root->left);
        y = countLeaf(root->right);
        if (root->left == NULL && root->right == NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}
// Sum of all nodes in a binary tree

int sum(struct node *root)
{
    int x, y;
    if (root != NULL)
    {
        x = sum(root->left);
        y = sum(root->right);
        return x + y + root->data;
    }
    return 0;
}


// Count the total no of nodes in a binary tree with degree 2

int countDeg2(struct node *root)
{
    int x, y;
    if (root != NULL)
    {
        x = countDeg2(root->left);
        y = countDeg2(root->right);
        if (root->left != NULL && root->right != NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

// Count the total no of nodes in a binary tree with degree 1 or 2

int countDeg1_2(struct node *root)
{
    int x, y;
    if (root != NULL)
    {
        x = countDeg1_2(root->left);
        y = countDeg1_2(root->right);
        if (root->left != NULL || root->right != NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

// Count the total no of nodes in a binary tree with degree 1 method 1

int countDeg1_method1(struct node *root)
{
    int x, y;
    if (root != NULL)
    {
        x = countDeg1_method1(root->left);
        y = countDeg1_method1(root->right);
        if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}


// Count the total no of nodes in a binary tree

int count(struct node *root)
{
    int x, y;
    if (root != NULL)
    {
        x = count(root->left);
        y = count(root->right);
        return x + y + 1;
    }
    return 0;
}
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void insertChild(struct node *root) {
    int leftData, rightData;

    printf("Enter value for left child of %d (-1 for no child): ", root->data);
    scanf("%d", &leftData);
    if (leftData != -1) {
        root->left = createNode(leftData);
        insertChild(root->left);  // Recursively insert children of the left child
    }

    printf("Enter value for the right child of %d (-1 for no child): ", root->data);
    scanf("%d", &rightData);
    if (rightData != -1) {
        root->right = createNode(rightData);
        insertChild(root->right);  // Recursively insert children of the right child
    }
}

int main() {
    struct node *root = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a new tree\n2. Insert children of a node\n3. Preorder traversal\n4. Inorder traversal\n5. Postorder traversal\n6. Count no of nodes \n 7. Sum of all nodes \n 8. Count no of leaf nodes\n 9. Count no of nodes with degree 2\n 10. Count no of nodes with degree 1 or 2 \n 11. Count no of nodes with degree 1 (method 1) \n 12. Exit\n");
       printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Node inserted successfully.\n");
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    insertChild(root);
                }
                break;
            case 3:
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                postorderTraversal(root);
                printf("\n");
                break;
           case 6:
            printf("Total no of nodes in the tree is: %d", count(root));
            break;
           case 7:
            printf("Sum of all nodes in the tree is: %d", sum(root));
            break;
            case 8:
            printf("Total no of leaf nodes in the tree is: %d", countLeaf(root));
            break;
           case 9:
            printf("Total no of nodes in the tree with degree 2 is: %d", countDeg2(root));
            break;
           case 10:
            printf("Total no of nodes in the tree with degree 1 or 2 is: %d", countDeg1_2(root));
            break;
            case 11:
            printf("Total no of nodes in the tree with degree 1 (method 1) is: %d", countDeg1_method1(root));
            break;
           case 12:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                
        }
    } 

    return 0;
}
