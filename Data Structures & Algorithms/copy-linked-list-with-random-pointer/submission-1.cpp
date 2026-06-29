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
        if (head == nullptr){
            return nullptr;
        }

        if (clone.find(head) != clone.end()){
            return clone[head];
        }

        Node* copy = new Node(head->val);

        // avoid re-create new copy in case acyclist list 
        // while random node will point 
        // again the head, 
        clone[head] = copy;
        copy->next = copyRandomList(head->next);
        copy->random = copyRandomList(head->random);

        return copy;
    }
};
