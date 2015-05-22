#include "Enemigo3.h"

Enemigo3::Enemigo3(SDL_Renderer* renderer)
{
   this->renderer = renderer;
    int w,h;
    textura = IMG_LoadTexture(renderer, "enemigo3.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 528;
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

void Enemigo3:: dibujar(){
   SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
}

void Enemigo3 :: logica(){
    rect_textura.y+=1;
    if(rect_textura.y > 359){
        rect_textura.y =0;
    }
}

Enemigo3::~Enemigo3()
{
    //dtor
}
