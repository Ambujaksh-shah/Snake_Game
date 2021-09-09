#ifndef RENDERINGIMAGE_H
#define RENDERINGIMAGE_H

#include <SDL2/SDL.h>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include<iostream>
#include<string>

class ImageRendering
{
private:
	 SDL_Texture *TextureSurface = nullptr;
	 SDL_Surface *Image=nullptr;
	 SDL_Surface *screen = nullptr;
	 TTF_Font *font;
	 Uint32 time;
     int x, y;
     static int constexpr NUMMENU = 2; 
   	 const char* labels[NUMMENU] = {"Continue","Exit"};
     SDL_Surface* menus[NUMMENU];
     SDL_Rect pos[NUMMENU];
     bool selected[NUMMENU] = {0,0};
     SDL_Color color[2] = {{0xFF,0xFF,0xFF,0xFF},{0x00,0xC0,0x00,0xFF}};   
	 
	 const std::string filepath="../img/Garden.jpg";
	 const std::string fontpath="../font/freedom.ttf";
public:
	SDL_Texture *textureSurface(SDL_Renderer *rendrerSurface);
	int showmenu(SDL_Window *);
	bool LoadImage();
	bool LoadFont();
	~ImageRendering();
};






#endif