//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Lunar Lander Display code
//
// - Dan Loman
// - 6/28/2016
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class SDL_Window;
class SDL_Surface;

#include <chrono>
#include <string>
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
class Display
{
  public:

    Display();

    Display(unsigned width, unsigned height);

    ~Display();

    Display(const Display& other) = delete;

    Display& operator = (const Display& rhs) = delete;

    void Update();

  private:

    void InitializeDisplay();

    void DisplayErrorAndExit(const std::string& ErrorString) const;

  private:

    SDL_Window* mpWindow;

    SDL_Surface* mpScreenSurface;

    unsigned mWidth;

    unsigned mHeight;

    std::chrono::time_point<
      std::chrono::system_clock,
      std::chrono::duration<double>> mLastUpdate;

    uint8_t mColor;
};

