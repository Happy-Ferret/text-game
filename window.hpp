#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>
class Game
{
public:
    Game(std::string name);
    ~Game();
    void display(std::string img, SDL_Renderer** ren);
    void draw(const char * msg, int x , int y, int r, int g, int b, SDL_Renderer** ren);
    void render(SDL_Renderer** ren, bool DRAW);
    void loop();
private:
    SDL_Renderer* Mapren;
    SDL_Window* Mapwin;
    SDL_Renderer* Mainren;
    SDL_Window* Mainwin;
    std::string name;
    SDL_Texture* tex;
    bool running;
    TTF_Font * font;
};