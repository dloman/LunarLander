//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Lunar Lander Display code
//
// - Dan Loman
// - 6/28/2016
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#include "Display.hpp"

#include <LunarSurfaceGenerator.hpp>

#include <iostream>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
Display::Display(unsigned Width, unsigned Height)
  : mWidth(Width),
    mHeight(Height),
    mWindow(sf::VideoMode(mWidth, mHeight), "Lunar Lander"),
    mLunarSurface(MoonGenerator::GenerateLunarSurface(mWidth, mHeight)),
    mLander(mWidth, mHeight, mLunarSurface)
{
  mWindow.setVerticalSyncEnabled(true);
  mWindow.clear(sf::Color::Black);
  mWindow.display();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Display::Update()
{
  mWindow.clear(sf::Color::Black);

  mLander.Update(mWindow);

  mWindow.draw(mLunarSurface);

  sf::Event Event;
  mWindow.pollEvent(Event);

  if (Event.type == sf::Event::Closed)
  {
    mWindow.close();
    exit(0);
  }
  mWindow.display();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Display::DisplayErrorAndExit(const std::string& ErrorString) const
{
  std::cerr << "ERROR: " << ErrorString << std::endl;
  exit(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
bool Display::IsClosed() const
{
  return mWindow.isOpen();
}
