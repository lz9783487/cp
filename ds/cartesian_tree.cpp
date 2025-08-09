template <typename F = less<int>>
class Cartesian_tree {
    int root = -1;
    vector<int> lson, rson, father;
    void build(vector<int> a) {
        int n = (int) a.size();
        lson = rson = father = vector<int>(n, -1);
        stack<int, vector<int>> st;
        for (int i = 0; i < n; ++i) {
            int last = -1;
            while (!st.empty() && !F()(a[st.top()], a[i])) {
                last = st.top();
                st.pop();
            }
            if (!st.empty()) {
                rson[st.top()] = i;
                father[i] = st.top();
            } else {
                root = i;
            }
            lson[i] = last;
            if (last != -1) {
                father[last] = i;
            }
            st.push(i);
        }
    }
};