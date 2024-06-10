class Solution
{
    public:
    
    void recurse(struct Node* &head, struct Node* &curr, struct Node* &prev){
        if(curr == NULL){
            head = prev;
            return;
        }
        recurse(head, curr -> next, curr);
        curr -> next = prev;
        
    }
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *&head)
    {
        
        Node* curr = head;
        Node* prev = NULL;
        recurse(head, curr, prev);
        return head;
    }
    
    
};