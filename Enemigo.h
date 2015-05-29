#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Jugador.h"
#include "Personaje.h"

class Enemigo : public Personaje
{
    public:
        bool puedo;
        void dibujar();
        void logica();
        bool fueTocado();
        Enemigo(SDL_Renderer* renderer, list<Personaje*>*personajes);
        virtual ~Enemigo();
    protected:
    private:
};

#endif // ENEMIGO_H
