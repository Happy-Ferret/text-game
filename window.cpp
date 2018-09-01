#include "window.hpp"
#include "event.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

std::map<std::string, std::string> locations;
std::string str;
std::string img = "main.png";
int texty = 403;
const char * getInput();
Game::Game(std::string Name)
{
    locations["main"] = "main.png";
    locations["house"]="house.png";
    locations["city"]="city.png";
    locations["alley"]="alley.png";
    locations["ex"]="house.png";
    name = Name;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(200,500,0,&Mapwin,&Mapren);
    SDL_CreateWindowAndRenderer(500,500,0,&Mainwin,&Mainren);
    SDL_SetWindowTitle(Mainwin,name.c_str());
    SDL_SetWindowTitle(Mapwin,"map");
    SDL_SetWindowPosition(Mainwin,0, 50);
    SDL_SetWindowPosition(Mapwin,500, 50);
    SDL_RaiseWindow(Mapwin);
    SDL_RaiseWindow(Mainwin);
    TTF_Init();
    font = TTF_OpenFont("/mnt/c/Users/Marie/SDLGAME/Sans.ttf",15);
    loop();
}
int start = 1;;
void Game::loop()
{
  running = true;   
  for(int i = 0; i< 150;i++){
    int iter = 0;
    std::string ret = getInput();
    if(ret=="\xF1"){
      std::cerr << ret << std::endl;
      this->~Game();
    }
    render(&Mapren,false);
    std::cout << str.size() << "\t" << str << std::endl;
    render(&Mainren,true);
    start = 0;
  }
  std::cout << str << std::endl;
}
const char * getInput()
{
  SDL_Event e;
  while(SDL_PollEvent(&e))
  {
    if(e.type==SDL_KEYDOWN)
    {
      switch(e.key.keysym.sym)
      {
        case SDLK_a:
        str+="a";
        img = "ex1.png";
        break;
        case SDLK_b:
        img = "ex.png";
        str+="b";
        break;
        case SDLK_c:
        str+="c";
        break;
        case SDLK_d:
        str+="d";
        break;
        case SDLK_e:
        str+="e";
        break;
        case SDLK_f:
        str+="f";
        break;
        case SDLK_g:
        str+="g";
        break;
        case SDLK_h:
        str+="h";
        break;
        case SDLK_i:
        str+="i";
        break;
        case SDLK_j:
        str+="j";
        break;
        case SDLK_k:
        str+="k";
        break;
        case SDLK_l:
        str+="l";
        break;
        case SDLK_m:
        str+="m";
        break;
        case SDLK_n:
        str+="n";
        break;
        case SDLK_o:
        str+="o";
        break;
        case SDLK_p:
        str+="p";
        break;
        case SDLK_q:
        str+="q";
        break;
        case SDLK_r:
        str+="r";
        break;
        case SDLK_s:
        str+="s";
        break;
        case SDLK_t:
        str+="t";
        break;
        case SDLK_u:
        str+="u";
        break;
        case SDLK_v:
        str+="v";
        break;
        case SDLK_w:
        str+="w";
        break;
        case SDLK_x:
        str+="x";
        break;
        case SDLK_y:
        str+="y";
        break;
        case SDLK_z:
        str+="z";
        break;
        case SDLK_0:
        str+="0";
        break;
        case SDLK_1:
        str+="1";
        break;
        case SDLK_2:
        str+="2";
        break;
        case SDLK_3:
        str+="3";
        break;
        case SDLK_4:
        str+="4";
        break;
        case SDLK_5:
        str+="5";
        break;
        case SDLK_6:
        str+="6";
        break;
        case SDLK_7:
        str+="7";
        break;
        case SDLK_8:
        str+="8";
        break;
        case SDLK_9:
        str+="9";
        break;
        case SDLK_SPACE:
        str+=" ";
        break;
        case SDLK_KP_ENTER:
        str.append("\n");
        return str.c_str();
        case SDLK_BACKSPACE:
        if(str.size()!=0)
          str.pop_back();
        return str.c_str();
        case SDLK_LALT:
        img = locations["main"];
        return "";
        default:
        return "";
      }
    }
    if(e.type == SDL_QUIT)
    {
      std::cout << "Quiting "<< std::endl;
      SDL_Quit();
      return("/xF1");
    }
    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
      int mouseX,mouseY;
      SDL_GetMouseState(&mouseX, &mouseY);
      if(houseButton)
        img = locations["house"];
      if(exButton){
        img = locations["ex"];
        std::cout << "EX" << std::endl;
      }
      if(cityButton)
        img = locations["city"];
      if(alleyButton)
        img = locations["alley"];
      
      std::cerr << "=============================" << std::endl;
      std::cerr << "x = " << mouseX << " y = " << mouseY << "\timg:"<< img << std::endl;
      std::cerr << "=============================" << std::endl;
      return "";
    }
  }
  return str.c_str();
}
Game::~Game()
{
  TTF_CloseFont(font);
  SDL_DestroyRenderer(Mapren);
  SDL_DestroyWindow(Mapwin);
  SDL_DestroyRenderer(Mainren);
  SDL_DestroyWindow(Mainwin);
}
void Game::draw(const char * msg, int x , int y, int r, int g, int b, SDL_Renderer** ren)
{
  SDL_Color color;
  color.r=r;
  color.g=g;
  color.b=b;
  color.a=255;
  SDL_Rect rect;
  SDL_Surface * surf = TTF_RenderText_Solid(font, msg, color);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(*ren, surf);
  rect.x=x;
  rect.y=y;
  rect.w = surf->w;
  rect.h = surf->h;
  SDL_RenderCopy(*ren, tex, NULL, &rect);
  SDL_FreeSurface(surf);
  SDL_DestroyTexture(tex);
}
void Game::render(SDL_Renderer** ren,bool DRAW)
{
  SDL_SetRenderDrawColor(*ren, 00, 00, 00, 255);
  SDL_Rect rect;
  if(ren == &Mainren)
  {
    rect.x=0;
    rect.y=0;
    rect.w=500;
    rect.h=500;
  }
  else if(ren == &Mapren)
  {
    rect.x=0;
    rect.y=0;
    rect.w=200;
    rect.h=500;
  }
  SDL_RenderFillRect(*ren, &rect);
  if(str.size() == 6 && start == 1)
  {
    str.erase(0);
  }
  start = 0;
  display(img,&Mainren);
  display("map.png",&Mapren);
  if(DRAW && str.size() > 0)
  {
    draw(str.c_str(), 0, texty, 255, 0, 0, ren);
  }
  SDL_RenderPresent(*ren);
}
void Game::display(std::string img, SDL_Renderer**ren)
{
  SDL_Surface* surf = IMG_Load(img.c_str());
  tex = SDL_CreateTextureFromSurface(*ren,surf);
  SDL_FreeSurface(surf);
  SDL_Rect dest;
  SDL_Rect src;
  if(ren == &Mainren)
  {
  src.x = 0;
  src.y = 0;
  src.w = 500;
  src.h = 500;
  dest.x = 0;
  dest.y = 0;
  dest.w = 500;
  dest.h = 500;
  }
  else if(ren == &Mapren)
  {
  src.x = 0;
  src.y = 0;
  src.w = 200;
  src.h = 500;
  dest.x = 0;
  dest.y = 0;
  dest.w = 200;
  dest.h = 500;
  }
  SDL_RenderCopyEx(*ren, tex, &src , &dest, 0, NULL, SDL_FLIP_NONE); 
}