#pragma once

#include <iostream>
#include <vector>
#include <ctime>

#include "../header/Bird.hpp"
#include "../header/Pvector.hpp"


#define NB_BIRD 500

class Flock {

    public:
        Flock();
        ~Flock();

        void update(sf::RenderWindow* window);
        void checkNeighbours(Pvector position);
        Pvector cohesion(Pvector positionn, Pvector vitesse);
        Pvector repulsion(Pvector position, Pvector vitesse);
        Pvector align(Pvector position, Pvector vitesse);

        std::vector<Bird*> getBirds() const {return this->birds;}


    private:
        std::vector<Bird*> birds;
};