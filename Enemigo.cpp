#include "Enemigo.h"

Enemigo::Enemigo(SDL_Renderer* renderer,list<Personaje*>*personajes)
{
    this->personajes = personajes;
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
    velocidad_bala =1;
    frame=0;
}

void Enemigo::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
    for(int i=0;i<rect_balas.size();i++)
        SDL_RenderCopy(renderer, textura_bala, NULL, &rect_balas[i]);
}
void Enemigo::logica()
{
    puedo=false;
   //movement logic

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
        puedo=true;
   }
   for(int i=0;i<rect_balas.size();i++){
   if(rect_balas[i].x<=640)
        rect_balas[i].x+=velocidad_bala;
    if(rect_balas[i].x>=609){
        rect_balas.erase(rect_balas.begin()+i);
    }
   }

    if(puedo)
   if(frame%150==0){
        SDL_Rect temp;
        temp.x=rect_textura.x+(rect_textura.w/2);
        temp.y=rect_textura.y+(rect_textura.h/2);
        temp.w=rect_bala.w;
        temp.h=rect_bala.h;
        rect_balas.push_back(temp);
   }

    frame++;
}


bool Enemigo::fueTocado(){
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
        }
        if(tocado)
        return true;
        else
        return false;
}
Enemigo::~Enemigo()
{
    //dtor
}
