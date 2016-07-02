//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Lunar Lander Display code
//
// - Dan Loman
// - 6/28/2016
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include <SFML/Graphics/VertexArray.hpp>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
namespace MoonGenerator
{
  sf::VertexArray GenerateLunarSurface(
    const unsigned WindowWidth,
    const unsigned WindowHeight);

  std::vector<int> GenerateLandingSpots(
    const int NumberOfLandingSpots,
    const int WindowWidth);

}

