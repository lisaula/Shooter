#ifndef PERSONAJE_H
#define PERSONAJE_H
#include<list>
#include<vector>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

using namespace std;

class Personaje
{
    public:
        vector<SDL_Rect>rect_balas;
        list<Personaje*>*personajes;
        float velocidad;
        float velocidad_bala;
        SDL_Texture *textura, *textura_bala;
        SDL_Rect rect_textura, rect_bala;
        SDL_Renderer *renderer;
        int frame;
        float getX();
        float getY();
        void movedBy(float x, float y);
        Personaje();
        virtual bool fueTocado()=0;

        virtual void logica()=0;
        virtual void dibujar()=0;
        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
