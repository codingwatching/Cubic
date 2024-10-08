#pragma once
#include "VertexList.h"

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

class UI
{
public:
  enum class State
  {
    None = 0,
    StatusMenu = 1 << 0,
    SelectBlockMenu = 1 << 1,
    MainMenu = 1 << 2,
    SaveMenu = 1 << 3,
    LoadMenu = 1 << 4,
  };

  void init();
  bool input(const SDL_Event& event);
  void update();
  void render();
  void tick();

  void openMenu(UI::State state, bool shouldUpdate = true);
  void openStatusMenu(const char* title, const char* description, bool closeable = false);
  void openMainMenu();
  void closeMenu();

  void log(const char* format, ...);

  UI::State state;
  bool isTouch;

private:
  enum class MouseState
  {
    Up = 0,
    Down = 1 << 0,
  };

  enum class TouchState
  {
    None = 0,
    Up = 1 << 0,
    Down = 1 << 1,
    Left = 1 << 2,
    Right = 1 << 3,
    Middle = 1 << 4,
    Jump = 1 << 5,
    Fullscreen = 1 << 6,
    Menu = 1 << 7,
  };

  enum class Cancellable
  {
    None = 0,
    Hold = 1 << 0,
    Swipe = 1 << 1,
  };

  struct Log
  {
    uint64_t created;
    std::string text;
  };

  struct Save
  {
    std::string path;
    std::string name;
    int index;
  };

  struct TouchPosition 
  {
    int64_t id;

    float x;
    float y;
    float initialX;
    float initialY;

    uint64_t startTime;

    bool swipe;
    bool hold;
    bool isHolding;
  };

  bool refresh();
  bool load(size_t index);
  bool save(size_t index);

  void drawHUD();
  void drawFPS();
  void drawCrosshair();
  void drawLogs();
  void drawHotbar();
  bool drawTouchControls(bool invisible = false);
  
  bool drawStatusMenu();
  bool drawLoadMenu();
  bool drawSaveMenu();
  bool drawMainMenu();
  bool drawSelectBlockMenu();

  bool drawSelectBlockButton(unsigned char blockType, unsigned char& selectedBlockType, int x, int y, int width, int height);
  bool drawTouchButton(unsigned int flag, int x, int y, int z, const char* text, int width = 200, int height = 20, bool multiTouch = true, bool invisible = false);
  bool drawButton(int x, int y, int z, const char* text, int state = 1, int width = 200, int height = 20);

  void drawBlock(unsigned char blockType, int x, int y, float scale);

  void drawInterface(int x0, int y0, int x1, int y1, int u0, int v0, int u1, int v1, float shade, int z);
  void drawInterface(int x0, int y0, int x1, int y1, int u0, int v0, int u1, int v1, float shade);
  void drawInterface(int x0, int y0, int x1, int y1, int u, int v, float shade, int z);
  void drawInterface(int x0, int y0, int x1, int y1, int u, int v, float shade);
  void drawInterface(int x0, int y0, int x1, int y1, int u, int v);

  void drawFont(const char* text, int x, int y, float shade, int z);
  void drawShadowedFont(const char* text, int x, int y, float shade, int z);
  void drawShadowedFont(const char* text, int x, int y, float shade);
  void drawCenteredFont(const char* text, int x, int y, float shade, int z);
  void drawCenteredFont(const char* text, int x, int y, float shade);

  const int FONT_WIDTHS[256] = {
    1, 8, 8, 8, 8, 8, 8, 9, 9, 1, 8, 8, 1, 8, 8, 8,
    8, 8, 1, 1, 8, 8, 8, 8, 1, 1, 8, 8, 8, 8, 8, 8,
    4, 2, 5, 6, 6, 7, 7, 3, 5, 5, 8, 6, 2, 6, 2, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 5, 6, 5, 6,
    7, 6, 6, 6, 6, 6, 6, 6, 6, 4, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 6, 4, 6, 6,
    3, 6, 6, 6, 6, 6, 5, 6, 6, 2, 6, 5, 3, 6, 6, 6,
    6, 6, 6, 6, 4, 6, 6, 6, 6, 6, 6, 5, 2, 5, 7, 6,

    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  };

  glm::vec2 mousePosition;
  UI::MouseState mouseState;
  unsigned int touchState;

  std::vector<glm::vec2> buttonPositions;
  std::vector<TouchPosition> touchPositions;
  std::vector<Log> logs;

  size_t page;
  std::vector<Save> saves;

  std::string statusTitle;
  std::string statusDescription;
  bool statusCloseable;

  uint64_t mainMenuLastCopy;

  VertexList fontVertices;
  GLuint fontTexture;

  VertexList interfaceVertices;
  GLuint interfaceTexture;

  VertexList blockVertices;

  const float TOUCH_SWIPE_OFFSET = 0.015f;
  const int TOUCH_PLACE_DELAY = 200;
  const int TOUCH_BREAK_DELAY = 300;
};

