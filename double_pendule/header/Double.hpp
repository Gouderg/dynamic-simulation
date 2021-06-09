#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>

#include "../header/Pendule.hpp"

#define NB_DOUBLE 2

class Double {

    public:
        Double(int angle1, int angle2);
        ~Double();

        void update();
        std::vector<Pendule*> getPendules() const {return this->pendules;}
        


    private:
        std::vector<Pendule*> pendules;
};
