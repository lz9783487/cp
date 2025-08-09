using Info = int;
struct Node {
    Info info = 0;
    array<int, 2> sons = {-1, -1};
};
Info compose(Info i, const Info& other) {
    return ...
}
vector<Node> tree(1);
void add(vector<int> char_seq, Info info) {
    int cur = 0;
    tree[cur].info = compose(tree[cur].info, info);
    for (auto i : char_seq) {
        auto& soni = tree[cur].sons[i];
        if (soni == -1) {
            tree.push_back(Node());
            soni = (int) tree.size() - 1;
        }
        cur = soni;
        tree[cur].info = compose(tree[cur].info, info);
    }
}
Info query(vector<int> char_seq) {
    int cur = 0;
    for (auto i : char_seq) {
        cur = tree[cur].sons[i];
        if (cur == -1) {
            ...
        }
    }
    return tree[cur].info;
}