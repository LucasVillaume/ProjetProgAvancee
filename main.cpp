#include "Cube.hpp"
#include "Sol.hpp"
#include "Plateforme.hpp"
#include <chrono>
#include <thread>
#include <vector>

int main(){
    
    sf::RenderWindow window(sf::VideoMode(1000,500),"Square's Quest");
    
    Cube cube;
    cube.cubeGentil();
    
    Sol sol(0,400,1000,500);
    std::vector<Plateforme> tab_pf;
    tab_pf.push_back(sol);
    
    
    int speed_y = 10;
    auto t1 = std::chrono::high_resolution_clock::now();
    while (window.isOpen()){
        { // sleep if less than 20 ms since last re-rendering; TODO: decouple rendering and event polling frequencies
            auto t2 = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
            if (fp_ms.count()<40) {
                std::this_thread::sleep_for(std::chrono::milliseconds(3));
                continue;
            }
            t1 = t2;
        }
        { // apply changes to the world
            if (speed_y>0 && cube.getOrdonneeCube()<400 || speed_y<0 && cube.getOrdonneeCube()>0) {
                cube.deplacerCube(0, speed_y);
            }
            if (speed_y<20) speed_y++;
        }
        window.clear();
        
        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
                window.close();
            }
            if (event.type == sf::Event::KeyPressed){
                
                switch(event.key.code){
                    
                    case(sf::Keyboard::Z): {
                        if (cube.getOrdonneeCube()>390)
                        speed_y = -30;
//                      cube.deplacerCube(0,-1);
                     } break;
                        
                    case(sf::Keyboard::Q):
                        cube.deplacerCube(-10,0);
                        break;
            
                    case(sf::Keyboard::S):
                        cube.deplacerCube(0,1);
                        break;
            
                    case(sf::Keyboard::D):
                        cube.deplacerCube(10,0);
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
                
                if (cube.dansAir()){
                    cube.chute();
                }
            }
        }

        window.draw(cube.getSprite());
        window.draw(cube.getATH().getSpriteVide());
        window.draw(cube.getATH().getSpritePleine());
        window.draw(cube.getATH().getSpriteBarreMana());
        window.draw(cube.getATH().getSpriteMana());
        window.draw(sol.getSprite());
        window.display();
    }
    
    return 0;
}
