#include <iostream>
#include <raylib.h>
#include <dlfcn.h>
#include "plugin.h"

#define WIDTH  900
#define HEIGHT 600
#define FPS    60

display_t display_fn = nullptr;

int main() {
  // ################################################
  //                    RECTS
  // ################################################
  Rectangle button = {300, 250, 200, 80};
  
  // ################################################
  //              load shared library
  // ################################################
  Plugin plugin{};
  plugin.version = 0;
  if (!loadPlugin(plugin)) { return 1; }
  
  // ################################################
  //                   RAYLIB
  // ################################################
  InitWindow(WIDTH, HEIGHT, "Hot reloaded button");
  SetTargetFPS(FPS);
  
  // ################################################
  //                 EVENT LOOP
  // ################################################
  while (!WindowShouldClose()) {
    // ---- mouse event handler ----
    Vector2 mouse = GetMousePosition();
    bool hover = CheckCollisionPointRec(mouse, button);

    // button click event
    if (hover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      plugin.display();
    }

    // keyboard event handler
    if (IsKeyPressed(KEY_R)) {
      std::cout << "[INFO] reloading...\n";
      if (!reloadPlugin(plugin)) {
	return 1;
      }
    }

    // ---- Drawing ----
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawRectangleRec(button, hover? BLUE : RED);
    DrawText("Click Me", 350, 280, 20, BLACK);
    DrawText("Press R to reload", 10, 10, 20, DARKGRAY);
    
    EndDrawing();
  }
  
  unloadPlugin(plugin);
  CloseWindow();
  return 0;
}
