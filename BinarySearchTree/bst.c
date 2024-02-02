#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* createNode(int data) 
{
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

struct node* insert(struct node *root, int key) 
{
  struct node *prev = NULL;
  struct node *current = root;

  while (current != NULL) 
  {
    prev = current;
    if (key == current->data) 
    {
      printf("Cannot insert %d, already in BST\n", key);
      return root; // Return existing root
    } else if (key < current->data) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  struct node* new1 = createNode(key);
  if (prev == NULL) {
    // This means the tree is empty
    return new1;
  } 
  else if (key < prev->data)
   {
    prev->left = new1;
  }
   else 
   {
    prev->right = new1;
  }

  return root; // Return existing root
}


struct node *inOrderPredecessor(struct node* root)
 {
  if (root == NULL || root->left == NULL) 
  {
    return NULL;
  }
  root = root->left;
  while (root->right != NULL) 
  {
    root = root->right;
  }
  return root;
}

struct node *deleteNode(struct node *root, int value)
 {
  struct node* iPre;

  if (root == NULL)
   {
    return NULL;
  }

  if (value < root->data) 
  {
    root->left = deleteNode(root->left, value);
  } else if (value > root->data) {
    root->right = deleteNode(root->right, value);
  } else {
    // Node with only one child or no child
    if ((root->left == NULL) || (root->right == NULL))
    {
      struct node *temp = root->left ? root->left : root->right;
      free(root);
      return temp;
    }

    // Node with two children
    iPre = inOrderPredecessor(root);
    root->data = iPre->data;
    root->left = deleteNode(root->left, iPre->data);
  }

  return root; // Return updated root
}

struct node *search(struct node* root, int key)
 {
  if (root == NULL || root->data == key) 
  {
    return root;
  }

  if (key < root->data)
   {
    return search(root->left, key);
  } else {
    return search(root->right, key);
  }
}

void inorderTraversal(struct node* root) 
{
  if (root != NULL) {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

void preorderTraversal(struct node* root) 
{
  if (root != NULL) {
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

void postorderTraversal(struct node* root)
 {
  if (root != NULL) 
  {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
  }
}

int main() {
  struct node *root = NULL;
  int choice, data, key;

  while (1) 
  {
    printf("\nMenu:\n");
    printf("1. Construct BST\n");
    printf("2. Insert element\n");
    printf("3. Delete element\n");
    printf("4. Search element\n");
    printf("5. Inorder traversal\n");
    printf("6. Preorder traversal\n");
    printf("7. Postorder traversal\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
     
    switch (choice) 
    {
          case 1:
        printf("BST is constructed.\n");
        break;
      case 2:
        printf("Enter the element to insert: ");
        scanf("%d", &key);
        root = insert(root, key);
        printf("%d inserted into the BST.\n", key);
        break;
      case 3:
        printf("Enter the element to delete: ");
        scanf("%d", &key);
        root = deleteNode(root, key);
        printf("%d deleted from the BST.\n", key);
        break;
      case 4:
        printf("Enter the element to search: ");
        scanf("%d", &key);
        if (search(root, key) != NULL) {
          printf("%d is found in the BST.\n", key);
        } else {
          printf("%d is not found in the BST.\n", key);
        }
        break;
      case 5:
        inorderTraversal(root);
        printf("\n");
        break;
      case 6:
        preorderTraversal(root);
        printf("\n");
        break;
      case 7:
        postorderTraversal(root);
        printf("\n");
        break;
      case 8:
        printf("Exiting the program.\n");
        exit(0); // Exit successfully
      default:
        printf("Invalid choice. Please enter a valid option.\n");
    }
  }

  return 0; // Indicate successful execution
}
