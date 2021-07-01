#include "../header/Pvector.hpp"

// Constructeur.
Pvector::Pvector(double x, double y) {
    this->x = x;
    this->y = y;
}

// Desctructeur.
Pvector::~Pvector() {
    // std::cout << "Appel du destructeur de Pvector" << std::endl;
}

// Ajoute un vecteur.
void Pvector::add(Pvector v) {
    this->x += v.x;
    this->y += v.y;
}

// Ajoute une constante.
void Pvector::add(double n) {
    this->x += n;
    this->y += n;
}

// Soustrait un vecteur.
void Pvector::sub(Pvector v) {
    this->x -= v.x;
    this->y -= v.y;
}


Pvector Pvector::sub(Pvector v1, Pvector v2) {
    Pvector diff = Pvector(0,0);
    diff.setX(v1.getX() - v2.getX());
    diff.setY(v1.getY() - v2.getY());
    return diff;
}

// Soustrait une constante.
void Pvector::sub(double n) {
    this->x -= n;
    this->y -= n;
}
// Mulitplie un vecteur.
void Pvector::mul(Pvector v) {
    this->x *= v.x;
    this->y *= v.y;
}

// Multiplie une constante.
void Pvector::mul(double n) {
    this->x *= n;
    this->y *= n;
}

// Divise un vecteur.
void Pvector::div(Pvector v) {
    this->x /= v.x;
    this->y /= v.y;
}

// Divise une constante.
void Pvector::div(double n) {
    this->x /= n;
    this->y /= n;
}

// Multiplication scalaire entre 2 vecteurs.
double Pvector::dot(Pvector v) {
    return this->x*v.x + this->y*v.y;
}


// Norme du vecteur.
double Pvector::mag() {
    return sqrt(pow(this->x,2) + pow(this->y,2));
}

// Normalize le vecteur en vecteur unitaire.
void Pvector::normalize() {
    double norme = mag();
    this->x = this->x / norme;
    this->y = this->y / norme;
}

double Pvector::dist(Pvector v) {
    return sqrt(pow(this->x-v.x,2) + pow(this->y-v.y,2));
}

// Angle du vecteur
double Pvector::getAngle(Pvector v) {
    return acos(dot(v) / (mag() * v.mag())) * 180/M_PI;
}

// Limite un vecteur
void Pvector::limit(double max) {
    if (mag() > max) {
        normalize();
        mul(max);
    }
}

Pvector Pvector::seek(Pvector target, Pvector position, double max, Pvector vitesse) {
    position.sub(target);
    position.normalize();
    position.mul(max);

    position.sub(vitesse);
    position.limit(max);  
    return position;
}