## What is an Invariant?

An **invariant** is a quantity or condition that **does not change** no matter how many valid operations you apply.

Examples:

- Parity (even/odd)
    
- Sum mod k
    
- XOR of elements
    
- Number of inversions modulo 2
    
- Relative ordering
    

---

## 1. Parity Invariants (Even / Odd)

### Key idea

Operations don’t change parity → final state must match initial parity.

### Classic Problems

1. **2331 – Evaluate Boolean Binary Tree**
    
2. **1523 – Count Odd Numbers in an Interval Range** `DONE`
    
3. **1250 – Check If It Is a Good Array**
    
    - Invariant: `gcd` of array
        
    - If gcd becomes 1 → possible
        
4. **2571 – Minimum Operations to Reduce an Integer to 0** `DONE`
    
    - Binary parity invariant
        

---

## 2. XOR Invariants

### Key idea

XOR remains unchanged when:

- swapping elements
    
- pairing equal numbers
    
- rearranging array
    

### Problems

1. **136 – Single Number**
    
    - Invariant: XOR of entire array
        
2. **268 – Missing Number**
    
3. **260 – Single Number III**
    
4. **287 – Find the Duplicate Number**
    
    - XOR + bit tricks
        

---

## 3. Sum Modulo Invariants

### Key idea

Sum modulo `k` does not change → final configuration must satisfy it.

### Problems

1. **1010 – Pairs of Songs With Total Durations Divisible by 60**
    
2. **974 – Subarray Sums Divisible by K**
    
3. **523 – Continuous Subarray Sum**
    
4. **2598 – Smallest Missing Non-negative Integer After Operations**
    

---

## 4. Permutation & Swap Invariants

### Key idea

Swaps do **not change relative counts or parity of permutations**

### Problems

1. **1530 – Number of Good Leaf Nodes Pairs**
    
2. **775 – Global and Local Inversions**
    
    - Invariant: difference between global & local inversions
        
3. **1202 – Smallest String With Swaps**
    
    - Invariant: connected components
        

---

## 5. Graph / Connectivity Invariants

### Key idea

Connectivity doesn’t change unless explicitly modified.

### Problems

1. **1319 – Number of Operations to Make Network Connected**
    
2. **547 – Number of Provinces**
    
3. **1971 – Find if Path Exists in Graph**
    

---

## 6. Game Theory / Winning State Invariants

### Key idea

Winning positions depend on **parity or Grundy numbers**

### Problems

1. **292 – Nim Game**
    
    - Invariant: XOR of pile sizes
        
2. **1025 – Divisor Game**
    
3. **486 – Predict the Winner**
    

---

## 7. Greedy + Invariant Thinking

### Key idea

Greedy works because some metric never decreases.

### Problems

1. **55 – Jump Game**
    
    - Invariant: max reachable index
        
2. **134 – Gas Station**
    
    - Invariant: total gas ≥ total cost
        
3. **135 – Candy**
    
    - Invariant: relative ordering of ratings