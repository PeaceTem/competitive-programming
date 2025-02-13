#include <iostream>
#include <cmath>
#include <vector>

const double G = 1.0; // Gravitational constant (scaled for simplicity)
const double dt = 0.01; // Time step
const int steps = 1000; // Number of simulation steps

// Structure to represent a 2D vector (position, velocity, force)
struct Vec2 {
    double x, y;

    Vec2 operator+(const Vec2 &v) const { return {x + v.x, y + v.y}; }
    Vec2 operator-(const Vec2 &v) const { return {x - v.x, y - v.y}; }
    Vec2 operator*(double scalar) const { return {x * scalar, y * scalar}; }
    Vec2 operator/(double scalar) const { return {x / scalar, y / scalar}; }
};

// Structure to represent a body (mass, position, velocity)
struct Body {
    double mass;
    Vec2 pos, vel;
};

// Compute gravitational force between two bodies
Vec2 gravitationalForce(const Body &a, const Body &b) {
    Vec2 r = b.pos - a.pos;
    double dist = std::sqrt(r.x * r.x + r.y * r.y) + 1e-6; // Avoid division by zero
    double forceMagnitude = (G * a.mass * b.mass) / (dist * dist);
    return r * (forceMagnitude / dist); // Normalize direction
}

// Compute total force on a body due to all others
Vec2 computeNetForce(const Body &body, const std::vector<Body> &bodies) {
    Vec2 netForce = {0, 0};
    for (const auto &other : bodies) {
        if (&body != &other) { // Avoid self-interaction
            netForce = netForce + gravitationalForce(body, other);
        }
    }
    return netForce;
}

// Runge-Kutta 4th Order (RK4) Integration
void updateBodies(std::vector<Body> &bodies) {
    std::vector<Body> k1 = bodies, k2 = bodies, k3 = bodies, k4 = bodies;
    
    for (size_t i = 0; i < bodies.size(); i++) {
        Vec2 f1 = computeNetForce(k1[i], k1);
        k2[i].pos = bodies[i].pos + k1[i].vel * (dt / 2);
        k2[i].vel = bodies[i].vel + f1 * (dt / (2 * bodies[i].mass));
        
        Vec2 f2 = computeNetForce(k2[i], k2);
        k3[i].pos = bodies[i].pos + k2[i].vel * (dt / 2);
        k3[i].vel = bodies[i].vel + f2 * (dt / (2 * bodies[i].mass));

        Vec2 f3 = computeNetForce(k3[i], k3);
        k4[i].pos = bodies[i].pos + k3[i].vel * dt;
        k4[i].vel = bodies[i].vel + f3 * (dt / bodies[i].mass);
    }

    for (size_t i = 0; i < bodies.size(); i++) {
        Vec2 f4 = computeNetForce(k4[i], k4);
        bodies[i].pos = bodies[i].pos + (k1[i].vel + k2[i].vel * 2 + k3[i].vel * 2 + k4[i].vel) * (dt / 6);
        bodies[i].vel = bodies[i].vel + (computeNetForce(k1[i], k1) + computeNetForce(k2[i], k2) * 2 +
                                         computeNetForce(k3[i], k3) * 2 + f4) * (dt / (6 * bodies[i].mass));
    }
}

int main() {
    // Initial conditions: mass, position (x, y), velocity (x, y)
    std::vector<Body> bodies = {
        {5.0, {0, 0}, {0, 0}},   // Central massive body
        {1.0, {5, 0}, {0, 1.5}}, // Orbiting body
        {1.0, {-5, 0}, {0, -1.5}} // Another orbiting body
    };

    for (int i = 0; i < steps; i++) {
        updateBodies(bodies);
        
        // Print positions to visualize (e.g., using Python/Matplotlib)
        std::cout << bodies[0].pos.x << " " << bodies[0].pos.y << " "
                  << bodies[1].pos.x << " " << bodies[1].pos.y << " "
                  << bodies[2].pos.x << " " << bodies[2].pos.y << std::endl;
    }

    return 0;
}
