### Problem: Coin Change - Greedy

---

### Short Revision Notes (Exam Quick Recall)

- Pattern: Greedy (always pick largest coin that fits)
- Core Idea: Sort coins descending, greedily subtract largest coin possible
- Key Trick: Only correct for canonical coin systems (e.g. {1,5,10,25}); fails for arbitrary systems
- Complexity: O(A/min_coin) time where A = amount

---

### Code Snippet (Important Part Only)

```cpp
sort(coins.rbegin(), coins.rend());  // largest first
for (int coin : coins)
    while (amount >= coin) {
        amount -= coin;
        count++;
    }
```

---

### Detailed Explanation

- Sort coins in descending order.
- For each coin (largest first), use it as many times as possible.
- Move to the next smaller coin when current coin exceeds remaining amount.

**When greedy works:** Canonical systems where large coins divide evenly into smaller ones (e.g., standard currency denominations).

**When greedy fails:** Non-canonical systems like {1,3,4} for amount 6: greedy gives 4+1+1=3 coins, but optimal is 3+3=2 coins.

**Edge cases:**
- Amount = 0: 0 coins
- No combination possible: return -1

**Common mistakes:**
- Applying greedy to arbitrary coin sets (use DP instead)
- Not sorting coins first

---

### Dry Run

Coins: {1,5,10,25}, Amount: 41  
Sort: {25,10,5,1}  
25 fits (41≥25): use 25, remaining=16, count=1  
10 fits (16≥10): use 10, remaining=6, count=2  
5 fits (6≥5): use 5, remaining=1, count=3  
1 fits (1≥1): use 1, remaining=0, count=4  

Result: **4 coins** (25+10+5+1)

---

### Visualization (USE MERMAID ONLY, NO ASCII)

```mermaid
graph LR
    A["Amount: 41"] --> B["Use 25 → 16"]
    B --> C["Use 10 → 6"]
    C --> D["Use 5 → 1"]
    D --> E["Use 1 → 0 ✓ (4 coins)"]
```
