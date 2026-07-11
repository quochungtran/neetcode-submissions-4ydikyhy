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
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToNew;
        oldToNew[nullptr] = nullptr;
        auto curr = head;
        while (curr){
            auto newNode = new Node(curr->val);
            oldToNew[curr] = newNode;
            curr = curr->next;
        }

        curr = head;
        while(curr){
            oldToNew[curr]->next = oldToNew[curr->next];
            oldToNew[curr]->random = oldToNew[curr->random];
            curr = curr->next;
        }

        return oldToNew[head];
    }
};
