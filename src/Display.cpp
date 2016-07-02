//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Lunar Lander Display code
//
// - Dan Loman
// - 6/28/2016
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#include "Display.hpp"

#include <iostream>
#include <thread>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
Display::Display(unsigned width, unsigned height)
  : mWidth(width),
    mHeight(height),
    mWindow(sf::VideoMode(mWidth, mHeight), "Lunar Lander"),
    mTexture(),
    mSprite()
{
  if (!mTexture.loadFromFile("/home/dloman/Source/LunarLander/static/images/lander.png"))
  {
    DisplayErrorAndExit("Couldn't load texture");
  }
  mSprite.setTexture(mTexture);
  mSprite.setPosition(sf::Vector2f(0, mHeight / 2));
  mWindow.setVerticalSyncEnabled(true);
  mWindow.clear(sf::Color::Black);
  mWindow.display();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Display::Update()
{
  mWindow.clear(sf::Color::Black);

  mWindow.draw(mSprite);

  sf::Event Event;
  mWindow.pollEvent(Event);

  if (Event.type == sf::Event::Closed)
  {
    mWindow.close();
    exit(0);
  }
  mWindow.display();

  auto Position = mSprite.getPosition();

  Position.x += 5;
  if (Position.x >= mWidth)
  {
    Position.x = 0;
  }

  mSprite.setPosition(Position);
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
