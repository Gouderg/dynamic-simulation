#include "../header/Pendule.hpp"

Pendule::Pendule(int longueur, double angle, int masse) {

    this->longueur = longueur;
    this->angle = angle;
    this->masse = masse;
    this->angleA = 0;
    this->angleV = 0;

    // Calcul de la position initial en fonction de l'angle et de la longueur.
    this->position = new Pvector(sin(angle * (PI/180)) * longueur, cos(angle * (PI/180)) * longueur);
    this->origine = new Pvector(0,0);
}

Pendule::~Pendule() {
    // std::cout << "Appel du destructeur de pendule" << std::endl;
}



void Pendule::draw(sf::RenderWindow* window) {
    // Origine.
    sf::CircleShape centre(RCO);                                     // Création d'un cercle de rayon.
    centre.setPosition(WIDTH/2 - RCO, HEIGHT*0.5 - RCO);    // Mise du cercle au centre de l'écran
    window->draw(centre);

    // Tige
    sf::Vertex tige[] = { 
        sf::Vertex(sf::Vector2f(this->origine->getX(), this->origine->getY())), 
        sf::Vertex(sf::Vector2f(this->position->getX(), this->position->getY()))
    };
    window->draw(tige,2,sf::Lines);

    // Masse    
    sf::CircleShape masse1(RCM1);                                     // Création d'un cercle de rayon.
    masse1.setPosition(this->position->getX() - RCM1,this->position->getY() - RCM1);    // Mise du cercle au centre de l'écran
    window->draw(masse1);
}