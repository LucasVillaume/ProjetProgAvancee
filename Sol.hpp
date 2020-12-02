#ifndef DEF_SOL
#define DEF_SOL

#include <SFML/Graphics.hpp>
#include "Plateforme.hpp"
#include "Point.hpp"

class Sol: public Plateforme{
	
	public:
	Sol(Point deb, Point fin);
	Sol(int x, int y, int x2, int y2);
		
};
#endif
