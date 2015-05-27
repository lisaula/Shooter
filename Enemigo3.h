#ifndef ENEMIGO3_H
#define ENEMIGO3_H
#include "Personaje.h"

class Enemigo3: public Personaje
{
    public:

        void dibujar();
        void logica();

        Enemigo3(SDL_Renderer* renderer);
        virtual ~Enemigo3();
    protected:
    private:
};

#endif // ENEMIGO3_H
