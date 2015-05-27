#include "Enemigo.h"

Enemigo::Enemigo(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    int w,h;
    textura = IMG_LoadTexture(renderer, "enemigo.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 0;
    rect_textura.y = 0;
    rect_textura.w = w;
    rect_textura.h = h;

    textura_bala = IMG_LoadTexture(renderer, "bala.png");
    SDL_QueryTexture(textura_bala, NULL, NULL, &w, &h);
    rect_bala.x = 100;
    rect_bala.y = 200;
    rect_bala.w = w;
    rect_bala.h = h;
}

void Enemigo::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
}
void Enemigo::logica()
{
   if(getX() >=0 && getX() <=518 && rect_textura.y ==0){
        rect_textura.x +=2;
   }
   if(getX()==518 && rect_textura.y>=0 && rect_textura.y <=370){
    rect_textura.y +=2;
   }
   if(getY() ==370 && getX()<=518 && getX()>=0){
    movedBy(-2,0);
   }
   if(getX()==0 && getY()<=370 && getY()>=0){
    movedBy(0,-2);
   }

}

Enemigo::~Enemigo()
{
    //dtor
}
