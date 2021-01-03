#include <stdio.h>
#include <stdlib.h>
#include "Plateforme.hpp"

Plateforme::Plateforme(Point deb, Point fin): hautGauche(deb), basDroite(fin){

}

Plateforme::Plateforme(int x, int y, int x2, int y2): hautGauche(Point(x,y)), basDroite(Point(x2,y2)){

}

//Get/Set

sf::Sprite Plateforme::getSprite(){
    return sprPlateforme;
}
