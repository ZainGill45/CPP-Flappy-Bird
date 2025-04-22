#include <iostream>
#include <raylib.h>

int main(int, char**) {
    InitWindow(800, 600, "My Raylib Window");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello, from learning C++", 10, 10, 20, BLACK);

        DrawFPS(10, 40);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}