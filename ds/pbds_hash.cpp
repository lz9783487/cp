#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
__gnu_pbds::gp_hash_table<string, int>::iterator it; //是的你没看错，这个hash表有迭代器！但是我并不知道这有什么用
__gnu_pbds::gp_hash_table<string, int> h; // string -> int
string hh;
int n, a, m;
int main()
{
    h["lskjdf"] = 123; //可以像 map 一样直接访问元素
    it = h.begin();//是的你没看错，这个hash表有迭代器！但是我并不知道这有什么用
    for (int ww = 1; ww <= m; ww++)
    {
        cin >> hh;
        //若哈希表中不存在查找的元素，.find() 会返回 .end()
        if (h.find(hh) != h.end()) //如果找的到这个元素
        {
            cout << h.find(hh)->first << " " << h.find(hh)->second << endl;
            //first对应的是Key , second 对应的是 Value
            //hash_.erase(hh);  删掉 hh 这里不做演示
        }
        else
        {
            cout << "No found!\n";
        }
    }
    return 0;
}
