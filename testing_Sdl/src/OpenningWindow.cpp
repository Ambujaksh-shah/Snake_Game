#include<SDL2/SDL.h>
#include<iostream>

#define screeWidth 480
#define screenHeight 640


SDL_Window * window=nullptr;
SDL_Surface *screenSurface = nullptr;
SDL_Surface *imgSurface = nullptr;


bool Init()
{
  bool success = true;

  if( SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cout<<"SDL could not initialize"<<SDL_GetError()<<std::endl;
    success=false;
  }
  else
  {
    window = SDL_CreateWindow("SDL Hello", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,screeWidth, screenHeight, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
      std::cout<<"Error creating Window"<<SDL_GetError()<<std::endl;
      success = false;
    }
    else
    {
      screenSurface = SDL_GetWindowSurface(window);

    }

  }

  return  success;
}

bool LoadMedia()
{
  bool success = true;

  imgSurface = SDL_LoadBMP("../test.bmp");

  if(imgSurface == NULL)
  {
    std::cout<<"Unable to load "<<SDL_GetError()<<std::endl;
    success = false;
  }

  return success;

}

void close()
{
  SDL_FreeSurface(imgSurface);
  imgSurface = NULL;

  SDL_DestroyWindow(window);
  window=NULL;
  SDL_Quit();

}

int main(int argc, char **argv)
{
  // SDL_Init(SDL_INIT_EVERYTHING);
  // SDL_Quit();

  // SDL_Window *window = nullptr;
  // SDL_Surface *window_surface = nullptr;
  // SDL_Surface *image_surface = nullptr;

  // if(SDL_Init(SDL_INIT_VIDEO) < 0 )
  //   std::cout<<"Vedio Intialization Error"<<SDL_GetError() <<std::endl;
  // else
  //   window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640, 480,SDL_WINDOW_SHOWN);
  //   if(window == NULL)
  //     std::cout<<"Window creation error"<<SDL_GetError() << std::endl;

  //   else{
  //     window_surface = SDL_GetWindowSurface(window);
  //     image_surface = SDL_LoadBMP("../test.bmp");
  //     if( image_surface == NULL)
  //     {
  //       std::cout<<"Image surface Error"<<SDL_GetError()<<std::endl;
  //     }
  //     else{
  //         SDL_BlitSurface(image_surface, NULL, window_surface, NULL);
  //         SDL_UpdateWindowSurface(window);
  //         SDL_Delay(2000);
  //     }
      
  //   }

  // SDL_DestroyWindow(window);
  // SDL_Quit();
  
  if( !Init() )
  {
    std::cout<<"Failed to initiallize\n";
  }
  else
  {
    if(!LoadMedia() )
    {
      std::cout<<"Failed to load\n";
    }
    else
    {
      bool quit =false;
      SDL_Event e;
      while( ! quit )
      {
        while( SDL_PollEvent( &e ) != 0)
        {
          if(e.type == SDL_QUIT )
          {
            std::cout<<"Entered"<<std::endl;
            quit = true;
          }
        }
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
        SDL_BlitSurface(imgSurface, NULL, screenSurface, NULL);
        SDL_UpdateWindowSurface(window);
        // SDL_Delay(2000);
      }
    }
  }

  close();

  return 0;


}
