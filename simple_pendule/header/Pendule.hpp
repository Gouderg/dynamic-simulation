#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cmath>

#include "../header/Pvector.hpp"


#define WIDTH 900               // Largeur de la fenêtre.
#define HEIGHT 600              // Hauteur de la fenêtre.
#define RCO 6                   // Rayon du cercle d'origine.
#define RCM1 20                 // Rayon du cercle de masse1.
#define PI 3.141592653589793    // Constante de PI
#define GRAVITY 9.81            // Constante de gravité
#define FRICTION 0.99           // Coefficient de friction

class Pendule {

    public:
        Pendule(int longueur, double angle);
        ~Pendule();
        
        // Getter
        Pvector* getPosition() const {return this->position;}

        void update();
        void draw(sf::RenderWindow* window);

    private:

        int longueur;                             // Longueur de la tige (en pixel).
        double angle, angleV, angleA;             // Angle de la tige par rapport au centre
        Pvector* position;                        // Position

};
