#ifndef ENEMIGO2_H
#define ENEMIGO2_H
#include "Personaje.h"

class Enemigo2 : public Personaje
{
    public:
        SDL_Texture *textura, *textura_bala;
        SDL_Rect rect_textura, rect_bala;
        SDL_Renderer *renderer;

        void dibujar();
        void logica();

        Enemigo2(SDL_Renderer* renderer);
        virtual ~Enemigo2();
    protected:
    private:
};

#endif // ENEMIGO2_H
