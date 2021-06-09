#include "../header/Double.hpp"

Double::Double(int angle1, int angle2) {

    Pendule* pendule1 = new Pendule(75, angle1, 10);
    pendules.push_back(pendule1);
    Pendule* pendule2 = new Pendule(150, angle2, 10);
    pendules.push_back(pendule2);
}

Double::~Double() {
    // std::cout << "Appel du destructeur de Double" << std::endl;
}

void Double::update() {

    // Récupération des constantes.
    // Pendule 1.
    float m1 = this->pendules[0]->getMasse();
    float t1 = this->pendules[0]->getAngle() * PI/180;
    float tp1 = this->pendules[0]->getAngleV() * PI/180;
    float l1 = this->pendules[0]->getLongueur();
    
    // Pendule 2.
    float m2 = this->pendules[1]->getMasse();
    float t2 = this->pendules[1]->getAngle() * PI/180;
    float tp2 = this->pendules[1]->getAngleV() * PI/180;
    float l2 = this->pendules[1]->getLongueur();


    // Angle Accélération 1.
    float tpp1 = (-GRAVITY*(2*m1+m2)*sin(t1)-m2*GRAVITY*sin(t1-2*t2)-2*sin(t1-t2)*m2*(pow(tp2,2)*l2+pow(tp1,2)*l1*cos(t1-t2))) / (l1 * (2*m1 + m2 - m2*cos(2*t1-2*t2)));

    // Angle Accélération 2.
    float tpp2 = (2*sin(t1-t2)*(pow(tp1,2)*l1*(m1+m2)+GRAVITY*(m1+m2)*cos(t1)+pow(tp2,2)*l2*m2*cos(t1-t2))) / (l2*(2*m1+m2-m2*cos(2*t1-2*t2)));

    // Mise à jour des valeurs pour le pendule 1.
    this->pendules[0]->setAngleA(tpp1);
    
    // Avec friction.
    // this->pendules[0]->setAngleV((this->pendules[0]->getAngleV() + this->pendules[0]->getAngleA()) * FRICTION);
    // Sans criction.
    this->pendules[0]->setAngleV(this->pendules[0]->getAngleV() + this->pendules[0]->getAngleA());
    
    this->pendules[0]->setAngle(this->pendules[0]->getAngle() + this->pendules[0]->getAngleV());

    this->pendules[0]->setOrigine(Pvector(WIDTH/2, HEIGHT*0.5));
    this->pendules[0]->getPosition()->setX(this->pendules[0]->getOrigine()->getX() + sin(this->pendules[0]->getAngle() * (PI/180)) * this->pendules[0]->getLongueur());
    this->pendules[0]->getPosition()->setY(this->pendules[0]->getOrigine()->getY() + cos(this->pendules[0]->getAngle() * (PI/180)) * this->pendules[0]->getLongueur());


    // Mise à jour des valeurs pour le pendule 2.
    this->pendules[1]->setOrigine(*this->pendules[0]->getPosition());
    this->pendules[1]->setAngleA(tpp2);
    
    // Avec friction.
    // this->pendules[1]->setAngleV((this->pendules[1]->getAngleV() + this->pendules[1]->getAngleA()) * FRICTION);
    // Sans friction.
    this->pendules[1]->setAngleV(this->pendules[1]->getAngleV() + this->pendules[1]->getAngleA());

    this->pendules[1]->setAngle(this->pendules[1]->getAngle() + this->pendules[1]->getAngleV());

    this->pendules[1]->getPosition()->setX(this->pendules[1]->getOrigine()->getX() + sin(this->pendules[1]->getAngle() * (PI/180)) * this->pendules[1]->getLongueur());
    this->pendules[1]->getPosition()->setY(this->pendules[1]->getOrigine()->getY() + cos(this->pendules[1]->getAngle() * (PI/180)) * this->pendules[1]->getLongueur());

}