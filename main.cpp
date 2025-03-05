#include "include/raylib.h"
#include <iostream>
#include <vector>
#include <math.h>

class circle
{
public:
    float x;       // X pos
    float y;       // Y pos
    float r;       // radius
    float s;       // speed
    Color c;       // color
    float d;       // Distance from Center
    float a;       // angle: required for speed
    std::string n; // Name

    circle(std::string _n, float _r, float _s, Color _c, float _d) : n(_n), r(_r), c(_c), d(_d)
    {

        x = 0;
        y = 0;
        a = 0.0f;
        s = _s * DEG2RAD;
    }
};

int main()
{

    InitWindow(1000, 1000, "GGT MP");

    SetTargetFPS(60);

    bool Paused = false;

    /// Panets:
    /// Mecury , Venus , Earth , Mars , Jupiter , Saturn , Uranus , Neptune

    circle Sun("Sun", 50, 0, ORANGE, 0);

    circle Mercury("Mercury", 5, 4.15, DARKGRAY, 100);
    circle Venus("Venus", 8, 1.62, GOLD, 140);
    circle Earth("Earth", 10, 1.00, BLUE, 180);
    circle Mars("Mars", 8, 0.53, MAROON, 220);
    circle Jupiter("Jupiter", 20, 0.32, ORANGE, 280);
    circle Saturn("Saturn", 18, 0.16, BEIGE, 340);
    circle Uranus("Uranus", 15, 0.08, SKYBLUE, 400);
    circle Neptune("Neptune", 14, 0.04, DARKBLUE, 460);

    std::vector<circle *> objects = {&Mercury, &Venus, &Earth, &Mars, &Jupiter, &Saturn, &Uranus, &Neptune};

    Camera2D camera;
    Vector2 center = {0, 0};
    float pace = 1.0f;

    camera.target = {Sun.x, Sun.y};
    camera.offset = {500, 500};
    camera.rotation = 0;
    camera.zoom = 1.0f;

    while (!WindowShouldClose())
    {

        {

            if (IsKeyReleased(KEY_SPACE))
            {
                Paused = Paused ? false : true;
            }

            if (IsKeyReleased(KEY_UP))
            {
                camera.zoom += 0.1f;
            }
            if (IsKeyReleased(KEY_DOWN))
            {
                camera.zoom -= 0.1f;
            }

            if (IsKeyReleased(KEY_R))
            {
                camera.zoom = 1.0f;
                pace = 1.f;
            }

            if (IsKeyReleased(KEY_RIGHT))
            {
                pace += 0.2f;
            }

            if (IsKeyReleased(KEY_LEFT))
            {
                pace -= 0.2f;
            }
        }

        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Solar System Animation", 10, 5, 20, WHITE);
        BeginMode2D(camera);

        DrawCircle(Sun.x, Sun.y, Sun.r, ORANGE);
        DrawText(Sun.n.c_str(), Sun.x - Sun.r / 2 + 10, Sun.y - Sun.r - 20, 15, WHITE);

        for (circle *o : objects)
        {

            if (!Paused)
            {
                o->a += o->s * pace;
                o->x = center.x + o->d * cosf(o->a);
                o->y = center.y + o->d * sinf(o->a);
            }
            else
            {
                DrawText("Paused", -80, -500, 40, WHITE);
            }

            DrawText(o->n.c_str(), o->x - o->r, o->y - o->r - 20, 15, WHITE);

            DrawCircleLines(center.x, center.y, o->d, GRAY);

            DrawCircle(o->x, o->y, o->r, o->c);
        }

        EndMode2D();

        EndDrawing();
    }

    return 0;
}