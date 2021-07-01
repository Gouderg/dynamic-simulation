#pragma once

#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../header/Pvector.hpp"

#define SIZE_BIRD 8
#define MAX_SPEED 10
#define ZONE_REPULSION SIZE_BIRD*2
#define ZONE_ORIENTATION SIZE_BIRD*3
#define ZONE_ATTRACTION SIZE_BIRD*4
#define ATTRACTION_FORCE 1
#define ORIENTATION_FORCE 1
#define REPULSION_FORCE 1.5



#define WIDTH 1200
#define HEIGHT 1200

class Bird {
    
    public:
        Bird(int id);
        ~Bird();

        // Setter.
        void setPosition(Pvector v) {*this->position = v;}
        void setVitesse(Pvector v) {*this->vitesse = v;}
        void setAcceleration(Pvector v) {*this->acceleration = v;}


        // Getter
        Pvector getPosition() const {return *this->position;}
        Pvector getVitesse() const {return *this->vitesse;}
        Pvector getAcceleration() const {return *this->acceleration;}

        int getRed() const {return this->color[0];}
        int getGreen() const {return this->color[1];}
        int getBlue() const {return this->color[2];}
        int getId() const {return this->id;}


        void update(Pvector speed);
        void draw(sf::RenderWindow* window);
        void checkBordure();
    
    private:
        int color[3];         // Bird color.
        int id;

        Pvector* acceleration;  // Bird Acceleration
        Pvector* vitesse;      // Bird speed.
        Pvector* position;     // Bird position.

};