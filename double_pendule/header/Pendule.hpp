#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <unistd.h>
#include <cmath>

#include "../header/Pvector.hpp"

#define WIDTH 900               // Largeur de la fenêtre.
#define HEIGHT 600              // Hauteur de la fenêtre.
#define RCO 6                   // Rayon du cercle d'origine.
#define RCM1 10                 // Rayon du cercle de masse1.
#define PI 3.141592653589793    // Constante de PI
#define GRAVITY 9.81        // Constante de gravité
#define FRICTION 0.999       // Coefficient de friction

class Pendule {

    public:
        Pendule(int longueur, double angle, int masse);
        ~Pendule();
        
        // Getter.
        Pvector* getPosition() const {return this->position;}
        Pvector* getOrigine() const {return this->origine;}

        int getLongueur() const {return this->longueur;}
        int getMasse() const {return this->masse;}
        double getAngle() const {return this->angle;}
        double getAngleV() const {return this->angleV;}
        double getAngleA() const {return this->angleA;}

        // Setter
        void setAngle(const double angle) {this->angle = angle;}
        void setAngleV(const double angleV) {this->angleV = angleV;}
        void setAngleA(const double angleA) {this->angleA = angleA;}
        void setPosition(const Pvector position) {*this->position = position;}
        void setOrigine(const Pvector origine) {*this->origine = origine;}

        void update(Pvector origine);
        void draw(sf::RenderWindow* window);


    private:

        int longueur, masse;            // Longueur de la tige et masse de la boule.
        double angle, angleV, angleA;   // Angle de la tige par rapport au centre.

        Pvector* position;      // Position
        Pvector* origine;       // Origine (utile lorsqu'il y a plus de 1 pendule).
};
