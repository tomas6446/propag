#include <stdio.h>
#include <time.h>

#include "Constants.h"
#include "Objects.h"
#include "Score.h"
#include "UI.h"


SDL_Texture* loadTexture(SDL_Renderer* Renderer, char* path)
{
    SDL_Texture* newTexture = NULL; // The final texture
    SDL_Surface* loadedSurface = IMG_Load(path); // Load image at specified path
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(Renderer, loadedSurface); // Create texture from surface pixels
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface); // Get rid of old loaded surface
    }

    return newTexture;
}

void updateEverything(SDL_Renderer* Renderer, struct Object* P1, struct Object* P2, struct Object* Ball, struct Score* Score1, struct Score* Score2, struct UI* line)
{
    updateUI(Renderer, line);
    updateScoreBoard(Renderer, Score1, P1->win); // update score1
    updateScoreBoard(Renderer, Score2, P2->win); // update score2
    updateBall(Renderer, Ball); // update ball
    updatePlayer(Renderer, P1->Rect); // update player1 
    updatePlayer(Renderer, P2->Rect); // update player2
}

void clearWindow(SDL_Renderer* Renderer)
{
    SDL_SetRenderDrawColor(Renderer, RED_RGB_COLOR);
    SDL_RenderClear(Renderer);
}

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING); // Initialize SDL
    TTF_Init(); // Initialize TTF

    // Susikuriu Window ir Renderer(rodyti grafika)
    SDL_Window* Window = SDL_CreateWindow("Pong", WINDOW_POS_X, WINDOW_POS_Y, WINDOW_WIDTH, WINDOW_HEIGHT, 0); // The window we'll be rendering to
    SDL_Renderer* Renderer = SDL_CreateRenderer(Window, 0, SDL_HINT_RENDER_VSYNC); // The window renderer
    SDL_bool Stop = SDL_FALSE;

    // Susikuriu objektus, Player1, Player2, ir Ball (kiekvienas turi savo x, y pozicija, savo width ir height). Taipat turi savo texture. P1 ir P2, texture neturi
    struct Object P1, P2, Ball; // laikyti x, y, width, height, texture, texture name, win count ir t.t
    struct Object* p_P1 = &P1, *p_P2 = &P2, *p_Ball = &Ball;  // pointeris i struktura P1, P2, Ball
    P1 = createPlayer(Renderer, PLAYER1_POS_X, PLAYER1_POS_Y, PLAYER_WIDTH, PLAYER_HEIGHT, ""); // posX, posY, width, height
    P2 = createPlayer(Renderer, PLAYER2_POS_X, PLAYER2_POS_Y, PLAYER_WIDTH, PLAYER_HEIGHT, "");
    Ball = createPlayer(Renderer, BALL_POS_X, BALL_POS_Y, BALL_RADIUS, BALL_RADIUS, "circle.png");

    // Susikuriu objektus, kurie rodys score
    struct Score Score1, Score2, Timer; // stroes string win count, texture, texture color, font, positions
    struct Score *p_Score1 = &Score1, *p_Score2 = &Score2, *p_timer = &Timer; // pointer
    Score1 = createScoreBoard(Renderer, SCORE1_POS_X, SCORE1_POS_Y, SCORE_WIDTH, SCORE_HEIGHT, "0"); // posX, posY, width, height, "text"
    Score2 = createScoreBoard(Renderer, SCORE2_POS_X, SCORE1_POS_Y, SCORE_WIDTH, SCORE_HEIGHT, "0");
    Timer = createScoreBoard(Renderer, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 150, 50, 300, "3");

    // Susikuriu UI
    struct UI Line;
    struct UI *p_line = &Line;
    Line = createUI(Renderer, LINE_POS_X, LINE_POS_Y, LINE_WIDTH, LINE_HEIGHT, "line.png");

    // Gaunu rezultatus is praejusio zaidimo
    P1.win = getScore("Player1.txt"); // get previous results
    P2.win = getScore("Player2.txt");

    int keysHeld[323] = { 0 }; // index represent which key id was pressed at the moment
    int timer = 0;

    while (!Stop) // Tol, kol nepaspaudzia 'X' (neiseina is zaidimo)
    {
        SDL_Event event;

        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                printf("Score [%d ; %d]\n", P1.win, P2.win);
                saveScore(P1.win, "Player1.txt"); // save results
                saveScore(P2.win, "Player2.txt"); 
                Stop = SDL_TRUE;
            }
            if (event.type == SDL_KEYDOWN)
            {
                keysHeld[event.key.keysym.sym] = 1;
            }
            if (event.type == SDL_KEYUP)
            {
                keysHeld[event.key.keysym.sym] = 0;
            }
        }
        

        movePlayer(p_P1, keysHeld, W, S); // move player1, based on direction
        movePlayer(p_P2, keysHeld, U, J); // move player2
        moveBall(p_Ball, p_P1, p_P2, &timer); // move ball, change direction on collision
        // Grafika
        clearWindow(Renderer); // clear window

        // Kad nebutu memory leak
        destroyBall(p_Ball); // destroy ball texture
        destroyScore(p_Score1); // destroy score of player1 texture
        destroyScore(p_Score2); // destroy score of player2 texture
        destroyUI(p_line);
        
        // Update objects
        updateEverything(Renderer, p_P1, p_P2, p_Ball, p_Score1, p_Score2, p_line);

        if (timer == 1) { // timer
            int timer_count = 3;
            while (timer_count != 0) {
                clearWindow(Renderer);

                updateEverything(Renderer, p_P1, p_P2, p_Ball, p_Score1, p_Score2, p_line);

                destroyScore(p_timer); // destroy timer texture
                updateScoreBoard(Renderer, p_timer, timer_count);
                SDL_RenderPresent(Renderer);
                SDL_Delay(500);

                timer_count--;
            }
            timer = 0;
        }

        SDL_RenderPresent(Renderer);    
    }

    // Programos pabaigoje daroma free texture memory
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    
    destroyBall(p_Ball);
    destroyScore(p_Score1);
    destroyScore(p_Score2);

    SDL_Quit();

    return 0;
}