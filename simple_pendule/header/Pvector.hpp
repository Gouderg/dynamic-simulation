#pragma once

class Pvector {
    public:
        Pvector(float x, float y);
        ~Pvector();

        // Getter.
        float getX() const {return this->x;}
        float getY() const {return this->y;}
        
        // Setter.
        void setX(const float x) {this->x = x;}
        void setY(const float y) {this->y = y;}

    private:
        float x, y;     // Coordonnées.
};
