#include <stdio.h>
#include <stdlib.h>
#include "Sol.hpp"

Sol::Sol(Point deb, Point fin): Plateforme(deb, fin){
    if (!texturePlateforme.loadFromFile("../ressources/TexturePlateforme/TextureSol.png")){
    }
    
    texturePlateforme.setSmooth(true);
    texturePlateforme.setRepeated(true);
    sprPlateforme.setTexture(texturePlateforme);
    sprPlateforme.setOrigin(0,fin.getAbscisse()-deb.getAbscisse());
    sprPlateforme.setPosition(deb.getAbscisse(),deb.getOrdonnee());
    
    float x_lim = (fin.getAbscisse()-deb.getAbscisse())/100;
    float y_lim = (fin.getOrdonnee()-deb.getOrdonnee())/100;
    sprPlateforme.setScale(x_lim,y_lim);
}

Sol::Sol(int x, int y, int x2, int y2): Plateforme(x,y,x2,y2){
    if (!texturePlateforme.loadFromFile("../ressources/TexturePlateforme/TextureSol.png")){
    }
    
    texturePlateforme.setSmooth(true);
    texturePlateforme.setRepeated(true);
    sprPlateforme.setTexture(texturePlateforme);
    sprPlateforme.setOrigin(0,0);
    sprPlateforme.setPosition(x,y);
    
    float x_lim = (x2-x)/100;   //x2-x: la largueur de la plateforme
    float y_lim = (y2-y)/100;   //y2-y: la hauteur de la plateforme
    sprPlateforme.setScale(x_lim,y_lim);
}
