#include "Enemigo3.h"

Enemigo3::Enemigo3(SDL_Renderer* renderer,list<Personaje*>*personajes)
{
    this->personajes = personajes;
    this->renderer = renderer;
    int w,h;
    textura = IMG_LoadTexture(renderer, "enemigo3.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 528;
    rect_textura.y = 0;
    rect_textura.w = w;
    rect_textura.h = h;

    textura_bala = IMG_LoadTexture(renderer, "SuperBala.png");
    SDL_QueryTexture(textura_bala, NULL, NULL, &w, &h);
    rect_bala.x = 100;
    rect_bala.y = 200;
    rect_bala.w = 0.01;
    rect_bala.h = 0.01;
    width=w;
    height=h;
    frame =1;
    velocidad=1;
    velocidad_bala=1;
    puedo = false;
}

void Enemigo3:: dibujar(){
   SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
   for(int i=0;i<rect_balas.size();i++)
        SDL_RenderCopy(renderer, textura_bala, NULL, &rect_balas[i]);
}
bool Enemigo3::fueTocado()
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
            if(rect_balas[j].x<=0){
            rect_balas.erase(rect_balas.begin()+j);
            }
        }
        if(tocado)
        return true;
        else
        return false;
}

void Enemigo3 :: logica(){
    puedo=false;
    rect_textura.y+=velocidad;
    if(rect_textura.y > 359){
        rect_textura.y =0;
    }

    if(frame%100==0){
        SDL_Rect temp;
        temp.x=rect_textura.x+(rect_textura.w/2);
        temp.y=rect_textura.y+(rect_textura.h/2);
        temp.w=0;
        temp.h=0;
        rect_balas.push_back(temp);
   }

    for(int i=0;i<rect_balas.size();i++){
        if(rect_balas[i].w<width && rect_balas[i].h<height){
            rect_balas[i].w+=1;
            rect_balas[i].h+=1;
        }else
            puedo = true;
    }

    for(int i=0;i<rect_balas.size();i++){
        if(puedo){
            rect_balas[i].x-=velocidad_bala;
        }
    }

   frame++;
}

Enemigo3::~Enemigo3()
{
    //dtor
}
