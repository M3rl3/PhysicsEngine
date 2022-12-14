#include "Particle.h"

Particle::Particle() /*: position(Vector3(0.f))
, velocity(Vector3(0.f))
, acceleration(Vector3(0.f))
, damping(1.f)
, mass(1.f)*/
{
    this->position = Vector3(0.f);
    this->velocity = Vector3(0.f);
    this->acceleration = Vector3(0.f);
    this->damping = 1.f;
    this->mass = 1.f;
}

Particle::~Particle() {

}


//Calculate particle position and velocity
void Particle::calculate(float dt) {
    velocity.scalevector(acceleration, dt);
    velocity = velocity * damping;
    position.scalevector(velocity, dt);
    
    //velocity = velocity + acceleration * dt;
    //velocity = velocity * damping;
    //position = position + velocity * dt;
}

void Particle::print0(float dt) {
    std::cout << "position = " << position.y << " + " << velocity.y << " * " << dt << "\n";
    velocity = velocity + acceleration * dt;
    std::cout << "position = " << position.y << " + " << velocity.y << " * " << dt << "\n";
    position = position + velocity * dt;
}

void Particle::print1() {
    std::cout << "\nPosition: (" << position.x << ", " << position.y << ", " << position.z << ") " << std::endl;
    std::cout << "\nVelocity: (" << velocity.x << ", " << velocity.y << ", " << velocity.z << ") " << std::endl;

}