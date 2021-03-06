
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<list>
#include "Jugador.h"
#include "Enemigo.h"
#include "Enemigo2.h"
#include "Enemigo3.h"
#include<SDL2/SDL_mixer.h>

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background, *pausa;
SDL_Rect rect_background, rect_pausa;
Mix_Music *mscMusic = NULL;
bool estaPausado;

void juego()
{
    //init music
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,2048) <0)
    {
        printf("SDL_MIXER error: %s\n", SDL_GetError());
    }

        mscMusic = Mix_LoadMUS("Orquesta_Arrecife_-_Arabesco.mp3");
        if(mscMusic ==NULL){
            printf("Couldn't open the .mp3: %s\n", Mix_GetError());
        }

    //Init textures
    int w=0,h=0;


    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

    unsigned int frame_anterior = SDL_GetTicks();

    list<Personaje*>personajes;
    personajes.push_back(new Jugador(renderer,&personajes));
    personajes.push_back(new Enemigo(renderer,&personajes));
    personajes.push_back(new Enemigo2(renderer,&personajes));
    personajes.push_back(new Enemigo3(renderer,&personajes));

    int w1=0,h1=0;
    pausa = IMG_LoadTexture(renderer,"pausado.png");
    SDL_QueryTexture(pausa, NULL, NULL, &w1, &h1);
    rect_pausa.x = 0;
    rect_pausa.y = 0;
    rect_pausa.w = w1;
    rect_pausa.h = h1;

    int frame=0;

    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_ESCAPE)
                {
                    estaPausado = true;
                }
                if(Event.key.keysym.sym == SDLK_RETURN){
                    estaPausado=false;
                }
            }
        }
        if(Mix_PlayingMusic()==0){
            Mix_PlayMusic(mscMusic, -1);
        }

        if(!estaPausado){
        for(list<Personaje*>::iterator i=personajes.begin();
            i!=personajes.end();
            i++)
            (*i)->logica();
        }
        SDL_RenderCopy(renderer, background, NULL, &rect_background);

        for(list<Personaje*>::iterator i=personajes.begin();
            i!=personajes.end();
            i++)
            (*i)->dibujar();

        for(list<Personaje*>::iterator i=personajes.begin();
            i!=personajes.end();
            i++){
            if((*i)->fueTocado()){
                return;
            }
        }

        if(estaPausado){
            SDL_RenderCopy(renderer, pausa, NULL, &rect_pausa);
        }

        if((SDL_GetTicks()-frame_anterior)<17)
            SDL_Delay(17-(SDL_GetTicks()-frame_anterior));
        frame_anterior=SDL_GetTicks();

        SDL_RenderPresent(renderer);
        frame++;
    }
    Mix_FreeMusic(mscMusic);
    mscMusic = NULL;
    Mix_Quit();
}

void menu()
{
int w,h;
    SDL_Texture* background_menu = IMG_LoadTexture(renderer,"menu.png");
    SDL_QueryTexture(background_menu, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_RETURN)
                {
                    juego();
                }

            }
        }
        SDL_RenderCopy(renderer, background_menu, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }
}

int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 640/*WIDTH*/, 480/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    menu();

	return 0;
}
