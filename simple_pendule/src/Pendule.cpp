#include "../header/Pendule.hpp"

Pendule::Pendule(int longueur, double angle) {

    this->longueur = longueur;
    this->angle = angle;
    this->angleA = 0;
    this->angleV = 0;

    // Calcul de la position initial en fonction de l'angle et de la longueur.
    this->position = new Pvector(sin(angle * (PI/180)) * longueur, cos(angle * (PI/180)) * longueur);

}

Pendule::~Pendule() {
    // std::cout << "Appel du destructeur de pendule" << std::endl;
}

void Pendule::update() {

    // Add gravity.
    this->angleA = (-1) * GRAVITY * sin(this->angle * (PI/180)) / this->longueur;
    
    // Add friction.
    // this->angleV *= FRICTION;

    this->angleV += this->angleA;
    this->angle += this->angleV;

    this->position->setX(sin(this->angle * (PI/180)) * this->longueur);
    this->position->setY(cos(this->angle * (PI/180)) * this->longueur); 
}

void Pendule::draw(sf::RenderWindow* window) {

    // Origine.
    sf::CircleShape origine(RCO);                                     // Création d'un cercle de rayon.
    origine.setPosition(WIDTH/2 - RCO, HEIGHT - HEIGHT*0.5 - RCO);    // Mise du cercle au centre de l'écran
    window->draw(origine);

    // Tige
    sf::Vertex tige[] = { 
        sf::Vertex(sf::Vector2f(WIDTH/2, HEIGHT - HEIGHT*0.5)), 
        sf::Vertex(sf::Vector2f(WIDTH/2 + position->getX(), HEIGHT - HEIGHT*0.5 + position->getY()))
    };
    window->draw(tige,2,sf::Lines);

    // Masse    
    sf::CircleShape masse1(RCM1);
    masse1.setPosition(WIDTH/2 + position->getX() - RCM1, HEIGHT - HEIGHT*0.5 + position->getY() - RCM1);
    window->draw(masse1);
}