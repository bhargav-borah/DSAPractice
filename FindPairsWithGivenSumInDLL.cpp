class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> arr;
        
        Node* leftNode = head;
        Node* rightNode = head;
        
        while (rightNode->next != nullptr) {
            rightNode = rightNode->next;
        }
        
        while (leftNode != nullptr && rightNode != nullptr && leftNode->prev != rightNode && leftNode != rightNode) {
            int sum = leftNode->data + rightNode->data;
            if (sum == target) {
                arr.push_back({leftNode->data, rightNode->data});
                leftNode = leftNode->next;
                rightNode = rightNode->prev;
            }
            else if (sum > target) {
                rightNode = rightNode->prev;
            }
            else if (sum < target) {
                leftNode = leftNode->next;
            }
        }
        
        return arr;
    }
};