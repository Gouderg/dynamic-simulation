#include "../header/Bird.hpp"

// Constructeur.
Bird::Bird(int id) {
    // Attribution de la couleur de l'oiseau
    for (int j = 0; j < 3; j++) {
        this->color[j] = std::rand()%255;
    }
    // this->position = new Pvector(rand() % WIDTH,rand() % HEIGHT);
    this->position = new Pvector(WIDTH/2,HEIGHT/2);
    this->vitesse = new Pvector(rand() % 6-3 , rand() % 6-3);
    this->id = id;
}

// Destructeur.
Bird::~Bird() {
    // std::cout << "Appel du destructeur de Bird" << std::endl;
}

// Dessine l'oiseau avec sa nouvelle position.
void Bird::draw(sf::RenderWindow* window) {
    
    // Coordonnées centre
    double x = this->position->getX();
    double y = this->position->getY();
    
    // Angle entre les deux points par rapport à l'origine
    double angle = M_PI - atan2(this->vitesse->getX(),this->vitesse->getY());

    // Dessin de l'oiseau.
    sf::ConvexShape bird;
    bird.setPointCount(4);
	bird.setPoint(0, sf::Vector2f(x, y));
	bird.setPoint(1, sf::Vector2f(x + (SIZE_BIRD/2) * cos(angle) + (-SIZE_BIRD/2) * sin(angle), y + SIZE_BIRD/2 * sin(angle) + (SIZE_BIRD/2) * cos(angle)));
	bird.setPoint(2, sf::Vector2f(x+ (SIZE_BIRD) * sin(angle), y + (-SIZE_BIRD) * cos(angle)));
	bird.setPoint(3, sf::Vector2f(x + (-SIZE_BIRD/2) * cos(angle) + (-SIZE_BIRD/2) * sin(angle), y + (-SIZE_BIRD/2) * sin(angle) + SIZE_BIRD/2 * cos(angle)));
    bird.setFillColor(sf::Color(this->getRed(), this->getGreen(), this->getBlue()));
    window->draw(bird);

    if (this->id == 1) {
        sf::CircleShape circle(ZONE_REPULSION);
        circle.setPosition(x - ZONE_REPULSION,y - ZONE_REPULSION);
        circle.setFillColor(sf::Color(this->getRed(), this->getGreen(), this->getBlue(), 75));
        window->draw(circle);

        sf::CircleShape circle1(ZONE_ORIENTATION);
        circle1.setPosition(x - ZONE_ORIENTATION,y - ZONE_ORIENTATION);
        circle1.setFillColor(sf::Color(this->getRed(), this->getGreen(), this->getBlue(), 50));
        window->draw(circle1);

        sf::CircleShape circle2(ZONE_ATTRACTION);
        circle2.setPosition(x - ZONE_ATTRACTION,y - ZONE_ATTRACTION);
        circle2.setFillColor(sf::Color(this->getRed(), this->getGreen(), this->getBlue(), 25));
        window->draw(circle2);
    }
    
}

// Fais évoluer la position de l'oiseau.
void Bird::update(Pvector speed) {
    // Mise à jour de la vitesse
    this->vitesse->add(speed);

    this->position->add(*this->vitesse);

    checkBordure();
}

void Bird::checkBordure() {

    // Coordonnées
    double x = this->position->getX();
    double y = this->position->getY();

    // WIDTH
    if (x - SIZE_BIRD < 0) this->position->setX(WIDTH - SIZE_BIRD);
    else if (x + SIZE_BIRD > WIDTH) this->position->setX(SIZE_BIRD);

    // HEIGHT
    if (y - SIZE_BIRD < 0) this->position->setY(HEIGHT - SIZE_BIRD);
    else if (y + SIZE_BIRD > HEIGHT) this->position->setY(SIZE_BIRD);   
}