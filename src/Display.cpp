//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Lunar Lander Display code
//
// - Dan Loman
// - 6/28/2016
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#include "Display.hpp"

#include <SDL.h>
#include <iostream>
//#include <stdio.h>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
Display::Display()
  : mpWindow(nullptr),
    mpScreenSurface(nullptr),
    mWidth(400),
    mHeight(600),
    mLastUpdate(std::chrono::system_clock::now()),
    mColor(0x00)
{
  InitializeDisplay();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
Display::Display(unsigned width, unsigned height)
  : mpWindow(nullptr),
    mpScreenSurface(nullptr),
    mWidth(width),
    mHeight(height),
    mLastUpdate(std::chrono::system_clock::now()),
    mColor(0x00)
{
  InitializeDisplay();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
Display::~Display()
{
  SDL_DestroyWindow(mpWindow );
  SDL_Quit();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Display::InitializeDisplay()
{
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    DisplayErrorAndExit("sdl couldn't be initialized");
  }
  mpWindow = SDL_CreateWindow(
    "Lunar Lander",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    mWidth,
    mHeight,
    SDL_WINDOW_SHOWN);
  if(!mpWindow)
  {
    DisplayErrorAndExit("Window could not be created!");
  }

  mpScreenSurface = SDL_GetWindowSurface(mpWindow);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Display::Update()
{
  using namespace std::chrono;

  if (system_clock::now()- mLastUpdate > milliseconds(500))
  {
    if (mColor == 0xFF)
    {
      mColor = 0x00;
    }
    else
    {
      mColor = 0xFF;
    }
    mLastUpdate = system_clock::now();
  }

    SDL_FillRect(
      mpScreenSurface,
      nullptr,
      SDL_MapRGB(mpScreenSurface->format, mColor, mColor, mColor));

     SDL_UpdateWindowSurface(mpWindow);
     SDL_Delay(2000);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Display::DisplayErrorAndExit(const std::string& ErrorString) const
{
  std::cerr << "ERROR: " << ErrorString << std::endl;
  exit(1);
}
