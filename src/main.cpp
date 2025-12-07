#include "raylib.h"
#include <vector>

struct Bullet
{
    float x, y;
    float speed;
    bool active;
};

struct StickMan
{
    float x, y;
    bool isPlayer;
    Color color;
};

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "My First Game - Stick Men");

    // Player on the right (600), Enemy on the left (200)
    StickMan player = {600, 300, true, BLUE};
    StickMan enemy = {200, 300, false, RED};

    std::vector<Bullet> bullets;

    SetTargetFPS(120);

    while (!WindowShouldClose())
    {
        // Update
        if (IsKeyPressed(KEY_SPACE))
        {
            // Player shoots to the left
            // Spawn bullet at the end of the gun
            bullets.push_back({player.x - 50, player.y - 10, -10.0f, true});
        }

        // Update bullets
        for (auto &bullet : bullets)
        {
            if (bullet.active)
            {
                bullet.x += bullet.speed;
                // Deactivate if off screen
                if (bullet.x < 0 || bullet.x > screenWidth)
                {
                    bullet.active = false;
                }
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Press SPACE to shoot!", 10, 10, 20, DARKGRAY);

        // --- Draw Enemy (Left, facing Right) ---
        // Head
        DrawCircle(enemy.x, enemy.y - 50, 20, enemy.color);
        // Body
        DrawLineEx({enemy.x, enemy.y - 30}, {enemy.x, enemy.y + 40}, 3.0f, BLACK);
        // Arms (Holding gun to the right)
        DrawLineEx({enemy.x, enemy.y - 10}, {enemy.x + 30, enemy.y}, 3.0f, BLACK);
        // Legs
        DrawLineEx({enemy.x, enemy.y + 40}, {enemy.x - 20, enemy.y + 80}, 3.0f, BLACK);
        DrawLineEx({enemy.x, enemy.y + 40}, {enemy.x + 20, enemy.y + 80}, 3.0f, BLACK);
        // Gun (Rectangle to the right)
        DrawRectangle(enemy.x + 30, enemy.y - 5, 20, 10, BLACK);

        // --- Draw Player (Right, facing Left) ---
        // Head
        DrawCircle(player.x, player.y - 50, 20, player.color);
        // Body
        DrawLineEx({player.x, player.y - 30}, {player.x, player.y + 40}, 3.0f, BLACK);
        // Arms (Holding gun to the left)
        DrawLineEx({player.x, player.y - 10}, {player.x - 30, player.y}, 3.0f, BLACK);
        // Legs
        DrawLineEx({player.x, player.y + 40}, {player.x - 20, player.y + 80}, 3.0f, BLACK);
        DrawLineEx({player.x, player.y + 40}, {player.x + 20, player.y + 80}, 3.0f, BLACK);
        // Gun (Rectangle to the left)
        DrawRectangle(player.x - 50, player.y - 5, 20, 10, BLACK);

        // --- Draw Bullets ---
        for (const auto &bullet : bullets)
        {
            if (bullet.active)
            {
                DrawCircle(bullet.x, bullet.y, 5, BLACK);
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
