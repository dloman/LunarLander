//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Lunar Lander Lander code
//
// - Dan Loman
// - 6/28/2016
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <chrono>
#include <string>

namespace sf
{
  class VertexArray;
  class RenderWindow;
}

constexpr double Pi = 3.14159265358979323846264338327950288419716939937510582;
constexpr double PiDiv2 = Pi / 2.0;
constexpr double DegreesToRadians = Pi / 180.0;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
class Lander
{
  public:

    Lander(unsigned Width, unsigned Height, sf::VertexArray& LunarSurface);

    ~Lander() = default;

    Lander(const Lander& other) = delete;

    Lander& operator = (const Lander& rhs) = delete;

    void Update(sf::RenderWindow& Window);

  private:

    void UpdatePhysics();

    bool HasCollidedWithGround() const;

  private:

    unsigned mWindowWidth;

    unsigned mWindowHeight;

    unsigned mSpriteWidth;

    unsigned mSpriteHeight;

    sf::Texture mTexture;

    sf::Sprite mSprite;

    sf::VertexArray& mLunarSurface;

    sf::Vector2f mPosition;

    sf::Vector2f mVelocity;

    const sf::Vector2f mGravity;
    sf::Vector2f mAcceleration;


};

