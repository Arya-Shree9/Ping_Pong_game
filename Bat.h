#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Bat{
private:
Vector2f m_Position;
RectangleShape m_Shape;
float m_Speed=1000.0f; //speed pixel persec
bool m_MovingLeft=false;// for the movement of the bat
bool m_MovingRight=false;

public:
Bat(float startX , float startY);
FloatRect getPosition();
RectangleShape getShape();
void moveLeft();
void moveRight();
void stopleft();
void stopright();
void update(Time dt); //will be used in clock, restarting the function
};
