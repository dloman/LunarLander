//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Lunar Lander Generates terrain of the moon
//
// - Dan Loman
// - 6/28/2016
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#include "LunarSurfaceGenerator.hpp"

#include <SFML/Graphics/ConvexShape.hpp>

#include <chrono>

namespace MoonGenerator
{

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
sf::VertexArray GenerateLunarSurface(
  const unsigned WindowWidth,
  const unsigned WindowHeight)
{
  sf::VertexArray Lines(sf::LinesStrip, 0);

  auto LandingSpots = GenerateLandingSpots(4, WindowWidth);

  std::default_random_engine Generator(
    std::chrono::high_resolution_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<int> Distribution(0, 1);
  auto Random = [&Generator, &Distribution] { return Distribution(Generator); };

  auto InLandingSpot = [&LandingSpots] (const int Width)
  {
    return std::any_of(
      LandingSpots.begin(),
      LandingSpots.end(),
      [Width] (int Value) { return Width >= Value && Width < Value + 40;});
  };

  auto Height = WindowHeight * .75;
  for (auto Width = 0u; Width < WindowWidth; Width += 4)
  {
    if (!InLandingSpot(Width))
    {
      if (Random())
      {
        Height += 18;
      }
      else
      {
        Height -= 18;
      }
      if (Height <= 0)
      {
        Height = 1;
      }
    }
    Lines.append(sf::Vector2f(Width, Height));
  }
  return Lines;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
std::vector<int> GenerateLandingSpots(
  const int NumberOfLandingSpots,
  const int WindowWidth)
{
  std::vector<int> LandingSpots;
  std::default_random_engine Generator(
    std::chrono::high_resolution_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<int> Distribution(0, WindowWidth - 8);

  auto Random = [&] { LandingSpots.emplace_back(Distribution(Generator)); };

  for (int i = 0; i < NumberOfLandingSpots; ++i)
  {
    Random();
  }
  return LandingSpots;
}

}

