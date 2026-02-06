# 🎮 **Anomaly Detection for Cheater Detection in Online Games — Research Overview**

Cheating in online games often introduces **statistical anomalies** in player behavior, physics constraints, timing, input patterns, and network interactions.  
Modern anti-cheat systems combine **machine learning**, **behavioral modeling**, and **server-side logic** to detect such anomalies.

This research summary organizes the entire topic into:

1. Types of cheating
    
2. Categories of anomalies
    
3. Data sources
    
4. Detection techniques (classical + ML + deep learning)
    
5. Game-specific methods
    
6. System architecture
    
7. Evaluation metrics
    
8. Challenges
    
9. Recommended reading
    

---

# 1️⃣ **Types of Cheating in Online Games**

Each cheat type produces a **distinct statistical anomaly**.

### **A. Gameplay manipulation**

- Aimbot
    
- Wallhack
    
- No recoil / no spread
    
- Speed hack
    
- Teleport
    
- Infinite ammo / health
    
- Scripted macros (auto-clickers)
    

### **B. Economic manipulation**

- Gold farming bots
    
- Marketplace inflation
    
- Duplication glitches
    

### **C. Network manipulation**

- Lag switching
    
- Packet injection
    
- Packet prediction abuse
    

### **D. Social/system manipulation**

- Account sharing
    
- Win-trading
    
- Match-fixing
    
- Boosting
    

---

# 2️⃣ **Types of Anomalies**

### **A. Behavioral anomalies**

- Reaction time too fast for human capability
    
- Input frequency too consistent (bot-like)
    
- Movement patterns unnaturally smooth or perfectly optimized
    
- Impossible accuracy at long distances
    
- Recoil control too perfect
    

### **B. Temporal anomalies**

- Action timing intervals more uniform than human randomness
    
- Inhuman click intervals (e.g., exactly 10.0 ms every time)
    

### **C. Statistical anomalies**

- Win rate suddenly spikes (boosting)
    
- XP or item gain too rapid
    
- K/D ratio increases nonlinearly compared to history
    

### **D. Physics anomalies**

- Movement speeds outside accepted ranges
    
- Impossible trajectories
    
- Position updates skipping too many frames
    
- Vertical acceleration not matching gravity constant
    

### **E. Network anomalies**

- Packet timestamp manipulation
    
- Frequent 0-ping bursts (sign of lag switching)
    

---

# 3️⃣ **Data Sources for Detection**

### **Client-based**

- Input logs
    
- Mouse/keyboard entropy
    
- Aim deltas
    
- Frame-by-frame position
    

### **Server-based**

- Player state updates
    
- Movement deltas
    
- Fire events
    
- Hit registration
    
- Match outcomes
    
- Network packet metadata
    

### **Meta-data**

- Device fingerprint
    
- Account history
    
- Social graph (boosting detection)
    

---

# 4️⃣ **Anomaly Detection Techniques**

## **A. Rule-Based Detection (Deterministic)**

Used for physics and timing constraints.

Examples:

- Speed > allowed limit → flag
    
- Aim snap angle > threshold → flag
    
- Accuracy > 95% with auto-recoil → suspicious
    

**Pros:** Fast, explainable  
**Cons:** Easy to bypass

---

## **B. Traditional ML Methods**

Used for statistical and behavioral anomalies.

### 1. **Isolation Forest**

- Identifies rare events that differ from population
    
- Perfect for K/D, accuracy, economic gains
    

### 2. **One-Class SVM**

- Model normal player behavior
    
- Deviations → anomaly
    

### 3. **Random Forest / XGBoost**

- Feature-based classification
    
- Detects patterns of known cheaters
    

### 4. **HMM (Hidden Markov Models)**

- Detects unnatural state transitions (movement, firing sequences)
    

### 5. **K-means clustering**

- Groups similar players
    
- Outliers → potential cheaters
    

---

## **C. Deep Learning Approaches**

### 1. **LSTM / GRU (Temporal patterns)**

- Detect bot-like timing
    
- Model sequential behavior (input → action → result)
    

### 2. **CNNs**

- Aim-trajectory images converted to heatmaps
    
- CNN detects smooth/robotic aim
    

### 3. **Autoencoders**

- Train on normal data
    
- High reconstruction error → anomaly
    

### 4. **GANs**

- Generate normal human behavior
    
- Compare real vs. generated to detect deviations
    

---

# 5️⃣ **Game-Specific Cheat Detection Techniques**

### **FPS games (Valorant, CS2, Fortnite)**

- Aim trajectory curve analysis
    
- Crosshair jitter randomness
    
- Time-to-target distribution
    
- Bullet spread vs. recoil pattern consistency
    
- Hit probability vs. actual hits ratio
    
- Movement speed variance
    

### **MMORPGs**

- Macro detection from uniform intervals
    
- Economical anomaly detection (duplication, inflation)
    
- Bot pathing recognition via positional entropy
    
- Action entropy modeling
    

### **Racing games**

- Path optimality scoring
    
- Perfect-turn detection
    
- Unrealistic acceleration curves
    

### **Puzzle/Strategy games**

- Move prediction probability too high
    
- APM uniformity
    
- Solver-like move sequence detection
    

---

# 6️⃣ **System Architecture (Industry Pattern)**

### **Server-Side Pipeline**

`Game Server → Event Stream → Feature Engineering →  Real-Time Anomaly Detector → Cheater Scoring Engine → Human Review / Auto-Ban`

### **Cheater Score**

Calculated from:

- Behavioral anomaly score
    
- Physics violation score
    
- Network anomaly score
    
- Account metadata
    
- ML probability score
    

**Then:**  
Threshold → warning → shadowban → ban

---

# 7️⃣ **Evaluation Metrics**

- **Precision** (avoid false bans)
    
- **Recall** (catch cheaters)
    
- **F1-score** (balance)
    
- **ROC-AUC**
    
- **False positive rate** (critical for game fairness)
    
- **Detection latency** (how fast cheaters get caught)
    

---

# 8️⃣ **Challenges**

- Cheaters evolve faster than detectors
    
- Limited labeled data
    
- High variance in player skill
    
- Smurf accounts look like anomalies
    
- Privacy rules restrict client-based tracking
    
- Many anomalies come from legitimate behavior (e.g., pro players)
    

---

# 9️⃣ **Recommended Papers & Resources**

(Non-sensitive, public research)

- **Valve Anti-Cheat (VAC) research papers**
    
- "Cheaters in the Steam Community" — USENIX
    
- "Aimbot detection using mouse movement analysis"
    
- Tencent anti-cheat AI papers
    
- “Detecting Bots in Online Games Using ML Techniques”
    
- Riot Games anti-cheat presentations (Vanguard)
    
- Blizzard’s Warden whitepapers
    

---

# ⭐ If you want, I can also give you:

✅ **A full research paper draft (3–10 pages)**  
✅ **Implementation examples (Elixir, Python, C++)**  
✅ **How to detect cheating in your exact game type**  
— whether matchmaking puzzle, FPS, RPG, or strategy.

Just tell me **what kind of game and what kind of cheats** you want to detect.

##### You said:

give me this specific scenario: sliding number puzzle

###### ChatGPT said:

Thought for 5s

Nice — I’ll give you a complete, actionable design for **anomaly detection tailored to a sliding-number puzzle** (15-puzzle / N-puzzle) game. This covers what to log, features to compute, rule-based detectors, ML approaches, data generation and labelling, deployment architecture, evaluation, and mitigation actions. I’ll also include short code sketches you can drop into your pipeline (Python + Elixir ideas) and a prioritized roadmap for getting this live.

---

# Overview (what cheating looks like in sliding puzzles)

Cheats for sliding puzzles typically try to make players finish puzzles faster or in fewer moves than legitimately possible. Common cheat types:

- **Client-side state tampering**: sending forged board states or final-solved events without valid move sequences.
    
- **Move injection / replay**: injecting a precomputed optimal move sequence or replaying a known solution.
    
- **Solver bot**: an automated agent that computes and issues near-optimal moves at inhuman speed/consistency.
    
- **Move shortcut / tile swap**: submitting a solved board by swapping tiles instead of legal sliding moves.
    
- **Latency exploits**: manipulating timestamps to appear slower/faster or to replay network events.
    
- **Collusion / boosting**: players coordinating to pass levels artificially (less common here).
    

Detection focuses on **sequence validity**, **optimality vs. human capability**, and **statistical anomalies**.

---

# Data to collect (server-side preferred; minimal client trust)

Always prefer server-side verification of state transitions. Log everything you can:

1. **Per-game metadata**
    
    - game_id, user_id, session_id, puzzle_size (e.g., 4×4), initial_board (array), seed, solvable flag
        
    - start_time, end_time, elapsed_time
        
    - client version, device fingerprint, transport (websocket/web)
        
2. **Move stream (ordered)**
    
    - timestamp (server-received + client-declared if available)
        
    - move_index
        
    - moved_tile (tile id)
        
    - from_pos, to_pos (coordinates)
        
    - board_hash after move
        
    - move_latency (server receive - prev receive)
        
    - any client signature / move nonce
        
3. **End/result event**
    
    - reported moves_count, reported_time, final_board_hash, claimed_solved_by (client/server)
        
4. **Auxiliary telemetry (optional but very helpful)**
    
    - mouse/gesture paths, mouse timestamps, keypresses
        
    - client-side move generation intervals
        
    - network RTT, packet loss
        

Collect these into an append-only event log so you can re-run checks offline.

---

# Integrity checks (basic, server-enforced, rule-based)

Run these **first** on every game — they are cheap and deterministic.

1. **Legal-move validation**
    
    - For each reported move, verify the move is a legal slide from previous server-side board state.
        
    - If the client sends only final board, reject unless you can reconstruct moves.
        
2. **Board-solvability check**
    
    - Verify the initial board is solvable (inversion count and blank-row parity rules).
        
3. **Hash-chain validation**
    
    - Maintain a hash chain `H0 = hash(initial_board || seed)` then `Hi = hash(Hi-1 || move || timestamp)` — reject if final hash does not match.
        
4. **No tile swaps**
    
    - If two board states differ by more than one tile's legal movement (i.e., non-adjacent tile moved), flag.
        
5. **Minimum-move lower bound**
    
    - Compute minimal move count using admissible heuristic (Manhattan distance) or run an A*/IDA* solver to get true optimal moves for small sizes. If reported moves < optimal, flag.
        
6. **Time vs. optimal moves**
    
    - Compute `time_per_move = elapsed_time / moves`. Very small times (e.g., < 10–30 ms per move consistently) are suspicious.
        
7. **Replay detection**
    
    - Keep a DB of known optimal solutions per seed; if a user matches a known solution pattern at machine-like speed, flag.
        
8. **Duplicate session detection**
    
    - Same account solving many puzzles with near-identical move sequences => bot/automation.
        

Rule-based checks are your first line — they catch many blatant cheats.

---

# Feature engineering (for ML)

From logs extract features per-game and per-player-session:

**Per-game features**

- `moves_count`
    
- `elapsed_time_ms`
    
- `time_per_move_mean, std, median`
    
- `min_possible_moves` (heuristic lower bound)
    
- `ratio_moves_to_min = moves_count / min_possible_moves`
    
- `optimal_gap = moves_count - min_possible_moves`
    
- `reconstruction_success` (boolean: can server reconstruct moves sequentially)
    
- `illegal_move_count`
    
- `tile_swap_count` (non-adjacent changes)
    
- `move_entropy` (Shannon entropy of move directions: up/down/left/right)
    
- `direction_transition_matrix` stats (how often L→R etc.)
    
- `repeat_patterns_score` (n-gram frequency of repeated k-length move motifs)
    
- `move_time_autocorrelation` (are timings too regular?)
    
- `human_timing_features`: coefficient of variation (std/mean) of inter-move intervals
    
- `mouse_path_vs_move` alignment score (if mouse telemetry available)
    
- `session_history_features`: average moves/time for user historically
    
- `device_risk_score` (new device, multiple accounts per device)
    

**Per-move / sequential features** (for sequence models)

- move distance (1 for a legal slide)
    
- heuristic delta (change in Manhattan sum after move)
    
- is_optimal_step (boolean if move reduces heuristic as an optimal path)
    
- inter-move-interval
    

---

# ML models & approaches

Use a **layered approach**:

### 1) Isolation Forest / One-Class methods (unsupervised)

Good for catching outliers on engineered features (`ratio_moves_to_min`, time_per_move, entropy). Fast to train and explain.

### 2) Supervised classifier (if you have labelled cheats)

- Models: XGBoost / RandomForest / LightGBM
    
- Features: all per-game features above + historical user features
    
- Label source: manual review, synthetic cheats (below), banned accounts
    

### 3) Sequential models (for timing and move-sequence patterns)

- LSTM or GRU trained on sequences of `(move_delta, heuristic_delta, inter_move_interval)` to score sequence likelihood.
    
- Autoencoder for sequences: reconstruct human sequences; high reconstruction error → anomaly.
    

### 4) Autoencoders on feature vectors

- Train on legitimate games; anomalies (large reconstruction error) are suspicious.
    

### 5) Hybrid scoring

Combine deterministic rules and ML probability with weighted scoring into final `cheater_score`.

---

# Synthetic cheat dataset generation (practical & necessary)

Labelled cheat data is scarce. Generate synthetic cheats:

1. **Optimal-solver runs**
    
    - Use an A*/IDA* solver to generate optimal solutions for random seeds.
        
    - Create bot traces with near-zero or constant inter-move intervals.
        
2. **Tile-swap attacks**
    
    - Generate final board events where final board differs by multi-tile swap.
        
3. **Replay attacks**
    
    - Replay known solutions but jitter timestamps to mimic human slightly.
        
4. **Noisy-bot**
    
    - Bots that do near-optimal moves but with slightly variable timing.
        
5. **Human play samples**
    
    - Collect from trusted human testers to form positive (legit) class.
        

Label dataset: `legit`, `bot_optimal`, `tile_swap`, `replay_attack`, etc.

---

# Example heuristics & thresholds (starting points — tune with data)

- `illegal_move_count > 0` → immediate flag for human review (or block).
    
- `moves_count < min_possible_moves` → immediate flag.
    
- `ratio_moves_to_min < 1.1` **and** `elapsed_time < 2 * min_possible_moves * human_min_move_ms` (human_min_move_ms ≈ 80–150ms) → high suspicion.
    
- `time_per_move_mean < 40ms` → suspicious (typical human lower bound ~80ms).
    
- `move_time_cv < 0.05` (very low variance in move times) → suspicious.
    
- `move_entropy < 1.0` (very deterministic move patterns) → suspicious.
    

These are starting heuristics — you must calibrate them to your player base.

---

# Server-side pseudocode (validation + scoring)

Here’s a concise pipeline you can run per-game on the server.

`# Elixir-style pseudocode (run after game ends) def process_game(game_log) do   if !valid_move_sequence?(game_log) do     mark_flag(game_log, :illegal_moves)   end    min_moves = compute_min_moves(game_log.initial_board)   features = extract_features(game_log, min_moves)    rule_flags = run_rule_checks(features)   ml_score = ml_model_score(features) # call Python model or precompiled lib    final_score = combine(rule_flags, ml_score)   take_action(final_score, game_log) end`

`take_action` could be `:ignore`, `:warn`, `:shadowban`, `:request_review`, or `:auto_ban`.

---

# Example Python snippet — compute Manhattan lower bound + ratio

`def manhattan_sum(board, size):     # board is list of length size*size containing 0..N-1 where 0 is blank     s = 0     for idx, tile in enumerate(board):         if tile == 0: continue         target_row, target_col = divmod(tile-1, size)         row, col = divmod(idx, size)         s += abs(row - target_row) + abs(col - target_col)     return s  # minimal moves lower bound = manhattan_sum (admissible) min_moves = manhattan_sum(initial_board, 4) ratio = moves_count / max(1, min_moves)`

For exact optimal moves you can run IDA* for 4×4 (maybe expensive); use heuristic + pattern DB for better lower bounds.

---

# Experimental evaluation & metrics

- **Precision @ threshold**: fraction of flagged players actually cheaters — minimize false positives.
    
- **Recall**: fraction of actual cheaters caught — maximize without increasing false positives too much.
    
- **AUC-ROC**, **PR curve**.
    
- **False positive rate** especially critical; measure player churn after false warnings.
    
- **Detection latency**: mean time from cheat action to detection.
    
- **Human review throughput**: how many flagged games/hr.
    

Set up offline evaluation using labelled set (synthetic + reviewed cases), then run a pilot in shadow mode before any punitive action.

---

# Deployment architecture (real-time + offline)

- **Game server**: immediate legal-move validation and hash-chain checks → block/require resync on failure.
    
- **Streaming**: send events to Kafka / RabbitMQ for feature extraction.
    
- **Real-time scoring**: lightweight rule checks + call model API (fast) to compute `cheater_score`.
    
- **Batch jobs**: retrain models daily/weekly on new labelled data.
    
- **Human moderation UI**: show full move trace + visual replay for rapid judgement.
    

Example flow:

`GameServer -> EventLog -> FeatureService -> RealTimeScorer -> ActionService                       -> DataLake -> ModelTrain -> ModelRegistry`

---

# Mitigation strategy (progressive, safe)

1. **Soft actions first** (low risk): shadowban (hide leaderboard), mark for review, send warning.
    
2. **Temporary measures**: cooldowns, loss of rewards pending review.
    
3. **Hard actions** (high confidence): ban account and revoke rewards.
    
4. **Rollback**: if cheating created in-game economy effects, perform restitution.
    
5. **Appeals flow**: provide appeal and human review to minimize wrongful bans.
    

Always log decisions and supporting evidence for audits.

---

# UX & legal considerations

- Avoid false positives — tweeting a wrongful ban is costly.
    
- Notify users when you collect telemetry; follow privacy/regulatory rules.
    
- Provide appeal and explainability (show evidence: timestamps, move trace).
    
- Keep policy consistent and documented.
    

---

# Prioritized roadmap (what to build, in order)

1. **Server-side move validation + hash chaining** — required immediately.
    
2. **Log all moves + initial/final board** to data store.
    
3. **Implement deterministic rule checks** (illegal moves, min-move check).
    
4. **Generate synthetic cheat / legit datasets** and label them.
    
5. **Train simple IsolationForest + XGBoost** on engineered features.
    
6. **Deploy real-time scoring in shadow mode** for 1–2 weeks.
    
7. **Add sequential detector (LSTM/autoencoder)** for move sequences.
    
8. **Human moderation UI + escalation policies**.
    
9. **Iterate thresholds, retrain, A/B test mitigations**.