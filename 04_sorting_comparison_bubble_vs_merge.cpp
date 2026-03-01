// Sorting Algorithm Comparison: Bubble Sort vs Merge Sort
#include <iostream>
#include <vector>

using namespace std;

struct SortStats {
    long long comparisons = 0;
    long long moves = 0;
};

void bubbleSort(vector<int>& a, SortStats& st) {
    int n = (int)a.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            st.comparisons++;
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                st.moves += 3;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void mergeInto(vector<int>& a, int l, int m, int r, vector<int>& tmp, SortStats& st) {
    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= r) {
        st.comparisons++;
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
        st.moves++;
    }
    while (i <= m) {
        tmp[k++] = a[i++];
        st.moves++;
    }
    while (j <= r) {
        tmp[k++] = a[j++];
        st.moves++;
    }
    for (int x = l; x <= r; x++) {
        a[x] = tmp[x];
        st.moves++;
    }
}

void mergeSortRec(vector<int>& a, int l, int r, vector<int>& tmp, SortStats& st) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortRec(a, l, m, tmp, st);
    mergeSortRec(a, m + 1, r, tmp, st);
    mergeInto(a, l, m, r, tmp, st);
}

void mergeSort(vector<int>& a, SortStats& st) {
    if (a.empty()) return;
    vector<int> tmp(a.size());
    mergeSortRec(a, 0, (int)a.size() - 1, tmp, st);
}

unsigned int nextRand(unsigned int& state) {
    state = state * 1103515245u + 12345u;
    return state;
}

vector<int> makeRandomArray(int n, unsigned int seed) {
    vector<int> a;
    a.reserve(n);
    unsigned int state = seed;
    for (int i = 0; i < n; i++) {
        a.push_back((int)(nextRand(state) % 10000u));
    }
    return a;
}

void runSize(int n) {
    vector<int> base = makeRandomArray(n, 123u);
    vector<int> a1 = base;
    vector<int> a2 = base;

    SortStats b, m;
    bubbleSort(a1, b);
    mergeSort(a2, m);

    cout << "n=" << n << "\n";
    cout << "Bubble: comparisons=" << b.comparisons << ", moves=" << b.moves << ", time=O(n^2)\n";
    cout << "Merge:  comparisons=" << m.comparisons << ", moves=" << m.moves << ", time=O(n log n)\n\n";
}

int main() {
    cout << "Bubble Sort vs Merge Sort (operation counts on random arrays)\n\n";

    runSize(10);
    runSize(50);
    runSize(100);
    runSize(200);

    return 0;
}
