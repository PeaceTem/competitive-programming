## 3. 1-Week Roadmap (REALISTIC)

Assuming ~3–5 hours/day.

---

### **Day 1 – Project Setup & Structure**

**Goal:** App boots, layout exists

- Create Phoenix app
    
- Setup Tailwind theme (simple, clean)
    
- Global layout:
    
    - Header (About | Blog | Projects | Resume | Games)
        
    - Footer (GitHub, LinkedIn)
        
- Static pages:
    
    - About me
        
    - Resume page (embed PDF)
        

✅ End of day: Website looks like _you_, even if empty

---

### **Day 2 – Blog Engine (Core)**

**Goal:** Blog listing + single post works

- Add NimblePublisher
    
- Parse markdown front-matter
    
- Blog index page
    
- Blog show page
    
- Syntax highlighting for code blocks
    

Optional:

- Tags
    
- Estimated read time
    

✅ End of day: You can write posts in Markdown and see them live

---

### **Day 3 – Images + Projects Section**

**Goal:** Blog images + projects look good

- Image handling (static assets)
    
- Cover images per blog
    
- Projects page:
    
    - Name
        
    - Description
        
    - Tech stack
        
    - GitHub link
        
    - Live demo (if any)
        

Store projects in:

- `projects.ex` module **or**
    
- `projects.md`
    

✅ End of day: Recruiter can scan your work in 30 seconds

---

### **Day 4 – Presence & Polish**

**Goal:** Subtle real-time features

- Add Phoenix Presence
    
- Show:
    
    - “Active now”
        
    - Number of visitors (optional)
        
- Add LiveView transitions
    
- Mobile responsiveness
    

❗ Keep this subtle. Presence is a _bonus_, not the product.

---

### **Day 5 – Tic-Tac-Toe (Human vs AI)**

**Goal:** Playable game

- Board state in LiveView
    
- Player vs Computer
    
- Implement Minimax
    
- Highlight winning line
    
- Reset button
    

Bonus:

- Difficulty levels (depth limit)
    

✅ End of day: Fun, impressive demo

---

### **Day 6 – Number Puzzle Game**

Ideas:

- Sliding puzzle (8-puzzle)
    
- Guess-the-number with hints
    
- Sudoku-lite
    

Focus on:

- Clean state transitions
    
- Clear logic
    
- Not fancy UI
    

---

### **Day 7 – Final Polish + Deployment**

**Goal:** Public, fast, impressive

- SEO metadata
    
- OpenGraph images
    
- 404 page
    
- Deploy (Fly.io is 🔥 for Elixir)
    
- Write 1 strong blog post:
    
    > “Building My Portfolio with Phoenix LiveView”