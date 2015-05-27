#ifndef ENEMIGO2_H
#define ENEMIGO2_H
#include "Personaje.h"

class Enemigo2 : public Personaje
{
    public:
        float velocidad;
        void dibujar();
        void logica();
        float getX();
        float getY();
        void movedBy(float x, float y);

        Enemigo2(SDL_Renderer* renderer);
        virtual ~Enemigo2();
    protected:
    private:
};

#endif // ENEMIGO2_H
