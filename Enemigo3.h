#ifndef ENEMIGO3_H
#define ENEMIGO3_H
#include "Personaje.h"

class Enemigo3: public Personaje
{
    public:
        float width, height;
        void dibujar();
        void logica();
        bool fueTocado();
        bool puedo;
        Enemigo3(SDL_Renderer* renderer,list<Personaje*>*personajes);
        virtual ~Enemigo3();
    protected:
    private:
};

#endif // ENEMIGO3_H
