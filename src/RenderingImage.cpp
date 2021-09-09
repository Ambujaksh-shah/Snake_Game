
#include"RenderingImage.h"


SDL_Texture * ImageRendering::textureSurface(SDL_Renderer *rendrerSurface)
{
    int imgFlags = IMG_INIT_JPG | IMG_INIT_TIF;
    
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
        std::cerr<<"Unable to Initialise flags "<<SDL_GetError()<<std::endl;
        
    if( ! LoadImage() )
        std::cerr<<"Error"<<std::endl;
    else
    {
        TextureSurface = SDL_CreateTextureFromSurface(rendrerSurface,Image);
        if(TextureSurface == NULL)
            std::cerr<<"Not able to convert"<<SDL_GetError();

    }
    SDL_FreeSurface(Image);

    return TextureSurface;

}


int  ImageRendering::showmenu(SDL_Window *window)
{
    if( ! LoadFont() )
        return 0;

    screen = SDL_GetWindowSurface(window);
    if( screen == NULL)
    {
        std::cerr<<"NUll"<<SDL_GetError();
        return 0;
    }

    menus[0] = TTF_RenderText_Solid(font,labels[0],color[0]);
    menus[1] = TTF_RenderText_Solid(font,labels[1],color[0]);

    pos[0].x = screen->clip_rect.w/2 - menus[0]->clip_rect.w/2;
    pos[0].y = screen->clip_rect.h/2 - menus[0]->clip_rect.h;
    pos[1].x = screen->clip_rect.w/2 - menus[0]->clip_rect.w/2;
    pos[1].y = screen->clip_rect.h/2 + menus[0]->clip_rect.h;


    SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,0x00,0x00,0x00));
    SDL_Event event;

    while(1)
    {
       time = SDL_GetTicks();
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    SDL_FreeSurface(menus[0]);
                    SDL_FreeSurface(menus[1]);
                    return 1;
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;
                    for(int i = 0; i < NUMMENU; i += 1) {
                        if(x>=pos[i].x && x<=pos[i].x+pos[i].w && y>=pos[i].y && y<=pos[i].y+pos[i].h)
                        {
                            if(!selected[i])
                            {
                                selected[i] = 1;
                                SDL_FreeSurface(menus[i]);
                                menus[i] = TTF_RenderText_Solid(font,labels[i],color[1]);
                            }
                        }
                        else
                        {
                            if(selected[i])
                            {
                                selected[i] = 0;
                                SDL_FreeSurface(menus[i]);
                                menus[i] = TTF_RenderText_Solid(font,labels[i],color[0]);
                            }
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    x = event.button.x;
                    y = event.button.y;
                    for(int i = 0; i < NUMMENU; i += 1) {
                        if(x>=pos[i].x && x<=pos[i].x+pos[i].w && y>=pos[i].y && y<=pos[i].y+pos[i].h)
                        {
                            SDL_FreeSurface(menus[0]);
                            SDL_FreeSurface(menus[1]);
                            return i;
                        }
                    }
                    break;
            }
        }
        for(int i = 0; i < NUMMENU; i += 1) {
            SDL_BlitSurface(menus[i],NULL,screen,&pos[i]);
        }
        
        SDL_UpdateWindowSurface(window);
        if(1000/30 > (SDL_GetTicks()-time))
            SDL_Delay(1000/30 - (SDL_GetTicks()-time));
    }
}

bool ImageRendering::LoadFont()
{
    bool success =true;
    if(TTF_Init()< 0)
    {
        std::cout<<"Error : "<<TTF_GetError()<<std::endl;
        success = false;
    }
    else
    {
        font = TTF_OpenFont(fontpath.c_str(),45);
        if(font ==NULL)
            success = false;       
    }
    return success;
}


bool ImageRendering::LoadImage()
{
    bool success=true;
    Image = IMG_Load(filepath.c_str());
    if(Image == NULL)
        success = false; 
    
return success;
}



ImageRendering::~ImageRendering()
{

    IMG_Quit();
    TTF_Quit();
}