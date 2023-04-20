template<class T>
class CircularLinkedList 
{
    private:
        struct Node 
        {
            T data;
            Node* next;
            Node(T value) : data(value), next(nullptr) {}
        };
        Node* last;
        size_t length;
    public:
        CircularLinkedList() : last(nullptr), length(0) {}
        ~CircularLinkedList() { clear(); }

        void push_back(T value) 
        {
            Node* new_node = new Node(value);
            if (!last) 
            {
                last = new_node;
                last->next = last;
            }
            else
            {
                new_node->next = last->next;
                last->next = new_node;
                last = new_node;
            }
            length++;
        }

        void push_front(T value) 
        {
            Node* new_node = new Node(value);
            if (!last) {
                last = new_node;
                last->next = last;
            }
            else 
            {
                new_node->next = last->next;
                last->next = new_node;
            }
            length++;
        }

        void insert(size_t idx, T value) 
        {
            if (idx == 0) 
            {
                push_front(value);
                return;
            }
            if (idx >= length) 
            {
                push_back(value);
                return;
            }
            Node* cur = last->next;
            Node* new_node = new Node(value);
            for (size_t i = 0; i < idx - 1; i++) cur = cur->next;
            new_node->next = cur->next;
            cur->next = new_node;
            length++;
        }

        void pop_back() 
        {
            if (!last) return;
            if (last->next == last)
            {
                delete last;
                last = nullptr;
                length = 0;
                return;
            }
            Node* cur = last->next;
            while (cur->next != last) cur = cur->next;
            cur->next = last->next;
            delete last;
            last = cur;
            length--;
        }

        void pop_front()
        {
            if (!last) return;
            if (last->next == last)
            {
                delete last;
                last = nullptr;
                length = 0;
                return;
            }
            Node* cur = last->next;
            last->next = cur->next;
            delete cur;
            length--;
        }

        void remove_at(size_t index)
        {
            if (index == 0) {pop_front(); return;}
            if (index == length - 1) {pop_back(); return;}
            Node* cur = last->next;
            for (size_t i = 0; i < index - 1; i++) cur = cur->next;
            Node* temp = cur->next;
            cur->next = temp->next;
            delete temp;
            length--;
        }

        size_t size() const
        {
            return length;
        }

        bool empty() const
        {
            return length == 0;
        }

        T& operator[](const size_t index) 
        {
            Node* cur = last->next;
            for (size_t i = 0; i < index; i++)
            {
                cur = cur->next;
            }
            return cur->data;
        }

        T const& operator[](const size_t index) const 
        {
            Node* cur = last->next;
            for (size_t i = 0; i < index; ++i)
            {
                cur = cur->next;
            }
            return cur->data;
        }
    
        void clear()
        {
            while (last) pop_front();
        }
};