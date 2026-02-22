ffmpeg -f gdigrab -framerate 60 -i desktop ^
-f dshow -i audio="Microphone (Realtek Audio)" ^
-f dshow -i audio="Stereo Mix (Realtek Audio)" ^
-filter_complex amix=inputs=2 ^
-c:v libx264 -preset veryfast -crf 23 -pix_fmt yuv420p ^
-c:a aac -b:a 192k final_output.mp4


# 🚀 **6-Month STL Roadmap for Competitive Programming**

## ✅ **Month 1 — Foundations + Containers**

### Learn

- `vector`
    
- `array`
    
- `string`
    
- `pair`, `tuple`
    
- `stack`, `queue`, `deque`
    
- Iterators & ranges
    
- Basic I/O speed (e.g., `ios::sync_with_stdio(false)`)
    

### Practice Problems

- Dynamic arrays (dynamic size)
    
- Prefix sums using vectors
    
- Stack/Queue simulation problems (parentheses, FIFO simulation)
    
- Deque: sliding window maximum
    

### Goal

➡ Be comfortable using containers + iterators efficiently.

---

## 🟦 **Month 2 — Sorting, Searching & Fundamental Algorithms**

### Learn

- `sort`, custom comparators (`struct`, lambda)
    
- `reverse`, `rotate`, `unique`, `next_permutation`
    
- `binary_search`, `lower_bound`, `upper_bound`
    
- `min_element`, `max_element`, `accumulate`
    

### Practice Problems

- Sorting with custom criteria (by pair.second, by abs difference)
    
- Frequency compression using `unique`
    
- Binary searching on arrays
    
- Next permutation problems
    

### Goal

➡ Competence in sorting + running binary search fast.

---

## 🟩 **Month 3 — Sets, Maps, and Ordered Containers**

### Learn

- `set`, `multiset`
    
- `map`, `multimap`
    
- Ordered queries
    
- Erase operations, iterator invalidation
    
- Custom comparators, descending order
    

### Practice Problems

- Keeping track of min/max dynamically (set)
    
- Multiset erase (one element version)
    
- Counting frequencies using map
    
- Order statistics type problems
    

### Goal

➡ Manage ordered data where insert/remove/query happens often.

---

## 🟨 **Month 4 — Advanced Containers & Tricks**

### Learn

- `unordered_map`, `unordered_set`
    
- Hashing vs Tree-based
    
- `bitset`
    
- 2D vectors, vector of vectors
    
- `priority_queue` (min & max)
    
- Custom PQ comparators
    

### Practice Problems

- Dijkstra using priority queue
    
- Hash maps for sliding windows (frequency tracking)
    
- Bitmask DP intros using bitset
    
- Solve problems with unordered_map (subarray sums)
    

### Goal

➡ Use hashing & priority queues for O(1) lookup / optimal graph tasks.

---

## 🟥 **Month 5 — Graph Algorithms + Advanced STL Usage**

### STL Focus

- Adjacency list using `vector<vector<int>>`
    
- Graph traversal using:
    
    - `queue` (BFS)
        
    - `stack` (DFS)
        
    - `priority_queue` (Dijkstra)
        
- `queue` for BFS grid
    
- `vector<pair<int,int>>` for weighted edges
    

### Practice Problems

- BFS + shortest path in unweighted graph
    
- DFS connected components
    
- Dijkstra shortest path
    
- Topological sort
    

### Goal

➡ Build routine graph templates using STL.

---

## 🟪 **Month 6 — Optimization, Speed, Competitive Templates**

### STL Focus

- Speed tricks (reserve, shrink_to_fit)
    
- Memory optimization
    
- `emplace` vs `push`
    
- Using `chrono` for profiling
    
- Debug macros
    
- Building reusable templates:
    
    - graph template
        
    - Dijkstra template
        
    - frequency counter template
        
    - sort + comparator template
        

### Practice Problems

- Solve mixed contests
    
- Timed practice on Codeforces/AtCoder
    
- Participate in Div3/Div2
    

### Goal

➡ Fast implementation + reduced memory + contest readiness.



## The 6 real worlds where C++ dominates

I’ll give you **concrete applications**, what you’d build, and how to start.

---

## 1️⃣ Systems & Infrastructure (best general-purpose path)

### What C++ does here

- Memory allocators
    
- Databases
    
- Compilers
    
- Runtime engines
    
- High-performance servers
    

### Example projects

- Write a **memory pool allocator**
    
- Build a **key-value store** (Redis-lite)
    
- Implement a **thread pool**
    
- Write a **simple HTTP server** using epoll
    

### Skills you’ll learn

- RAII
    
- cache locality
    
- threading
    
- atomics
    
- lock-free design
    

### Why this is elite

This path makes you a **strong software engineer**, not just “a C++ dev”.

---

## 2️⃣ Competitive Programming → Interview muscle

You already touch this world.

### What C++ does here

- Fast IO
    
- Low-level optimizations
    
- STL mastery
    

### Build focus

- Custom segment tree
    
- LRU cache
    
- Graph algorithms
    
- Union-Find optimizations
    

### Why it matters

- C++ forces algorithmic clarity
    
- You build speed + correctness instincts
    
- Translates directly to interviews
    

This is **training**, not the end goal.

---

## 3️⃣ Game Engines & Simulations

### What C++ does here

- Real-time constraints
    
- Physics engines
    
- ECS (Entity-Component-System)
    

### Example projects

- 2D game engine core
    
- Particle system
    
- Physics collision engine
    
- Simple renderer
    

### Skills

- Data-oriented design
    
- Performance profiling
    
- Cache-friendly layouts
    

---

## 4️⃣ Finance / Trading Systems

### What C++ does here

- Ultra-low latency
    
- Deterministic behavior
    
- High-throughput systems
    

### Example projects

- Order matching engine
    
- Market data parser
    
- Lock-free ring buffer
    

### Skills

- nanosecond-level thinking
    
- concurrency without GC
    
- systems correctness
    

This is _very_ hard — but very valuable.

---

## 5️⃣ Embedded / Robotics (Linux-level, not bare metal)

### What C++ does here

- Sensor drivers
    
- Real-time-ish control
    
- Hardware abstraction layers
    

### Example projects

- GPIO controller
    
- Motor controller logic
    
- Sensor fusion engine
    

---

## 6️⃣ Developer Tools (underrated & powerful)

### What C++ does here

- Compilers
    
- Static analyzers
    
- Debuggers
    
- Formatters
    

### Example projects

- Code formatter
    
- AST parser
    
- Static checker
    

---

## The biggest mistake to avoid

❌ Random tutorials  
❌ “Learn C++ in 30 days”  
❌ Syntax-first learning

C++ is learned **backwards**:

> pain → need → feature → mastery

---

## A concrete 90-day path (do this)

### Month 1: Core systems mindset

Build:

- Dynamic array (vector clone)
    
- Smart pointer (`unique_ptr` clone)
    
- Thread pool
    

Learn:

- move semantics
    
- RAII
    
- memory layout
    

---

### Month 2: Concurrency + performance

Build:

- Producer–consumer queue
    
- LRU cache
    
- Timer wheel
    

Learn:

- atomics
    
- mutex vs lock-free
    
- false sharing
    

---

### Month 3: Real project

Pick ONE:

- KV store
    
- HTTP server
    
- Game engine core
    
- Matching engine
    

Make it:

- documented
    
- benchmarked
    
- clean
    

---

## How you know you’re “doing C++ right”

You start asking:

- “Who owns this memory?”
    
- “What’s the lifetime?”
    
- “Is this cache-friendly?”
    
- “Can this be lock-free?”
    
- “What happens under load?”
    

That’s the C++ mindset.

---

## Career reality (important)

If you combine:

- **C++ systems skill**
    
- **your existing software engineering background**
    

You become:

- backend infra engineer
    
- systems engineer
    
- performance engineer
    
- embedded Linux engineer
    

Very few people can do this well.

---

## I won’t leave you hanging

Let’s make this actionable.

**Pick one direction** and I’ll:

- design a **starter project**
    
- define **milestones**
    
- give **reading + tooling**
    
- review architecture
    

👉 Reply with one of these:

- Systems / infra
    
- Game engine
    
- Finance / low-latency
    
- Embedded / robotics
    
- “I want the most hireable path”
    

We’ll build from there.



```
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <utility>
#include <algorithm>

template <typename T>
class Vector {
public:
    using value_type = T;
    using size_type = std::size_t;
    using iterator = T*;
    using const_iterator = const T*;

private:
    T* data_;
    size_type size_;
    size_type capacity_;

    void destroy_elements() {
        for (size_type i = 0; i < size_; ++i)
            data_[i].~T();
        size_ = 0;
    }

    void reallocate(size_type new_cap) {
        T* new_data = static_cast<T*>(::operator new(sizeof(T) * new_cap));

        size_type i = 0;
        try {
            for (; i < size_; ++i)
                new (new_data + i) T(std::move_if_noexcept(data_[i]));
        } catch (...) {
            for (size_type j = 0; j < i; ++j)
                new_data[j].~T();
            ::operator delete(new_data);
            throw;
        }

        destroy_elements();
        ::operator delete(data_);

        data_ = new_data;
        capacity_ = new_cap;
        size_ = i;
    }

public:
    // Constructors
    Vector() : data_(nullptr), size_(0), capacity_(0) {}

    explicit Vector(size_type count, const T& value = T())
        : Vector() {
        reserve(count);
        for (size_type i = 0; i < count; ++i)
            push_back(value);
    }

    // Copy constructor
    Vector(const Vector& other) : Vector() {
        reserve(other.size_);
        for (const auto& x : other)
            push_back(x);
    }

    // Move constructor
    Vector(Vector&& other) noexcept
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr;
        other.size_ = other.capacity_ = 0;
    }

    // Copy assignment
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            destroy_elements();
            reserve(other.size_);
            for (const auto& x : other)
                push_back(x);
        }
        return *this;
    }

    // Move assignment
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            destroy_elements();
            ::operator delete(data_);
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
        return *this;
    }

    // Destructor
    ~Vector() {
        destroy_elements();
        ::operator delete(data_);
    }

    // Element access
    T& operator[](size_type i) { return data_[i]; }
    const T& operator[](size_type i) const { return data_[i]; }

    T& at(size_type i) {
        if (i >= size_) throw std::out_of_range("Vector::at");
        return data_[i];
    }

    // Capacity
    size_type size() const { return size_; }
    size_type capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }

    void reserve(size_type new_cap) {
        if (new_cap > capacity_)
            reallocate(new_cap);
    }

    void resize(size_type count, T value = T()) {
        if (count < size_) {
            for (size_type i = count; i < size_; ++i)
                data_[i].~T();
        } else if (count > size_) {
            reserve(count);
            for (size_type i = size_; i < count; ++i)
                new (data_ + i) T(value);
        }
        size_ = count;
    }

    // Modifiers
    void push_back(const T& value) {
        if (size_ == capacity_)
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        new (data_ + size_) T(value);
        ++size_;
    }

    void push_back(T&& value) {
        if (size_ == capacity_)
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        new (data_ + size_) T(std::move(value));
        ++size_;
    }

    void pop_back() {
        if (size_ == 0) return;
        data_[--size_].~T();
    }

    void clear() {
        destroy_elements();
    }

    // Iterators
    iterator begin() { return data_; }
    iterator end() { return data_ + size_; }
    const_iterator begin() const { return data_; }
    const_iterator end() const { return data_ + size_; }
};

```

# 1️⃣ HTTP Server (epoll-based, Linux)

### What this teaches

- sockets
    
- non-blocking I/O
    
- event loops
    
- real backend infra skills
    

### Minimal HTTP server core

```
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    bind(server_fd, (sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 128);

    int ep = epoll_create1(0);
    epoll_event ev{EPOLLIN, {.fd = server_fd}};
    epoll_ctl(ep, EPOLL_CTL_ADD, server_fd, &ev);

    epoll_event events[64];

    while (true) {
        int n = epoll_wait(ep, events, 64, -1);
        for (int i = 0; i < n; i++) {
            if (events[i].data.fd == server_fd) {
                int client = accept4(server_fd, nullptr, nullptr, SOCK_NONBLOCK);
                epoll_event cev{EPOLLIN, {.fd = client}};
                epoll_ctl(ep, EPOLL_CTL_ADD, client, &cev);
            } else {
                int fd = events[i].data.fd;
                char buf[1024];
                read(fd, buf, sizeof(buf));
                const char* resp =
                    "HTTP/1.1 200 OK\r\nContent-Length: 5\r\n\r\nHello";
                write(fd, resp, strlen(resp));
                close(fd);
            }
        }
    }
}

```

➡️ Extend with:

- thread pool
    
- request parsing
    
- keep-alive
    
- routing

# 2️⃣ Thread Pool (production-style)

### What this teaches

- concurrency
    
- condition variables
    
- task scheduling

```
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

class ThreadPool {
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex mtx;
    std::condition_variable cv;
    bool stop = false;

public:
    ThreadPool(size_t n) {
        for (size_t i = 0; i < n; i++) {
            workers.emplace_back([this] {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock lk(mtx);
                        cv.wait(lk, [&]{ return stop || !tasks.empty(); });
                        if (stop && tasks.empty()) return;
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
        }
    }

    template<class F>
    void submit(F&& f) {
        {
            std::lock_guard lk(mtx);
            tasks.emplace(std::forward<F>(f));
        }
        cv.notify_one();
    }

    ~ThreadPool() {
        {
            std::lock_guard lk(mtx);
            stop = true;
        }
        cv.notify_all();
        for (auto& t : workers) t.join();
    }
};

```

➡️ Extend with:

- futures
    
- work stealing
    
- priority queues

# 3️⃣ KV Store (in-memory, Redis-lite)

### What this teaches

- data structures
    
- concurrency control
    
- persistence hooks
```
#include <unordered_map>
#include <shared_mutex>
#include <string>

class KVStore {
    std::unordered_map<std::string, std::string> map;
    mutable std::shared_mutex mtx;

public:
    void put(const std::string& k, const std::string& v) {
        std::unique_lock lk(mtx);
        map[k] = v;
    }

    bool get(const std::string& k, std::string& out) const {
        std::shared_lock lk(mtx);
        auto it = map.find(k);
        if (it == map.end()) return false;
        out = it->second;
        return true;
    }

    void del(const std::string& k) {
        std::unique_lock lk(mtx);
        map.erase(k);
    }
};

```
➡️ Extend with:

- WAL logging
    
- snapshots
    
- LRU eviction
    
- networking layer

# 4️⃣ Game Engine Core (ECS-style)

### What this teaches

- data-oriented design
    
- cache friendliness
    
- real-time loops

```
#include <unordered_map>
#include <vector>

using Entity = uint32_t;

struct Position { float x, y; };
struct Velocity { float vx, vy; };

class Registry {
    Entity next = 1;
public:
    std::vector<Entity> entities;
    std::unordered_map<Entity, Position> pos;
    std::unordered_map<Entity, Velocity> vel;

    Entity create() {
        Entity e = next++;
        entities.push_back(e);
        return e;
    }
};

void movement_system(Registry& r, float dt) {
    for (auto e : r.entities) {
        if (r.pos.count(e) && r.vel.count(e)) {
            r.pos[e].x += r.vel[e].vx * dt;
            r.pos[e].y += r.vel[e].vy * dt;
        }
    }
}

```

➡️ Extend with:

- component pools
    
- spatial partitioning
    
- render loop

# 5️⃣ Matching Engine (trading core)

### What this teaches

- correctness under concurrency
    
- data structures
    
- performance discipline

```
#include <map>
#include <queue>

struct Order {
    int id;
    int qty;
};

std::map<int, std::queue<Order>, std::greater<int>> buy;
std::map<int, std::queue<Order>> sell;

void match() {
    while (!buy.empty() && !sell.empty()) {
        auto& b = buy.begin()->second.front();
        auto& s = sell.begin()->second.front();

        int traded = std::min(b.qty, s.qty);
        b.qty -= traded;
        s.qty -= traded;

        if (b.qty == 0) buy.begin()->second.pop();
        if (s.qty == 0) sell.begin()->second.pop();

        if (buy.begin()->second.empty()) buy.erase(buy.begin());
        if (sell.begin()->second.empty()) sell.erase(sell.begin());
    }
}

```

➡️ Extend with:

- timestamps
    
- lock-free queues
    
- persistence
    
- recovery
# 6️⃣ Neural Network (from scratch, forward pass)

### What this teaches

- numerical computing
    
- memory layout
    
- performance

```
#include <vector>
#include <cmath>

struct Dense {
    std::vector<float> w, b;
    int in, out;

    Dense(int i, int o) : in(i), out(o),
        w(i * o), b(o) {}

    std::vector<float> forward(const std::vector<float>& x) {
        std::vector<float> y(out, 0.0f);
        for (int j = 0; j < out; j++) {
            for (int i = 0; i < in; i++)
                y[j] += x[i] * w[j * in + i];
            y[j] += b[j];
            y[j] = std::max(0.0f, y[j]); // ReLU
        }
        return y;
    }
};

```

➡️ Extend with:

- backprop
    
- SIMD
    
- batching
    
- GPU offload