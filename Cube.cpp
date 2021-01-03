#include "Cube.hpp"

using namespace std;

Cube::Cube(): vie(3), vieMax(3), mana(100), position(Point(0,0)), nom("MadDummy"), vitesse(10), gravite(15), ath(ATH()){
    
    if (!textureCube.loadFromFile("../ressources/TextureCube/Cube.png")){
    }
    
    textureCube.setSmooth(true);
    textureCube.setRepeated(false);
    sprCube.setTexture(textureCube);
    sprCube.setOrigin(0,300);
    sprCube.setScale(0.5,0.5);
    sprCube.setPosition(0.f,300.f);
    
}

void Cube::gagnerVie(int v){
    vie += v;
    if (vie > vieMax){
        vie = vieMax;
    }
    ath.modifVie(vie);
}

void Cube::prendreDegats(int d){
    vie -= d;
    if (vie < 0){
        vie = 0;
    }
    ath.modifVie(vie);
}

void Cube::augmenterVieMax(int v){
    vieMax += v;
    if (vieMax > 6){
        vieMax = 6;
    }
    ath.modifVieMax(vieMax);
}

void Cube::diminuerVieMax(int v){
    vieMax -= v;
    if (vieMax < 1){
        vieMax = 1;
    }
    gagnerVie(0);   //gagnerVie(0) permet de mettre la vie à jour grace à "if" présent dans la fonction
    ath.modifVieMax(vieMax);
}

void Cube::regenMana(int m){
    mana += m;
    if (mana > 100){
        mana = 100;
    }
    ath.modifMana(mana);
}

void Cube::depenserMana(int m){
    mana -= m;
    if (mana < 0){
        mana = 0;
    }
    ath.modifMana(mana);
}

bool Cube::estVivant() const{
    bool v = true;
    if (vie > 0){
        v = false;
    }
    return v;
}

void Cube::deplacerCube(int x, int y){
    sprCube.move(x,y);
    position.deplacer(x,y);
}

void Cube::chute(){
    while (dansAir()){
        position.deplacer(0,gravite);
    }
    sprCube.setPosition(sf::Vector2f(getAbscisseCube(),getOrdonneeCube()));
    
    if (getOrdonneeCube() > 300){
        sprCube.setPosition(getAbscisseCube(),300);
    }
}

bool Cube::dansAir() const{
    bool air = true;
    
    if (sf::Vector2f(getAbscisseCube(),300.f) == sprCube.getPosition()){
        air = false;
    }
    
    if (getOrdonneeCube() > 300){
        air = false;
    }
    
    return air;
}

void Cube::cubeGentil(){
    sprCube.setTextureRect(sf::IntRect(0,0,300,300));
}

void Cube::cubeColere(){
    sprCube.setTextureRect(sf::IntRect(301,301,300,300));
}



//[*]-------------------- Get/Set methode--------------------[*]



int Cube::getVie() const{
    return vie;
}

int Cube::getVieMax() const{
    return vieMax;
}

int Cube::getAbscisseCube() const{
    return position.getAbscisse();
}

int Cube::getOrdonneeCube() const{
    return position.getOrdonnee();
}

void Cube::setAbscisseCube(int x){
    position.setAbscisse(x);
}

void Cube::setOrdonneeCube(int y){
    position.setOrdonnee(y);
}

void Cube::setNom(string nouvNom){
    nom = nouvNom;
}

string Cube::getNom() const{
    return nom;                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
}

int Cube::getVitesse() const{
    return vitesse;
}

void Cube::setVitesse(int vit){
    vitesse = vit;
}

int Cube::getGravite() const{
    return gravite;
}

void Cube::setGravite(int g){
    gravite = g;
}

void Cube::setTexture(sf::Image image){
    textureCube.update(image);
}

sf::Texture Cube::getTexture(){
    return textureCube;
}

sf::Sprite Cube::getSprite(){
    return sprCube;
}

ATH Cube::getATH() const{
    return ath;
}
















