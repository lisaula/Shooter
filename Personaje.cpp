#include "Personaje.h"

Personaje::Personaje()
{
    //ctor
}
float Personaje :: getX(){
    return rect_textura.x;
}
float Personaje :: getY(){
    return rect_textura.y;
}
void Personaje :: movedBy(float x, float y){
    rect_textura.x +=x;
    rect_textura.y +=y;
}
Personaje::~Personaje()
{
    //dtor
}
