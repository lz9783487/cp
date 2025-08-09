template <typename T>
struct custom_list {
    struct Node {
        T val;
        Node *prev, *next;
        Node() : val(), prev(nullptr), next(nullptr) {}
        Node(const T &val) : val(val), prev(nullptr), next(nullptr) {}
    };
    Node *head, *tail;
    size_t sz;
    custom_list() : head(new Node()), tail(new Node()), sz(0) {
        head->next = tail;
        tail->prev = head;
    }
    ~custom_list() {
        while (head != nullptr) {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    Node *push_back(const T &val) {
        Node *node = new Node(val);
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
        ++sz;
        return node;
    }
    Node *push_front(const T &val) {
        Node *node = new Node(val);
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        ++sz;
        return node;
    }
    Node *begin() const {
        return head->next;
    }
    Node *end() const {
        return tail;
    }
    void pop_back() {
        if (sz == 0) {
            return;
        }
        Node *node = tail->prev;
        tail->prev = node->prev;
        node->prev->next = tail;
        delete node;
        --sz;
    }
    void pop_front() {
        if (sz == 0) {
            return;
        }
        Node *node = head->next;
        head->next = node->next;
        node->next->prev = head;
        delete node;
        --sz;
    }
    T &front() {
        return head->next->val;
    }
    T &back() {
        return tail->prev->val;
    }
    size_t size() {
        return sz;
    }
};