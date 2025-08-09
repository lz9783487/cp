#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
__gnu_pbds::tree< 
    std::string, // key值
    __gnu_pbds::null_type, /* 这是映射到的值，我们现在不需要，所以填null_type */
    std::less<std::string>, /* 比较规则，可以使用仿函数的形式 */
    __gnu_pbds::rb_tree_tag, /* 树的类型 红黑树一般为最优 */
    __gnu_pbds::tree_order_statistics_node_update /* 节点更新类型 */
    > k;

int main() {
    int cnt = 0;
    k.insert("man");
    k.insert("what");
    k.insert("can");
    k.insert("i");
    k.insert("say");
    // after inserts: {"can","i","man","say","what"}
    auto it = k.find("can");
    cout << *it << endl; 

    it = k.find_by_order(0); // find by rank
    cout << *it << endl; // can

    it = k.find_by_order(1);
    cout << *it << endl; // i
    it = k.find_by_order(2);
    cout << *it << endl; // man

    int f = k.order_of_key("man"); // find by key
    cout << f << endl;

    for (auto kk = k.begin(); kk != k.end(); kk++) {
        cout << (*kk) << " "; // can i man say what
    } 
    return 0;
}