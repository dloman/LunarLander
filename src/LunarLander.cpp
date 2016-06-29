//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Lunar Lander
//
// - Dan Loman
// - 6/28/2016
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include <iostream>

#include "Display.hpp"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
int main()
{
  Display display;
  for (auto i = 0u; i < 100000; ++i)
  {
    display.Update();
  }
  return 0;
}

