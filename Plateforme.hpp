#ifndef DEF_PLATEFORME
#define DEF_PLATEFORME

#include <SFML/Graphics.hpp>
#include "Point.hpp"

class Plateforme{

	public:
	Plateforme(Point deb, Point fin);
	Plateforme(int x, int y, int x2, int y2);
	void casser();
	void reparer();
	//Get/Set
	sf::Sprite getSprite();
	
	protected:
	Point hautGauche;
	Point basDroite;
	sf::Texture texturePlateforme;
	sf::Sprite sprPlateforme;

};

#endif
