# What CM actually requires (reality check)

- Rating ≈ **1900–1999**
    
- You must:
    
    - Solve **A–C instantly**
        
    - Solve **D consistently**
        
    - Sometimes solve **E**
        
- Knowledge is **not the bottleneck**  
    👉 **Speed, accuracy, pattern recognition, and contest discipline are**
    

---

# Time Budget Strategy (≥ 2 hrs/day)

**Do NOT grind random problems.**  
Use a **contest-first approach**.

### Daily structure (ideal)

- **30–45 min** → Practice problems (targeted)
    
- **30–45 min** → Editorial reading + implementation redo
    
- **15–30 min** → Notes / pattern extraction
    

On **contest days**:

- **Full contest (2 hrs)**
    
- **+ 1 hr upsolve (mandatory)**
    

---

# Phase-wise Roadmap (12 months)

---

## PHASE 1 (Months 1–3): Speed & Accuracy Foundation

### Goal

- Turn known topics into **reflexes**
    
- Eliminate silly mistakes
    

### What to do

#### 1️⃣ Spam Div2 C/D (but correctly)

- Platforms:
    
    - **Codeforces Div2**
        
    - Old contests only
        
- Rules:
    
    - **Time limit:** 60–75 min max per problem
        
    - If stuck → read editorial → **recode without looking**
        

Focus areas:

- Implementation-heavy problems
    
- Math + greedy + bit tricks
    
- Prefix/suffix logic
    

#### 2️⃣ Mandatory post-contest routine

For _every_ contest:

- Re-solve **all problems you failed**
    
- Ask:
    
    - Why didn’t I see this?
        
    - What was the missing observation?
        
- Write **1–2 lines summary** per problem
    

📌 This step alone separates 1400 → 1700.

---

## PHASE 2 (Months 4–6): Depth & Pattern Mastery

### Goal

- Become **consistent D solver**
    
- Start cracking E occasionally
    

### What to focus on (in depth)

You already know topics — now **master patterns**:

### 🔹 DP (VERY important)

- DP on arrays (subarray compression)
    
- DP with bitmask
    
- Tree DP
    
- DP + greedy hybrids
    

👉 Do **30–40 DP problems**, not 5.

### 🔹 Graphs

- BFS/DFS variations
    
- Topological sorting
    
- Shortest paths (multi-source, 0-1 BFS)
    
- DSU tricks
    

### 🔹 Trees

- LCA + binary lifting
    
- Rerooting DP
    
- Tree diameter & subtree queries
    

### 🔹 Math

- GCD properties
    
- Modular arithmetic
    
- Sieve + divisor tricks
    
- Bitwise AND/OR/XOR patterns
    

---

## PHASE 3 (Months 7–9): Contest Hardening

### Goal

- Push rating from ~1700 → ~1850
    

### Strategy shift

#### 1️⃣ Fewer problems, higher quality

- Solve **Div2 D/E**
    
- **Div1 A/B** (gold mine for patterns)
    

#### 2️⃣ Simulate real contests

- No pauses
    
- No editorials
    
- Strict timing
    

#### 3️⃣ Upsolve aggressively

- If you don’t upsolve E → rating stagnates
    

---

## PHASE 4 (Months 10–12): CM Push

### Goal

- Break 1900+
    

### What changes now

#### 🔥 Precision > Volume

- No more mass grinding
    
- Only:
    
    - Live contests
        
    - Upsolving
        
    - Revisiting mistakes
        

#### 🔥 Contest mindset

- Read all problems first
    
- Identify:
    
    - “free”
        
    - “medium”
        
    - “maybe later”
        
- Don’t tunnel vision
    

#### 🔥 Fix common CM-killers

- Overthinking easy problems
    
- Panic during contest
    
- Slow implementation
    
- Missing edge cases
    

---

# Weekly Schedule (Example)

| Day | Activity                            |
| --- | ----------------------------------- |
| Mon | 2–3 practice problems (D-level)     |
| Tue | Editorial study + re-implementation |
| Wed | Mixed practice                      |
| Thu | DP/Graph focus                      |
| Fri | Light practice + notes              |
| Sat | **Live contest + upsolve**          |
| Sun | 2–3 hard problems + review          |

---

# Tools You MUST Use

- **CF Problemset filters**  
    Rating 1400–1900
    
- **Virtual contests**
    
- **Notion / notebook**
    
    - Patterns
        
    - Common tricks
        
    - Bugs you repeat
        

---

# Signs you’re on track

By:

- **Month 3** → 1500–1600
    
- **Month 6** → 1650–1750
    
- **Month 9** → 1800+
    
- **Month 12** → CM range
    

---

# Brutally honest advice

- If you:
    
    - Skip upsolving ❌
        
    - Solve only easy problems ❌
        
    - Learn new topics endlessly ❌
        

You won’t reach CM.

But if you:

- Treat contests seriously
    
- Review mistakes religiously
    
- Focus on **thinking patterns**, not syntax
    

👉 **CM in 1 year is absolutely achievable**.


# DP RoadMap
## 🟢 1. 1D Linear DP (Beginner)

**State depends on previous 1–2 states**

### Pattern

`dp[i] = f(dp[i-1], dp[i-2], ...)`

### Examples

- Fibonacci
    
- Climbing Stairs (LC 70)
    
- Min Cost Climbing Stairs (LC 746)
    
- House Robber (LC 198)
    

---

## 🟢 2. 1D DP with Choice (Knapsack-lite)

**Each index has a decision**

### Pattern

`dp[i] = min / max over choices`

### Examples

- Coin Change (LC 322)
    
- Perfect Squares (LC 279)
    
- Jump Game II (LC 45)
    

---

## 🟡 3. Prefix / Suffix DP

**Uses cumulative info**

### Examples

- Best Time to Buy and Sell Stock (LC 121)
    
- Trapping Rain Water (DP view)
    
- Product of Array Except Self (DP view)
    

---

## 🟡 4. 2D Grid DP

**Move in grid**

### Pattern

`dp[i][j] from top / left / diagonal`

### Examples

- Unique Paths (LC 62)
    
- Minimum Path Sum (LC 64)
    
- Dungeon Game (LC 174)
    

---

## 🟡 5. Interval DP

**DP over ranges**

### Pattern

`dp[l][r]`

### Examples

- Matrix Chain Multiplication
    
- Burst Balloons (LC 312)
    
- Palindrome DP (LC 516)
    

---

## 🟡 6. Subsequence DP

**Pick or skip**

### Pattern

`dp[i][j] → prefixes`

### Examples

- Longest Common Subsequence (LC 1143)
    
- Edit Distance (LC 72)
    
- Delete Operation for Two Strings (LC 583)
    

---

## 🟠 7. Knapsack DP (Classic)

**Capacity-based states**

### Pattern

`dp[i][w]`

### Examples

- 0/1 Knapsack
    
- Partition Equal Subset Sum (LC 416)
    
- Target Sum (LC 494)
    

---

## 🟠 8. State Compression DP (Bitmask DP)

**Subset-based DP**

### Pattern

`dp[mask]`

### Examples

- Traveling Salesman Problem
    
- Minimum Number of Work Sessions (LC 1986)
    
- Assignment Problem
    

---

## 🟠 9. DP on Trees

**DFS + DP merge**

### Pattern

`dp[u][state]`

### Examples

- Tree Diameter
    
- House Robber III (LC 337)
    
- Tree Matching
    

---

## 🔴 10. DP on DAG / Graphs

**Topological DP**

### Examples

- Longest Path in DAG
    
- Course Schedule III
    
- DP with BFS / DAG relaxation
    

---

## 🔴 11. Digit DP

**DP on digits with constraints**

### Pattern

`dp[pos][tight][state]`

### Examples

- Count numbers with constraints
    
- Numbers ≤ N without consecutive ones
    
- Count digit occurrences
    

---

## 🔴 12. Probability DP

**Expected values**

### Examples

- Dice probability
    
- Random walk
    
- Expected number of steps
    

---

## 🔴 13. Game Theory DP

**Optimal play**

### Pattern

`win / lose DP`

### Examples

- Stone Game series
    
- Nim variations
    
- Predict the Winner (LC 486)
    

---

## 🔴 14. DP with Monotonic Queue / Optimization

**Optimize transitions**

### Techniques

- Convex Hull Trick
    
- Monotonic Queue
    
- Divide & Conquer DP
    

### Examples

- DP optimization problems (CF)
    
- Slopes trick
    

---

## 🔴 15. DP on Automata / Strings + State

**FSM + DP**

### Examples

- Regex Matching (LC 10)
    
- Wildcard Matching (LC 44)
    
- String matching with constraints
    

---

## 🔥 16. Advanced Hybrid DP (Expert)

**Multiple DP paradigms combined**

### Examples

- Tree + Bitmask DP
    
- Digit + DP + math