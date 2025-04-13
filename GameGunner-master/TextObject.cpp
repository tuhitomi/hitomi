#include "TextObject.h"

TextObject::TextObject() {
  text_color_.r=255;
  text_color_.g=255;
  text_color_.b=255;
  texture=NULL;
  str_val_="";
}
TextObject::~TextObject()
{

}
bool TextObject::LoadFromRenderText(TTF_Font *font, SDL_Renderer* screen)
{
    SDL_Surface* text_surface=TTF_RenderText_Solid(font,str_val_.c_str(),text_color_);
    if(text_surface)
    {
        texture=SDL_CreateTextureFromSurface(screen,text_surface);
        width=text_surface->w;
        height=text_surface->h;
            SDL_FreeSurface(text_surface);
    }
    return texture!=NULL;
}
void TextObject::Free() {
if(texture!=NULL) {
    SDL_DestroyTexture(texture);
    texture=NULL;
}
}
void TextObject::SetColor(Uint8 red,Uint8 green,Uint8 blue)
{
    text_color_.r=red;
    text_color_.g=green;
    text_color_.b=blue;
}
void TextObject::SetColor(int type)
{
    if(type==RED_TEXT)
    {
        SDL_Color color={255,0,0};
        text_color_=color;
    }
    else if(type==WHITE_TEXT)
    {
        SDL_Color color={255,255,255};
        text_color_=color;
    }
    else if(type==BLACK_TEXT)
    {
        SDL_Color color={0,0,0};
        text_color_=color;
    }
}
void TextObject::RenderText(SDL_Renderer* screen,int xp,int yp,SDL_Rect* clip, double angle,SDL_Point* center,SDL_RendererFlip flip)
{
    SDL_Rect RenderQuad={xp,yp,width,height};
    if(clip!=NULL)
    {
        RenderQuad.w=clip->w;
        RenderQuad.h=clip->h;
    }
    SDL_RenderCopyEx(screen,texture,clip,&RenderQuad,angle,center,flip);
}
