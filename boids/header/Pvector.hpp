#pragma once

#include <iostream>
#include <cmath>

class Pvector {
    public: 
        Pvector(double x, double y);
        ~Pvector();

        // Getter.
        double getX() const {return this->x;}
        double getY() const {return this->y;}
    
        // Setter.
        void setX(const double x) {this->x = x;}
        void setY(const double y) {this->y = y;}

        // Add.
        void add(Pvector v);
        void add(double n);

        // Sub.
        void sub(Pvector v);
        static Pvector sub(Pvector v1, Pvector v2);

        void sub(double n);

        // Multiplication.
        void mul(Pvector v);
        void mul(double n);

        // Division.
        void div(Pvector v);
        void div(double n);

        // Multiplication scalaire entre 2 vecteurs.
        double dot(Pvector v); 

        // Opération sur les vecteurs.
        double mag();                   // Norme du vecteur
        void normalize();
        double dist(Pvector v);
        double getAngle(Pvector v);
        void limit(double max);
        static Pvector seek(Pvector target, Pvector position, double max, Pvector vitesse);

    private:
        double x, y;
};