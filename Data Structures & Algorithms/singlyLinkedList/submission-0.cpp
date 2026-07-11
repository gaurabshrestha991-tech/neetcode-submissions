class ListNode {
    public:
    int val;
    ListNode* next;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList
{
    public :
    ListNode* head;

    LinkedList () {
        head = nullptr;
    }

    int get(int index)
    {
        ListNode* curr = head;
        int i  =0;

        while (curr != nullptr)
        {
            if(i == index)
                return curr->val;
                
            curr = curr->next;
            i++;
        }
        return -1;
    }

    void insertHead(int val){
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    void insertTail(int val) {
        ListNode* newNode = new ListNode(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        ListNode* curr = head;

        while (curr -> next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    bool remove(int index) {
        if(head == nullptr)
        return false;

        if(index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        ListNode* curr = head;
        int i = 0;

        while (curr != nullptr && i < index - 1) {
            curr = curr->next;
            i++;
        }

        if (curr == nullptr || curr->next == nullptr)
            return false;

            ListNode* temp = curr->next;
            curr->next = temp->next;
            delete temp;

            return true;
    }

    vector<int> getValues() {
        vector<int> ans;
        ListNode* curr = head;

        while(curr != nullptr) {
            ans.push_back(curr->val);
            curr  = curr->next;
        }
        return ans;
    }
};