#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    VideoMode vm(960, 540); 
    RenderWindow window(vm, "Pong");
    Bat bat(960 / 2, 540 - 20);
    Ball ball(960 / 2,0);
    int score=0;
    int lifes=3;
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    Text hud;
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setPosition(20,20);
    
    Clock clock;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            bat.moveLeft();
        }else{
        	bat.stopleft();
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            bat.moveRight();
        }else{
        	bat.stopright();
        }
        //update section
        Time dt = clock.restart();
        bat.update(dt);
        ball.update(dt);
        std::stringstream ss;
        ss<<"Score: "<<score<<"   Lives:"<<lifes;
        hud.setString(ss.str());
        if(ball.getPosition().left<0 || ball.getPosition().left + ball.getPosition().width>window.getSize().x){
        	ball.reboundSides();
        }
        if(ball.getPosition().top<0){
        	ball.reboundBatOrTop();
        	score++;
        }
        if(ball.getPosition().intersects(bat.getPosition())){
        	ball.reboundBatOrTop();
        
        }
        if(ball.getPosition().top > window.getSize().y){
        	ball.reboundBottom();
        	if(lifes>0){
        	
        	lifes--;
        	
        	if(lifes==0){
        		std::stringstream ss;
        		ss<<"GAME OVER !!!";
        		hud.setString(ss.str());
        	}
        	
        	}
        	
        	
        }

        window.clear();
        window.draw(hud);
         window.draw(ball.getShape());
        window.draw(bat.getShape());
        window.display();
    }
    return 0;
}
