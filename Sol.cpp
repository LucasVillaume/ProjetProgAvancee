#include <stdio.h>
#include <stdlib.h>
#include "Sol.hpp"

Sol::Sol(Point deb, Point fin): Plateforme(deb, fin){
    if (!texturePlateforme.loadFromFile("../ressources/TextureSol.png")){
    }
    
    texturePlateforme.setSmooth(true);
    texturePlateforme.setRepeated(true);
    sprPlateforme.setTexture(texturePlateforme);
    sprPlateforme.setPosition(0.f,301.f);
}

Sol::Sol(int x, int y, int x2, int y2): Plateforme(x,y,x2,y2){
    if (!texturePlateforme.loadFromFile("../ressources/TextureSol.png")){
    }
    
    texturePlateforme.setSmooth(true);
    texturePlateforme.setRepeated(true);
    sprPlateforme.setTexture(texturePlateforme);
    sprPlateforme.setPosition(0.f,301.f);
}
