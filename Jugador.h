#ifndef JUGADOR_H
#define JUGADOR_H
#include "Personaje.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;
class Jugador : public Personaje
{
    public:
        void dibujar();
        void logica();
        bool fueTocado();
        Jugador(SDL_Renderer *renderer,list<Personaje*>*personajes);
        virtual ~Jugador();
    protected:
    private:
};

#endif // JUGADOR_H
