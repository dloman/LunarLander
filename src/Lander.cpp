//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Lunar Lander Lander code
//
// - Dan Loman
// - 6/28/2016
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#include "Lander.hpp"

#include <LunarSurfaceGenerator.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

#include <iostream>
#include <cmath>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
Lander::Lander(unsigned Width, unsigned Height, sf::VertexArray& LunarSurface)
  : mWindowWidth(Width),
    mWindowHeight(Height),
    mSpriteWidth(0),
    mSpriteHeight(0),
    mTexture(),
    mSprite(),
    mLunarSurface(LunarSurface),
    mPosition(0, 1),
    mVelocity(.7, .7),
    mGravity(0.0, 0.005),
    mAcceleration(mGravity),
    mCrashed(false),
    mFont(),
    mMessage()
{
  if (
    !mTexture.loadFromFile(
      "/home/dloman/Source/LunarLander/static/images/lander.png"))
  {
    std::cerr << "ERROR: Couldn't load texture" << std::endl;
    exit(1);
  }
  mSprite.setTexture(mTexture);
  mSprite.setScale(sf::Vector2f(0.6f, 0.6f));

  auto Size = mSprite.getGlobalBounds();
  mSpriteWidth = Size.width;
  mSpriteHeight = Size.height;
  mSprite.setOrigin(sf::Vector2f(Size.width / 2, Size.height / 2));
  mPosition.y += Size.height / 2;
  mSprite.setPosition(mPosition);

  if (!mFont.loadFromFile("/usr/share/fonts/truetype/msttcorefonts/arial.ttf"))
  {
    std::cerr << "ERROR: Font not loading " << std::endl;
  }

  mMessage.setFont(mFont);
  mMessage.setCharacterSize(55);
  mMessage.setColor(sf::Color::White);
  mMessage.setStyle(sf::Text::Bold);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Lander::UpdatePhysics()
{
  if (mCrashed)
  {
    return;
  }

  mVelocity += mAcceleration;
  mPosition += mVelocity;
  if (mPosition.x >= mWindowWidth|| mPosition.y > mWindowHeight)
  {
    mPosition = sf::Vector2f(0, 15);
    mVelocity = sf::Vector2f(.7, .7);
    mAcceleration = sf::Vector2f(0.0 , 0.01);
    mSprite.setRotation(0);
  }
  mSprite.setPosition(mPosition);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
bool Lander::HasCollidedWithGround() const
{
  auto BoundingBox = mSprite.getGlobalBounds();

  auto HasCollided = [&BoundingBox] (sf::Vertex& Vertex)
  {
    return BoundingBox.contains(Vertex.position);
  };

  for (size_t i = 0u; i < mLunarSurface.getVertexCount(); ++i)
  {
    if (HasCollided(mLunarSurface[i]))
    {
      return true;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Lander::Update(sf::RenderWindow& Window)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    mSprite.rotate(3);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    mSprite.rotate(-3);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    auto Rotation = DegreesToRadians * mSprite.getRotation();
    mAcceleration.x += .0005 * sin(Rotation);
    mAcceleration.y -= .0005 * cos(Rotation);
  }
  else
  {
    mAcceleration = mGravity;
  }
  UpdatePhysics();

  if (HasCollidedWithGround())
  {
    auto Rotation = mSprite.getRotation();

    if ((Rotation < 10 || Rotation > 355) &&
      mVelocity.x < .7 && mVelocity.y < .7)
    {
      mMessage.setString("Succseful Landing!!");
    }
    else
    {
      mMessage.setString("You crashed and died horribly");
    }

    mCrashed = true;
  }
  Window.draw(mSprite);

  if (mCrashed)
  {
    Window.draw(mMessage);
  }
}

