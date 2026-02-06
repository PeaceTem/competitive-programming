Use chess.com & Monkeytype design - svgs, etc.
2*Contabo + Railway/Render(postgres) => $17/mo
OR use 3Contabo instances instead => $15/mo
Each Contabo instances => 3 vCPU Cores, 8 GB RAM, 75 GB NVMe OR 150 GB SSD
Object Storage Contabo => 250GB $3.39

Have a second DB that only accepts writes in a queue maybe, i.e. can be done later.
**Always write the test for each feature**.
### Always read elixir/phoenix and ionic/react docs daily
Use Modal popup for Win etc.
You can also use TypeRacer combat format,[Where more than 2 people can fight it out]

You can challenge [Casual/Rated] other users
The typeracer is also rated
Casual games with unregistered users

ChatGPT even has emoji generators
## Domain Name ideas
numberforces.com

# 🚀 Refined Two-Week Puzzle App Plan
Day 1 -> Wednesday, Aug 20, 2025

**Tech Stack:**

- **Frontend (Web + Mobile):** Ionic + React + Capacitor
    
- **Backend:** Elixir + Phoenix (API, auth, matchmaking, combat, Elo rating)
    
- **Database:** PostgreSQL
    
- **Auth:** Google OAuth (authentication) + Role-based Authorization
    
- **Payments:** Stripe ($3/mo or $10/year)
    
- **Rating:** Elo system for player-vs-player
    

---

## 🔹 Core Features

1. Puzzle gameplay (3x3 free, premium unlocks more sizes).
    
2. User accounts via Google OAuth.
    
3. Stripe subscription for premium.
    
4. Combat mode (2 players solve same puzzle, fastest wins).
    
5. Elo rating for ranked combat.
    
6. Leaderboards (solo & combat).
7. Daily Streak Tracking
    
Just LIke the world puzzle championship.
combat will be like codeforces' contest [ICPC] where anyone compete against eachother.

---

## 🔹 Week 1: Backend & Core Gameplay

### Day 1–2: Phoenix Backend Setup

- Scaffold Phoenix API: `mix phx.new puzzle_backend --no-html --no-assets`.
    
- Add PostgreSQL schemas:
    
    - **users**: id, email, google_uid, role (free/premium), elo_rating (default 1200).
        
    - **puzzles**: id, size, scrambled_state, solved_state.
        
    - **matches**: id, puzzle_id, player1_id, player2_id, winner_id, created_at.
        
    - **subscriptions**: user_id, stripe_customer_id, status.
        
- Auth:
    
    - Use `ueberauth_google` or `goth` for Google OAuth.
        
    - Store JWT/session after login.
        
- Authorization:
    
    - Use a plug to check role (premium/free) before accessing premium routes.
        

---

### Day 3–4: Puzzle Gameplay API

- Endpoints: supervisor n dynamic supervisor
    
    - `GET /puzzle/:size` → returns a scrambled puzzle.
        
    - `POST /solve` → check solution (solver validates).
        
    - `GET /leaderboard?size=3` → returns top attempts.
        
- Connect to Ionic frontend (login, fetch puzzle, solve, leaderboard).
    

---

### Day 5: Combat System (Backend)

- Implement **matchmaking**:
    
    - Queue system (Redis or ETS) for waiting players.
        
    - When 2 players match → assign puzzle, create `matches` record.
        
- Combat flow:
    
    1. Both players receive the same puzzle state.
        
    2. They solve locally → submit moves to `/combat/submit`.
        
    3. First correct submission → backend marks winner.
    4. Add timer [1, 3, 5]
    5. Number of moves too.
        
- Update Elo rating:
    
    - Use standard Elo formula:
        
        `R_new = R_old + K * (S - E)`
        
        - K = 32 (or configurable).
            
        - S = 1 if win, 0 if loss.
            
        - E = expected score.
            

---

### Day 6: Stripe Subscription Integration

- Add `stripity_stripe` for Elixir.
    
- Endpoints:
    
    - `POST /subscribe` → starts Stripe checkout.
        
    - `POST /webhook` → updates subscription status in DB.
        
- Frontend:
    
    - Show “Subscribe” page with $3/mo or $10/year.
        
    - Lock premium features (bigger puzzles, ranked combat) behind premium role.
        

---

### Day 7: Frontend Puzzle UI (Ionic + React)

- Build Puzzle component (3x3 grid with drag/swipe moves).
    
- Timer + move counter.
    
- Screens: Login (Google), Dashboard, Puzzle Play, Leaderboard, Subscription.
    

---

## 🔹 Week 2: Combat + Polish + Deployment

### Day 8–9: Combat Frontend

- Add **Combat Mode screen**:
    
    - Queue button (“Find Opponent”).
        
    - Show both players’ timers & move counts in real-time (Phoenix Channels / WebSockets).
        
    - End screen: winner, Elo change, rematch option.
        

### Day 10: Leaderboards

- Solo Leaderboard: fastest times per puzzle size.
    
- Combat Leaderboard: Elo rating (ranked players).
    
- Differentiate **free leaderboard** (3x3 only) vs **premium leaderboard** (all sizes).
    

### Day 11: Authorization Polishing

- Role-based checks:
    
    - Free users → only 3x3 solo puzzles & casual combat (no Elo).
        
    - Premium users → all puzzle sizes & Elo combat.
        

### Day 12: Testing

- Unit tests: solver integration, Elo updates, auth flow.
    
- API tests: puzzle endpoints, combat flow.
    
- Mobile tests: puzzle play & combat on iOS/Android.
    

### Day 13: Deployment

- Backend → Fly.io or Gigalixir.
    
- Database → Supabase or RDS (Postgres).
    
- Frontend:
    
    - Web → Vercel/Netlify.
        
    - Mobile → build with Capacitor → Play Store & App Store.
        

### Day 14: Final Polish

- Dark mode / simple UI themes.
    
- Notifications (match found, subscription expiring).
    
- Marketing landing page with Stripe Checkout.
- ### Add AdMob & AdSense
    

---

# ✅ Final Deliverables

- **Web + iOS + Android app** (Ionic React). [Use Chess.com Black and Green]
    
- **Google OAuth authentication** + **role-based authorization**.
    
- **Puzzle gameplay** (3x3 free, larger premium).
    
- **Combat mode with Elo rating (add casual like Lichess)**.
    
- **Stripe subscription** for premium.
    
- **Leaderboards** (solo & combat).
    

---

⚡ Recommendation for combat:

- Use **Phoenix Channels (WebSockets)** → real-time updates (timers, moves, match result).
    
- Keep casual combat free → Elo combat premium (incentive to pay).
- Use multiple Payment Gateways - Moniepoint, Interswitch, Flutterwave, Paystack.


#### Daily Streak
#### Monthly Combat - 300 games to qualify. 


## 🎨 Design Concept: _Puzzle Arena_

### 🌟 Theme

- Minimal but **gamey look**: dark background + neon accent (blue/green/orange).
    
- Rounded puzzle tiles with soft shadows.
    
- Animated transitions (tiles sliding smoothly).
    

---

## 📱 Screens

### 1. **Home Screen**
 Add the community section to the home screen.
- **Header:** _Sliding Puzzle Arena_
    
- **Buttons (cards with icons):**
    
    - 🧩 **Play Puzzle** (fetch puzzle)
        
    - ⚡ **Solve with AI**
        
    - 🏆 **Leaderboard**
        
- **Animated background:** subtle grid pattern or puzzle pieces floating.
    

---

### 2. **Puzzle Screen**

- **Top Bar:**
    
    - Back arrow ←
        
    - Timer ⏱
        
    - Moves counter 🔢
        
- **Puzzle Board:**
    
    - Grid (3×3 or 4×4) with draggable/slideable tiles.
        
    - Empty space represented by a transparent tile.
        
    - Smooth animations when tiles move.
        
- **Bottom Buttons:**
    
    - 🔄 Restart Puzzle
        
    - ⚡ Solve (calls backend → returns optimal path, animates tiles automatically).
        

---

### 3. **Leaderboard Screen**

- **Header:** Leaderboard
    
- **List of Players:**
    
    - 🥇 Rank + Avatar + Username + Best Time + Moves
        
- Highlight **your score** with a glowing card.
    
- **Optional:** Toggle switch (⏳ Fastest Time / 🎯 Fewest Moves).
    

---

## 🔗 Backend Connection Flow

1. **Fetch Puzzle (Play Puzzle)**
    
    - Ionic frontend calls Phoenix backend:
        
        `GET /api/puzzle/new`
        
    - Returns a puzzle state (e.g., `[1,2,3,4,5,6,7,8,0]`).
        
2. **Solve Puzzle (AI Engine)**
    
    - User taps **Solve** →
        
        `POST /api/puzzle/solve { "state": [1,2,3,4,5,6,7,8,0] }`
        
    - Backend returns solution moves → frontend animates them.
        
3. **Leaderboard**
    
    - Ionic fetches leaderboard:
        
        `GET /api/leaderboard`
        
    - Displays top 10 (time & moves).
        
    - After puzzle is solved, Ionic sends:
        
        `POST /api/leaderboard { "username": "Olumide", "time": 25, "moves": 40 }`
        

---

## 🛠️ Ionic Components to Use

- **IonPage / IonContent / IonHeader** → screens.
    
- **IonGrid / IonRow / IonCol** → puzzle board layout.
    
- **IonButton (rounded, outline, neon)** → actions.
    
- **IonList / IonItem / IonAvatar / IonLabel** → leaderboard.
    
- **IonLoading** → while fetching puzzle/solution.

---

## 🌍 4. Micro-Grants & Startup Programs

There are organizations that give **$500–$5,000 micro-grants** (no equity). Some good ones:

- **Stripe Atlas / Indie Hackers community** → sometimes sponsor small indie devs.
    
- **Pioneer.app** → gives $1,000 grants for cool projects.
    
- **OnDeck Catalyst** → supports young founders with stipends.
    
- **African-focused startup hubs**: Tony Elumelu Foundation, Founders Institute, Co-Creation Hub (Lagos).
    

---

## 🚀 5. Pre-Sell / Validate

If your app is consumer-facing (like your puzzle app):

- Create a **landing page** with screenshots and a waitlist.
    
- Offer **early access for $2–$5**.
    
- Even 20–30 people paying you upfront = your $100 monthly covered.
## 3. Build in Public (Content → Funding)

- Share your **progress on LinkedIn/Twitter** (screenshots, updates, mistakes, lessons).
    
- Add a **Buy Me a Coffee / Patreon link** → some people will support.
    
- Example: “I’m building an Elixir-powered puzzle game from Nigeria. Supporting this project is $5/month — join the journey!”
  
  
  
  ### Create Your Own Premium Ads for now - Copy chess.com
- HTML to SVG

If you want, I can add:

- Tile **tap highlights** for tiles that are currently slideable.
    
- A **“smart shuffle”** button on mount (auto-shuffles once when you open the page).
    
- Optional **move animations** (translate) for an even more “arcade neon” feel.