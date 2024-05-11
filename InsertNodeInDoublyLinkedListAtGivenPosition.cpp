void addNode(Node *head, int pos, int data)
{
   Node* newNode = new Node(data);
   Node* temp = head;
   
   while (pos--) {
       temp = temp->next;
   }
   
   if (temp->next != nullptr) {
       newNode->next = temp->next;
       newNode->prev = temp;
       temp->next->prev = newNode;
       temp->next = newNode;
   }
   else {
       newNode->next = nullptr;
       newNode->prev = temp;
       temp->next = newNode;
   }
}