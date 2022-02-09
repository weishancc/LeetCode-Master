class MyLinkedList {
    public:
        struct ListNode {
            int val;
            ListNode* next;
            ListNode(int val):val(val), next(nullptr){}
        };

        MyLinkedList() {
            _dummyHead = new ListNode(0);
            _size = 0;
        }

        int get(int index) {
            if (index > (_size - 1) || index < 0) {
                return -1;
            }
            ListNode* cur = _dummyHead->next;
            while(index--){ 
                cur = cur->next;
            }
            return cur->val;
        }

        void addAtHead(int val) {
            ListNode* newNode = new ListNode(val);
            newNode->next = _dummyHead->next; // NewNode points to current head node(_dummyHead)
            _dummyHead->next = newNode; // Update current head node to newNode
            _size++;
        }

        void addAtTail(int val) {
            ListNode* newNode = new ListNode(val);
            ListNode* cur = _dummyHead;
            while(cur->next != nullptr){
                cur = cur->next;
            }
            cur->next = newNode;
            _size++;
        }


        void addAtIndex(int index, int val) {
            if (index > _size) {
                return;
            }
            ListNode* newNode = new ListNode(val);
            ListNode* cur = _dummyHead;
            while(index--) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            _size++;
        }

        void deleteAtIndex(int index) {
            if (index >= _size || index < 0) {
                return;
            }
            ListNode* cur = _dummyHead;
            while(index--) {
                cur = cur ->next;
            }
    
            cur->next = cur->next->next;
            _size--;
        }

    private:
        int _size;
        ListNode* _dummyHead;

};