#include "Cube.hpp"

int main(){
    
    sf::RenderWindow window(sf::VideoMode(1000,500),"Cube's Quest");
    
    Cube cube;
    cube.cubeGentil();
    
    while (window.isOpen()){
        window.clear();
        
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
                window.close();
            }
            if (event.type == sf::Event::KeyPressed){
                
                switch(event.key.code){
                    
                    case(sf::Keyboard::Z):
                        cube.deplacerCube(0,-6);
                        break;
                        
                    case(sf::Keyboard::Q):
                        cube.deplacerCube(-1,0);
                        break;
            
                    case(sf::Keyboard::S):
                        cube.deplacerCube(0,1);
                        break;
            
                    case(sf::Keyboard::D):
                        cube.deplacerCube(1,0);
                        break;
                        
                    case(sf::Keyboard::W):
                        cube.prendreDegats(1);
                        break;
                        
                    case(sf::Keyboard::X):
                        cube.gagnerVie(1);
                        break;
                    
                    case(sf::Keyboard::V):
                        cube.augmenterVieMax(1);
                        break;
                        
                    case(sf::Keyboard::C):
                        cube.diminuerVieMax(1);
                        break;
                        
                    case(sf::Keyboard::P):
                        cube.regenMana(1);
                        break;
                    
                    case(sf::Keyboard::M):
                        cube.depenserMana(1);
                        break;
                        
                    default:
                        break;
                }
                
                if (cube.dansAir() == true){
                    cube.chute();
                }
            }  
        }

        window.draw(cube.getSprite());
        window.draw(cube.getATH().getSpriteVide());
        window.draw(cube.getATH().getSpritePleine());
        window.draw(cube.getATH().getSpriteBarreMana());
        window.draw(cube.getATH().getSpriteMana());
        window.display();
    }
    
    return 0;
}
