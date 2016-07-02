//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Lunar Lander Display code
//
// - Dan Loman
// - 6/28/2016
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <chrono>
#include <string>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
class Display
{
  public:

    Display(unsigned width, unsigned height);

    ~Display() = default;

    Display(const Display& other) = delete;

    Display& operator = (const Display& rhs) = delete;

    void Update();

    bool IsClosed() const;

  private:

    void DisplayErrorAndExit(const std::string& ErrorString) const;

  private:

    unsigned mWidth;

    unsigned mHeight;

    sf::RenderWindow mWindow;

    sf::Texture mTexture;

    sf::Sprite mSprite;

};

