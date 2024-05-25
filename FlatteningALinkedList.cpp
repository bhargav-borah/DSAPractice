Node* mergeTwoLists(Node* a, Node* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    
    Node* result;
    if (a->data < b->data) {
        result = a;
        result->bottom = mergeTwoLists(a->bottom, b);
    }    
    else {
        result = b;
        result->bottom = mergeTwoLists(b->bottom, a);
    }
    
    return result;
}

Node *flatten(Node *root) {
    
    if (root == nullptr || root->next == nullptr) {
        return root;
    }
    
    root->next = flatten(root->next);
    root = mergeTwoLists(root, root->next);
    
    return root;
}