// Sort Array of 0s, 1s, and 2s: Bubble Sort vs Merge Sort vs Three-Pointer
#include <iostream>
#include <vector>

using namespace std;

struct Stats {
    long long comparisons = 0;
    long long moves = 0;
};

void bubbleSort012(vector<int>& a, Stats& st) {
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

void mergeInto(vector<int>& a, int l, int m, int r, vector<int>& tmp, Stats& st) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        st.comparisons++;
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
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

void mergeSortRec(vector<int>& a, int l, int r, vector<int>& tmp, Stats& st) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortRec(a, l, m, tmp, st);
    mergeSortRec(a, m + 1, r, tmp, st);
    mergeInto(a, l, m, r, tmp, st);
}

void mergeSort012(vector<int>& a, Stats& st) {
    if (a.empty()) return;
    vector<int> tmp(a.size());
    mergeSortRec(a, 0, (int)a.size() - 1, tmp, st);
}

void threePointerSort012(vector<int>& a, Stats& st) {
    int low = 0;
    int mid = 0;
    int high = (int)a.size() - 1;

    while (mid <= high) {
        st.comparisons++;
        if (a[mid] == 0) {
            int t = a[low];
            a[low] = a[mid];
            a[mid] = t;
            st.moves += 3;
            low++;
            mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else {
            int t = a[mid];
            a[mid] = a[high];
            a[high] = t;
            st.moves += 3;
            high--;
        }
    }
}

void printArray(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << "\n";
}

void runAll(const vector<int>& base, const string& name) {
    cout << "\nTest: " << name << "\nInput: ";
    printArray(base);

    vector<int> b = base;
    vector<int> m = base;
    vector<int> t = base;

    Stats sb, sm, st;

    bubbleSort012(b, sb);
    mergeSort012(m, sm);
    threePointerSort012(t, st);

    cout << "Bubble: ";
    printArray(b);
    cout << "comparisons=" << sb.comparisons << ", moves=" << sb.moves << "\n";

    cout << "Merge:  ";
    printArray(m);
    cout << "comparisons=" << sm.comparisons << ", moves=" << sm.moves << "\n";

    cout << "3-PTR:  ";
    printArray(t);
    cout << "comparisons=" << st.comparisons << ", moves=" << st.moves << "\n";

    cout << "Expected time: Bubble O(n^2), Merge O(n log n), 3-PTR O(n)\n";
}

int main() {
    vector<int> best = {0, 0, 0, 1, 1, 1, 2, 2, 2};
    vector<int> worst = {2, 2, 2, 1, 1, 1, 0, 0, 0};

    runAll(best, "Best case (already sorted)");
    runAll(worst, "Worst case (reverse sorted)");

    return 0;
}
