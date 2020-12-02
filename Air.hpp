#ifndef DEF_AIR
#define DEF_AIR

#include <SFML/Graphics.hpp>
#include "Plateforme.hpp"
#include "Point.hpp"

class Air: public Plateforme{

	public:
	Air(Point deb, Point fin);
	Air(int x, int y, int x2, int y2);
	
};
#endif
