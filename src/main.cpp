#include <Curves.h>
#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 1000;
const int HEIGHT = 800;
int main()
{
    std::vector<Point2D> points = {{1, 1}, {1.5, 1.5}, {2, 1}, {2, 2}, {1, 2.5}};
    BezierCurve2D c(points);
    std::vector<double> t;
    for (double i = 0.0; i < 1.001; i += 0.01) t.push_back(i);
    std::vector<Point2D> curvePoints = c.renderCurve(t);
    //for (int i = 0; i < t.size(); i++) std::cout << curvePoints[i] << std::endl;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("Curves", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );
    SDL_Renderer* renderer = SDL_CreateRenderer( window, -1, 0 );

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 1; i < curvePoints.size(); i++) 
        SDL_RenderDrawLine(renderer, curvePoints[i - 1].x * 100, curvePoints[i - 1].y * 100, curvePoints[i].x * 100, curvePoints[i].y * 100);
    
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int i = 0; i < points.size(); i++)
        SDL_RenderDrawPoint(renderer, points[i].x * 100, points[i].y * 100);
    SDL_RenderPresent(renderer);
    while ( true )
    {
        SDL_Event windowEvent;
        SDL_PollEvent( &windowEvent );

        if ( SDL_QUIT == windowEvent.type )
        {
            break;
        }

        
    }
    SDL_DestroyWindow ( window );
    SDL_Quit();

    return EXIT_SUCCESS;
}