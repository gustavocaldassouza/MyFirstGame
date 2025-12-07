#include "raylib.h"
#include <vector>
#include <cmath>

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
    bool alive;
    Color color;
};

Vector2 Rotate(Vector2 point, Vector2 center, float angleDeg)
{
    float rad = angleDeg * PI / 180.0f;
    float s = sinf(rad);
    float c = cosf(rad);

    point.x -= center.x;
    point.y -= center.y;

    float xnew = point.x * c - point.y * s;
    float ynew = point.x * s + point.y * c;

    return {xnew + center.x, ynew + center.y};
}

void DrawStickMan(const StickMan &man)
{
    float dir = man.isPlayer ? -1.0f : 1.0f;
    float angle = 0.0f;

    // If dead, rotate 90 degrees backwards
    if (!man.alive)
    {
        angle = man.isPlayer ? 90.0f : -90.0f;
    }

    // Pivot around the feet
    Vector2 center = {man.x, man.y + 80};

    auto T = [&](float x, float y) -> Vector2
    {
        return Rotate({x, y}, center, angle);
    };

    // Head
    DrawCircleV(T(man.x, man.y - 50), 20, man.color);
    // Body
    DrawLineEx(T(man.x, man.y - 30), T(man.x, man.y + 40), 3.0f, BLACK);
    // Arms (Holding gun)
    DrawLineEx(T(man.x, man.y - 10), T(man.x + 30 * dir, man.y), 3.0f, BLACK);
    // Legs
    DrawLineEx(T(man.x, man.y + 40), T(man.x - 20, man.y + 80), 3.0f, BLACK);
    DrawLineEx(T(man.x, man.y + 40), T(man.x + 20, man.y + 80), 3.0f, BLACK);
    // Gun (Approximated as a thick line)
    DrawLineEx(T(man.x + 30 * dir, man.y), T(man.x + 50 * dir, man.y), 10.0f, BLACK);
}

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "My First Game - Stick Men");

    // Player on the right (600), Enemy on the left (200)
    StickMan player = {600, 300, true, true, BLUE};
    StickMan enemy = {200, 300, false, true, RED};

    std::vector<Bullet> bullets;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update
        if (IsKeyPressed(KEY_SPACE) && player.alive)
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

                // Collision with Enemy
                if (enemy.alive)
                {
                    // Simple bounding box for enemy
                    // x-20 to x+20, y-70 to y+80
                    if (bullet.x >= enemy.x - 20 && bullet.x <= enemy.x + 20 &&
                        bullet.y >= enemy.y - 70 && bullet.y <= enemy.y + 80)
                    {
                        enemy.alive = false;
                        bullet.active = false;
                    }
                }
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Press SPACE to shoot!", 10, 10, 20, DARKGRAY);

        DrawStickMan(enemy);
        DrawStickMan(player);

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
