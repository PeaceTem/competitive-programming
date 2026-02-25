# 🔤 6-Month Strings Roadmap (24 Weeks)

---

## 🟢 **Month 1: String Fundamentals (Weeks 1–4)**

### **Week 1: Basics & Manipulation** `DONE`

**Concepts**

- Indexing, substrings
    
- ASCII vs Unicode
    
- Character frequency
    

**Problems**

- Reverse String (LC 344)
    
- Valid Anagram (LC 242)
    
- First Unique Character (LC 387)
    

🎯 _Goal:_ Comfort with string operations

---

### **Week 2: Two Pointers & Sliding Window** `DONE`

**Concepts**

- Fixed vs variable window
    
- Frequency maps
    

**Problems**

- Longest Substring Without Repeating Characters (LC 3)
    
- Permutation in String (LC 567)
    
- Minimum Window Substring (LC 76)
    

🎯 _Goal:_ Window control mastery

---

### **Week 3: String Parsing & Simulation** `DONE`

**Concepts**

- Tokenization
    
- Edge cases
    

**Problems**

- Valid Palindrome (LC 125)
    
- String to Integer (atoi) (LC 8)
    
- Implement strStr() (LC 28)
    

🎯 _Goal:_ Avoid off-by-one bugs

---

### **Week 4: Prefix Techniques** `DONE`

**Concepts**

- Prefix sums on strings
    
- Hashing intuition
    

**Problems**

- Find the Index of the First Occurrence (LC 28)
    
- Repeated Substring Pattern (LC 459)
    

🎯 _Goal:_ Early pattern recognition

---

## 🟡 **Month 2: Hashing & Substrings (Weeks 5–8)**

### **Week 5: Rolling Hash (Rabin–Karp)** `DONE`

**Concepts**

- Polynomial hashing
    
- Collision handling
    

**Problems**

- Longest Duplicate Substring (LC 1044)
    
- Find substring matches
    

🎯 _Goal:_ Fast substring comparison

---

### **Week 6: Palindrome Techniques** `DONE`

**Concepts**

- Expand around center
    
- DP for palindromes
    

**Problems**

- Longest Palindromic Substring (LC 5)
    
- Palindromic Substrings (LC 647)
    

🎯 _Goal:_ Palindrome recognition

---

### **Week 7: String DP (Basics)**

**Concepts**

- Subsequence vs substring
    

**Problems**

- Longest Common Subsequence (LC 1143)
    
- Delete Operation for Two Strings (LC 583)
    

🎯 _Goal:_ Subsequence DP intuition

---

### **Week 8: Edit Distance Family**

**Concepts**

- Insert / delete / replace
    

**Problems**

- Edit Distance (LC 72)
    
- Minimum ASCII Delete Sum (LC 712)
    

🎯 _Goal:_ Transition design mastery

---

## 🟠 **Month 3: Pattern Matching Algorithms (Weeks 9–12)**

### **Week 9: KMP Algorithm**

**Concepts**

- LPS array
    
- Failure function
    

**Problems**

- Implement KMP
    
- Repeated Substring Pattern (revisit)
    

🎯 _Goal:_ Linear-time matching

---

### **Week 10: Z-Algorithm**

**Concepts**

- Z-array
    
- Pattern matching tricks
    

**Problems**

- String Matching
    
- Find occurrences using Z
    

🎯 _Goal:_ Pattern detection mastery

---

### **Week 11: Suffix Arrays (Intro)**

**Concepts**

- Sorted suffixes
    
- Rank arrays
    

**Problems**

- Longest Repeated Substring
    
- Distinct substrings count
    

🎯 _Goal:_ Lexicographic thinking

---

### **Week 12: Suffix Automaton (Intro)**

**Concepts**

- State graph
    
- End positions
    

🎯 _Goal:_ Powerful substring structure

---

## 🔴 **Month 4: Advanced String Structures (Weeks 13–16)**

### **Week 13: Trie**

**Concepts**

- Prefix trees
    
- Dictionary problems
    

**Problems**

- Implement Trie (LC 208)
    
- Word Search II (LC 212)
    

---

### **Week 14: Aho–Corasick**

**Concepts**

- Multiple pattern matching
    

🎯 _Goal:_ Multi-pattern search

---

### **Week 15: Manacher’s Algorithm**

**Concepts**

- Linear palindrome finding
    

**Problems**

- Longest Palindromic Substring (optimized)
    

🎯 _Goal:_ O(n) palindromes

---

### **Week 16: String + Bitmask / Graph**

**Concepts**

- State modeling
    

**Problems**

- Shortest Common Supersequence (LC 1092)
    
- Shortest Path Visiting All Nodes (LC 847, string modeling)
    

---

## 🔥 **Month 5: Advanced String DP & Counting (Weeks 17–20)**

### **Week 17: Counting Subsequences**

**Concepts**

- DP counting
    

**Problems**

- Distinct Subsequences (LC 115)
    

---

### **Week 18: Regex & Wildcards**

**Concepts**

- Automaton DP
    

**Problems**

- Regular Expression Matching (LC 10)
    
- Wildcard Matching (LC 44)
    

---

### **Week 19: String Compression & Encoding**

**Problems**

- String Compression II (LC 1531)
    

🎯 _Goal:_ Hard DP on strings

---

### **Week 20: String Optimization Problems**

**Problems**

- Remove Duplicate Letters (LC 316)
    
- Smallest Subsequence of Distinct Characters (LC 1081)
    

---

## 🏆 **Month 6: Mastery & Contests (Weeks 21–24)**

### **Week 21–22: Mixed Hard Problems**

- LC Hard string problems
    
- CF Div2 D/E string problems
    

---

### **Week 23: Templates & Speed**

**Templates**

- KMP
    
- Z-algorithm
    
- Rolling hash
    
- Trie
    

---

### **Week 24: Final Revision**

- Re-solve toughest problems
    
- Optimize implementations
    

🎯 **Final Goal**  
You should:

- Instantly classify string problems
    
- Choose correct algorithm quickly
    
- Avoid TLE via proper string techniques
    

---

## 🧠 Golden Rule for Strings

> If substrings are compared repeatedly, **you need hashing or suffix structures**.