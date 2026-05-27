#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "Game of Life");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Hello World", 350, 280, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
