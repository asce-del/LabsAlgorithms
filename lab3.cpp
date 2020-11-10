#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node *insert(struct Node *node, int value) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = node;

    return new_node;
}

struct Node *reverse(struct Node *node) {
    struct Node *current = node;
    struct Node *prev = NULL, *next = NULL;
    while (current != NULL) {

        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    return prev;
}


void display(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    struct Node *head = NULL;
    int n, x;

    cout << "Enter list quantity ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        head = insert(head, x);
    }

    cout << "The linked list is: ";
    struct Node *newNode = NULL;

    display(head);
    cout << "\n";
    newNode = reverse(head);
    display(newNode);

    return 0;
}