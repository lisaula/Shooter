#include "Enemigo2.h"

Enemigo2::Enemigo2(SDL_Renderer *renderer,list<Personaje*>*personajes)
{
    this->personajes = personajes;
    this->renderer = renderer;
    int w,h;
    textura = IMG_LoadTexture(renderer, "enemigo2.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 581;
    rect_textura.y = 0;
    rect_textura.w = w;
    rect_textura.h = h;

    textura_bala = IMG_LoadTexture(renderer, "balaV.png");
    SDL_QueryTexture(textura_bala, NULL, NULL, &w, &h);
    rect_bala.x = 100;
    rect_bala.y = 200;
    rect_bala.w = w;
    rect_bala.h = h;
    velocidad =1;
    velocidad_bala =10;
    frame =1;
}

void Enemigo2:: dibujar(){
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
    for(int i=0;i<rect_balas.size();i++)
        SDL_RenderCopy(renderer, textura_bala, NULL, &rect_balas[i]);
}

void Enemigo2:: logica(){
    for(int i=0;i<rect_balas.size();i++)
        rect_balas[i].y+=velocidad_bala;

    if(rect_textura.x >=581){
        velocidad *= -1;
    }
    if(getX()<=0){
        velocidad *=-1;
    }
    movedBy(velocidad,0);

    if(frame%100==0){
        SDL_Rect temp;
        temp.x=rect_textura.x+(rect_textura.w/2);
        temp.y=rect_textura.y+(rect_textura.h/2);
        temp.w=rect_bala.w;
        temp.h=rect_bala.h;
        rect_balas.push_back(temp);
   }

    frame++;
}

bool Enemigo2::fueTocado()
{
list<Personaje*>::iterator i=personajes->begin();
    bool tocado = false;
   for(int j=0;j<rect_balas.size();j++)
        {
            SDL_Rect rect1 = rect_balas[j];
            SDL_Rect rect2 = (*i)->rect_textura;
            if((rect1.x+rect1.w<rect2.x)==false//Muy a la izq
                && (rect1.x>rect2.x+rect2.w)==false//Muy a la der
                && (rect1.y+rect1.h<rect2.y)==false//Muy arriba
                && (rect1.y>rect2.y+rect2.h)==false//Muy abajo
               )
            {

                rect_balas.erase(rect_balas.begin()+j);
                tocado = true;
                break;
            }
            if(rect_balas[j].y>=449){
            rect_balas.erase(rect_balas.begin()+j);
            }
        }
        if(tocado)
        return true;
        else
        return false;
}

Enemigo2::~Enemigo2()
{
    //dtor
}
