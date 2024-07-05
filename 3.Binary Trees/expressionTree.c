// // #include <stdio.h>
// // #include <stdlib.h>

// // struct node {
// //     char data;
// //     struct node* left;
// //     struct node* right;
// //     struct node* next;
// // };

// // struct node *head = NULL;

// // struct node* newNode(char data) {
// //     struct node* node = (struct node*)malloc(sizeof(struct node));
// //     node->data = data;
// //     node->left = NULL;
// //     node->right = NULL;
// //     node->next = NULL;
// //     return node;
// // }

// // void printInorder(struct node* node) {
// //     if (node == NULL)
// //         return;
    
// //     printInorder(node->left);
// //     printf("%c ", node->data);
// //     printInorder(node->right);
// // }

// // void push(struct node* x) {
// //     if (head == NULL)
// //         head = x;
// //     else {
// //         (x)->next = head;
// //         head = x;
// //     }
// // }

// // struct node* pop() {
// //     struct node* p = head;
// //     head = head->next;
// //     return p;
// // }

// // int main() {
// //     char s[100];
// //     printf("Enter the infix expression: ");
// //     scanf("%s", s);

// //     int i = 0;
// //     struct node *x, *y, *z;

// //     while (s[i] != '\0') {
// //         if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
// //             z = newNode(s[i]);
// //             x = pop();
// //             y = pop();
// //             z->left = y;
// //             z->right = x;
// //             push(z);
// //         } else {
// //             z = newNode(s[i]);
// //             push(z);

// // 		}
// // 	}
// // 	printf(" The Inorder Traversal of Expression Tree: ");
// // 	printInorder(z);
// // 	return 0;
// // }


// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

// // Define a structure for the expression tree node
// struct TreeNode {
//     char data;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };

// // Function to check if a character is an operator
// int isOperator(char c) {
//     return (c == '+' || c == '-' || c == '*' || c == '/');
// }

// // Function to create a new node for the expression tree
// struct TreeNode* createNode(char data) {
//     struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//     newNode->data = data;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// // Function to convert infix expression to expression tree
// struct TreeNode* infixToExpressionTree(char* expression, int start, int end) {
//     if (start > end) {
//         return NULL;
//     }

//     // Find the index of the operator with the lowest precedence
//     int lowestPrecedence = 9999; // a large number
//     int indexOfOperator = -1;

//     int i;
//     for (i = start; i <= end; i++) {
//         if (isOperator(expression[i])) {
//             int precedence;
//             if (expression[i] == '+' || expression[i] == '-') {
//                 precedence = 1;
//             } else {
//                 precedence = 2;
//             }

//             if (precedence <= lowestPrecedence) {
//                 lowestPrecedence = precedence;
//                 indexOfOperator = i;
//             }
//         }
//     }

//     // Create a new node for the operator
//     struct TreeNode* root = createNode(expression[indexOfOperator]);

//     // Recursively construct the left and right subtrees
//     root->left = infixToExpressionTree(expression, start, indexOfOperator - 1);
//     root->right = infixToExpressionTree(expression, indexOfOperator + 1, end);

//     return root;
// }

// // Function to print the expression tree in infix form
// void printInfix(struct TreeNode* root) {
//     if (root != NULL) {
//         if (isOperator(root->data)) {
//             printf("(");
//         }

//         printInfix(root->left);
//         printf("%c", root->data);
//         printInfix(root->right);

//         if (isOperator(root->data)) {
//             printf(")");
//         }
//     }
// }

// int main() {
//     char expression[] = "a+b*c";
//     int length = sizeof(expression) / sizeof(expression[0]) - 1;

//     // Convert infix expression to expression tree
//     struct TreeNode* root = infixToExpressionTree(expression, 0, length - 1);

//     // Print the expression tree in infix form
//     printInfix(root);

//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>

// Define a structure for the expression tree node
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node for the expression tree
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to evaluate the expression tree
int evaluateExpressionTree(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    // If the node is a leaf (operand), return its value
    if (root->left == NULL && root->right == NULL) {
        return root->data - '0'; // Convert character to integer
    }

    // Evaluate the left and right subtrees
    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    // Perform the operation based on the operator at the current node
    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            fprintf(stderr, "Invalid operator: %c\n", root->data);
            exit(EXIT_FAILURE);
    }
}

int main() {
    // Construct a sample expression tree: (3 + (4 * 5))
    struct TreeNode* root = createNode('+');
    root->left = createNode('3');
    root->right = createNode('*');
    root->right->left = createNode('4');
    root->right->right = createNode('5');

    // Evaluate the expression tree
    int result = evaluateExpressionTree(root);

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}
