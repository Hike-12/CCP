#include <bits/stdc++.h>
using namespace std;

class TopKFrequent
{
    int k;
    unordered_map<int, int> freq;
    struct Comp
    {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
        {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        }
    };
    set<pair<int, int>, Comp> st;

public:
    TopKFrequent(int K)
    {
        k = K;
    }

    void add(int num)
    {
        int f = freq[num];
        if (f > 0)
            st.erase({f, num});
        freq[num]++;
        st.insert({freq[num], num});
    }

    vector<int> getTopK()
    {
        vector<int> res;
        auto it = st.rbegin();
        while (it != st.rend() && res.size() < k)
        {
            res.push_back(it->second);
            ++it;
        }
        return res;
    }
};

int main()
{
    TopKFrequent obj(3);
    obj.add(1);
    obj.add(1);
    obj.add(2);
    obj.add(2);
    obj.add(2);
    obj.add(3);
    vector<int> ans = obj.getTopK();
    for (int x : ans)
        cout << x << " ";
}