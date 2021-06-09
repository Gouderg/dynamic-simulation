#include "../header/Pvector.hpp"

Pvector::Pvector(float x, float y) {
    this->x = x;
    this->y = y;
}

Pvector::~Pvector() {
    // std::cout << "Appel du destructeur de Pvector" << std::endl;
}