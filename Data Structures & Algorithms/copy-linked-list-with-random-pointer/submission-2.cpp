/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> clone;
public:
    Node* copyRandomList(Node* head) {
        // step 1
        unordered_map<Node*, Node*> oldToNew;
        oldToNew[nullptr] = nullptr;

        Node* curr = head;
        while (curr != nullptr){
            Node* copy = new Node(curr->val);
            oldToNew[curr] = copy;
            curr = curr->next;
        }

        curr = head;
        while (curr != nullptr){
            auto copy = oldToNew[curr];
            copy->next = oldToNew[curr->next];
            copy->random = oldToNew[curr->random];
            curr = curr->next;
        }
        return oldToNew[head];
    }
};
