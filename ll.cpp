class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        Node *curr = head;
        
        Node *next = NULL;
        while(curr != NULL)
        {
            next = curr->next;
            Node *temp = new Node(curr->val);
            temp->next = next;
            curr->next = temp;
            curr = next;
        }
        curr = head;
        while(curr != NULL)
        {
            if(curr->random != NULL)
            {    
            curr->next->random = curr->random->next;
           
            }   
            else 
                curr->next->random = NULL;
            curr = curr->next->next;
        }
        
        curr = head;
        Node *head_cp = curr->next;
        while( curr->next != NULL )
        {
            
            next = curr->next->next;
            if(curr->next->next != NULL)
            {    
            curr->next->next = curr->next->next->next;
            curr->next = next;
            }
            else 
            {
                curr->next->next = NULL;
                curr->next =  NULL;
                break;
            }
            curr = curr->next;
        }
        
        
        
        return head_cp;
       
        
    }
};