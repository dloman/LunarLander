//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Lunar Lander Display code
//
// - Dan Loman
// - 6/28/2016
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include <Lander.hpp>

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include <chrono>
#include <string>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
class Display
{
  public:

    Display(unsigned Width, unsigned Height);

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

    sf::VertexArray mLunarSurface;

    Lander mLander;
};

