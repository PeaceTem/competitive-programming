## 🧩 OVERVIEW: Project Goal

**NumberForces** is a **competitive sliding puzzle platform** (like a “chess.com for logic puzzles”) that blends:

- **Casual solo play** (for engagement & learning),
    
- **Competitive combat mode** (for retention),
    
- **Progression mechanics** (Elo, streaks, leaderboards),
    
- **Monetization** via **Stripe** (USD/NGN) and ads (AdMob/AdSense).
    

---

## ⚙️ PHASE STRUCTURE

| Phase                                | Focus                                                        | Goal                                             |
| ------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------ |
| **Phase 1 – Core MVP**               | Core puzzle logic, user system, solo play, monetization      | Build a complete, usable app (soft-launch ready) |
| **Phase 2 – Competitive Systems**    | Combat mode, Elo, leaderboards                               | Introduce multiplayer and ranking features       |
| **Phase 3 – Engagement & Expansion** | Streaks, achievements, daily puzzles, advanced UI, analytics | Deepen retention and community                   |

---

## 🚀 PHASE 1 – CORE MVP (FOUNDATIONAL RELEASE)

### 🎯 Goal

Deliver a **playable and monetizable** puzzle app with basic user management, solo puzzle play, and payment integration — enough to collect feedback and measure user interest.

---

### 🧱 1. Core Puzzle System `DONE`

**Why:** This is the heart of the app. Needs to feel smooth, responsive, and rewarding.

**Tasks:**

-  Implement **3×3 sliding (real sliding like luke's own) puzzle** with animations & timer. `DONE`
    
-  Add **move counter**, **reset**, **shuffle**, and **completion detection**. `DONE`
    
-  Store puzzle states (for resume/retry); user return back to puzzle state during in-match reload. `DONE`
    
-  Build **Puzzle Engine module** that can later support 4×4, 5×5. (use list instead of string for puzzle state) `DONE`
    
-  Optimize for performance on both web and mobile. `DONE`
- Add a centralize Play Page for Combat, Challenges, and Tournaments. `DONE`
    

🧠 _Keep game logic modular so combat mode can reuse it later._

-----

### 👤 2. Authentication (Google OAuth) `DONE`

**Why:** Low-friction onboarding and future-proofing for multi-device sync.

**Tasks:**

-  Implement Google Sign-In using Firebase/Auth.js/Phoenix integration. `DONE`
    
-  Store user profile in DB (user_id, name, email, **avatar**). `DONE`
    
-  Implement basic JWT or session authentication. `DONE`
    
-  Add logout and account management UI. (Change Username) `DONE`
    

---

### 💳 3. Premium Subscription System

**Why:** Early monetization testing + support advanced puzzles later.

**Tasks:**

-  Integrate **Stripe Checkout** (USD + NGN).
    
-  Add **subscription tiers** (e.g., Free, Premium).
    
-  Handle webhooks for subscription status.
    
-  Gate puzzle sizes >3×3 behind Premium.
    
-  Show subscription status on Dashboard.
    
-  Add cancel/renew handling.
    

💡 _Stripe’s pricing page can later be localized for Nigeria (NGN). Use test mode for early testing._

---

### 🧭 4. Core Screens & Navigation `ONGOING`

**Why:** User experience foundation — must be minimal but intuitive.

**Screens (Phase 1):**

1. **Login Screen** (Google OAuth)
    
2. **Dashboard**
    
    - “Play Puzzle”
        
    - “Upgrade to Premium”
        
    - “Leaderboard (coming soon)”
        
    - “Daily Puzzle (coming soon)”
        
3. **Puzzle Play Screen**
    
    - 3×3 grid, move/timer display
        
    - Win animation
        
    - “Play Again” / “Home” buttons
        
4. **Subscription Page**
    
    - Stripe checkout integration
        
5. **Profile/Settings Page**
    
    - Logout
        
    - View subscription status
        

---

### 📊 5. Database & Backend `ONGOING`

**Why:** Maintain persistence, prepare for multiplayer in future phases.

**Tasks:**

-  Design tables/schemas:
    
    - `users`, `puzzles`, `sessions`, `subscriptions`
        
-  Set up backend (Phoenix or Node/Express) for:
    
    - Auth handling
        
    - Puzzle history (optional)
        
    - Payment webhook
        
-  Secure all API endpoints
    
-  Deploy to a test environment (Render/Fly.io/Vercel backend)
    

---

### 💰 6. Ads Integration

**Why:** Adds passive monetization for free users.

**Tasks:**

-  Add **AdMob** (mobile) or **AdSense** (web) SDK.
    
-  Configure **banner ads** on Dashboard and **interstitial** on puzzle completion.
    
-  Add toggle to disable ads for premium users.
    

---

### 🧩 7. UX/UI & Branding (Dark Theme with Gold Color) `ONGOING`

**Why:** A polished design increases retention.

**Tasks:**

-  Simple logo & theme (neon or minimal brain-game vibe).
    
-  Consistent font & color palette.
    
-  Responsive design for mobile + tablet.
    
-  Add haptics/sound effects.
    

---

### 🧾 8. Testing & QA

**Tasks:**

-  Unit test puzzle logic.
    
-  Integration test for login and Stripe flow.
    
-  Device compatibility testing (mobile, desktop).
    
-  Load test backend.
    

---

### 🧩 9. Deployment

**Tasks:**

-  Deploy backend to Render/Fly.io.
    
-  Deploy frontend to Vercel.
    
-  Connect production Stripe keys.
    
-  Configure analytics (Firebase or Plausible).
    
-  Beta test with small user group.
    

---

### 🔹 Optional (If Time Allows)

-  Add “Daily Puzzle” (seeded puzzle per day).
    
-  Store basic stats: best time, average moves.
    
-  Add subtle confetti or animation when puzzle solved.
    

---

## 🧨 PHASE 2 – COMPETITIVE SYSTEMS `ONGOING`

### Focus:

Turn NumberForces into a _competitive platform_ like chess.com.

**Core Additions:**

-  **Combat Mode:** Real-time PvP match; same puzzle, fastest wins. `DONE`
    
-  **Elo Rating:** Update after combat matches. `DONE`
    
-  **Leaderboards:** combat Elo. `DONE`
    
-  **Matchmaking:** Pair similar-rated players. `DONE`
    
-  **Spectator / Replay mode.** `LATER`
	
-  Add subtle confetti or animation when puzzle solved.
    
-  Store puzzle states (for resume/retry); user return back to puzzle state during in-match reload. `DONE`
-  **Log Moves**: The server should validate each move. `DONE`
-  **Uninitiated Matches**: find match on reopening of screen uninitiated.
-  **Clean GameRegistry**: Clean the game registry after each game. `DONE`

💡 _Reuse puzzle logic from Phase 1 — only sync moves and timer over channels._

---

## 🏆 PHASE 3 – ENGAGEMENT & EXPANSION

**Enhancements:**

-  **Daily Winning Streak tracking** & badges.
    
-  **Puzzle history & analysis** (like game review).
    
-  **Push notifications** for streaks and challenges.
    
-  **Tournaments or timed events.**
    
-  **Social sharing & friend system.**
-  **Referral System**
    
-  **Offline mode.**
    

---

## 🧭 Why These Phase Choices?

| Reason                  | Decision                                                                     |
| ----------------------- | ---------------------------------------------------------------------------- |
| **Speed to MVP**        | Phase 1 focuses on single-player and monetization; easiest to test and ship. |
| **Iterative expansion** | Later phases build _on top_ of stable core — no rework.                      |
| **Technical reuse**     | Puzzle engine, user system, and Stripe base stay constant across all phases. |
| **Market validation**   | Early version helps test user interest before complex multiplayer setup.     |
ffmpeg -f dshow -i audio="Stereo Mix (Conexant ISST Audio)" -f gdigrab -framerate 30 -i desktop -c:v libx264 -preset slow -pix_fmt yuv420p -c:a aac -b:a 192k underwood.mp4


**Referral System**
**Cheating Detection System - Anomaly Detection (Unsupervised Learning)** 
**Phoenix Presence**
**Both Authenticated and Unauthenticated users (guest mode) can play games**
**Check Leetcode's Quest Page Design**


## Tournaments
- Contests like Codeforces - each participants have a new elo rating specifically for the tournament. It lasts for a day.
- Blitz Cup Tournaments
- Swiss Style Tournaments
- Last Man Standing Swiss Style

Weekly Brawl Tournament
- It should last for one week from Sunday to Friday.
- 