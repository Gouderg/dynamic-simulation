#include "../header/Flock.hpp"

Flock::Flock() {
    
    for(int i = 0; i < NB_BIRD; i++) {
        Bird* bird = new Bird(i);
        birds.push_back(bird);
    }
}

Flock::~Flock() {

}

void Flock::update(sf::RenderWindow* window) {
    for (auto elt: getBirds()) {
        Pvector accel = Pvector(0,0);
        Pvector vitesse = elt->getVitesse();
        Pvector position = elt->getPosition();
        // On applique la séparation
        Pvector rep = repulsion(position, vitesse);
        // On applique l'alignement
        Pvector ali = align(position, vitesse);
        // On applique la cohésion
        Pvector coh = cohesion(position, vitesse);
        rep.mul(REPULSION_FORCE);
        ali.mul(ORIENTATION_FORCE);
        coh.mul(ATTRACTION_FORCE);

        // Pour chaque pVector, on mulitplie par la constante associé
        // On ajoute ces 3 forces à l'accélération
        accel.add(rep);
        accel.add(ali);
        accel.add(coh);

        // On ajoute l'accélération à la vitesse
        vitesse.add(accel);
        // On limite la vitesse
        vitesse.limit(MAX_SPEED);
        // On ajoute la vitesse à la position
        position.add(vitesse);
        // On remet l'accélération à 0

        elt->setPosition(position);
        elt->setVitesse(vitesse);

        elt->checkBordure();

        if (elt->getId() == 1) {
            checkNeighbours(elt->getPosition());
        }
		elt->draw(window);
    }
}

void Flock::checkNeighbours(Pvector position) {
    int compteur = 0;
    double distance = 0;
    for (auto elt : getBirds()) {
        distance = elt->getPosition().dist(position);
        if (distance < SIZE_BIRD*2 && distance != 0) {
            // std::cout << position.getAngle(elt->getPosition()) << std::endl;
            compteur += 1;
        }
    }
    // std::cout << compteur << std::endl;
}

// Cohésion
Pvector Flock::cohesion(Pvector position, Pvector vitesse) {
    float count = 0;
    Pvector centre = Pvector(0,0);
    for (auto elt : getBirds()) {
        double d = elt->getPosition().dist(position);
        if (d <= ZONE_ATTRACTION && d > 0) {
            centre.add(elt->getPosition());
            count += 1;
        }
    }
    if (count > 0) {
        centre.div(count);
        return Pvector::seek(centre, position, MAX_SPEED, vitesse);
    }
    

    return Pvector(0,0);
}

// Repulsion
Pvector Flock::repulsion(Pvector position, Pvector vitesse) {
    float count = 1;
    Pvector repulsion = Pvector(0,0);
    for (auto elt : getBirds()) {
        double d = elt->getPosition().dist(position);
        if (d <= ZONE_REPULSION && d > 0) {
            Pvector diff = Pvector::sub(position, elt->getPosition());
            diff.normalize();
            diff.div(d);
            repulsion.add(diff);
            count += 1;
        }
    }

    if (count > 0) {
        repulsion.div(count);
    }

    if (repulsion.mag() > 0) {
        repulsion.normalize();
        repulsion.mul(MAX_SPEED);
        repulsion.sub(vitesse);
        repulsion.limit(MAX_SPEED);
    }

    return repulsion;
}

// Alignement 
Pvector Flock::align(Pvector position, Pvector vitesse) {

    Pvector speed = Pvector(0,0);
    float count = 0;
    for (auto elt : getBirds()) {
        double d = elt->getPosition().dist(position);
        if (d >= ZONE_ORIENTATION && d > 0) {
            speed.add(elt->getVitesse());
            count += 1;
        }
    }

    // S'il y a des voisins
    if (count > 0) {
        speed.div(count);
        speed.normalize();
        speed.mul(MAX_SPEED);
        speed.sub(vitesse);
        speed.limit(MAX_SPEED);
    }

    return speed;
}