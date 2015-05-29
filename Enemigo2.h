#ifndef ENEMIGO2_H
#define ENEMIGO2_H
#include "Personaje.h"

class Enemigo2 : public Personaje
{
    public:
        void dibujar();
        void logica();
        bool fueTocado();
        Enemigo2(SDL_Renderer* renderer,list<Personaje*>*personajes);
        virtual ~Enemigo2();
    protected:
    private:
};

#endif // ENEMIGO2_H
