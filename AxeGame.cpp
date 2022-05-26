#include "raylib.h"

int main()
{
    //window
    int width{800};
    int height{450};
    InitWindow(width, height, "Axe Game"); 

    //circle coordinates
    int circle_x{200};
    int circle_y{200};
    //circle radius
    int circle_radius{25};
    //circle edges
    int left_circle_x{circle_x - circle_radius};
    int right_circle_x{circle_x + circle_radius};
    int up_circle_y{circle_y - circle_radius};
    int below_circle_y{circle_y + circle_radius};

    //axe coordinates
    int axe_x{400};
    int axe_y{0};
    //axe dimensions
    int axe_length{50};
    //axe mouvement
    int direction{10};
    //axe edges
    int left_axe_x{axe_x};
    int right_axe_x{axe_x + axe_length};
    int up_axe_y{axe_y};
    int below_axe_y{axe_y + axe_length};

    //true if collision 
    bool collision_axe = 
                        (below_axe_y >= up_circle_y) && 
                        (up_axe_y <= below_circle_y) && 
                        (left_axe_x <= right_circle_x) && 
                        (right_axe_x >= left_circle_x);

    SetTargetFPS(60);
    //keep the window open
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        //win or lose
        if(collision_axe)
        {
            DrawText("Imagine losing!!!!", 330, 200, 20, RED);
        }
        else
        {

            //Game Logic

            //update the edges
            //circle
            int left_circle_x{circle_x - circle_radius};
            int right_circle_x{circle_x + circle_radius};
            int up_circle_y{circle_y - circle_radius};
            int below_circle_y{circle_y + circle_radius};
            //axe
            int left_axe_x{axe_x};
            int right_axe_x{axe_x + axe_length};
            int up_axe_y{axe_y};
            int below_axe_y{axe_y + axe_length};
            //update collision with axe
            collision_axe = 
                        (below_axe_y >= up_circle_y) && 
                        (up_axe_y <= below_circle_y) && 
                        (left_axe_x <= right_circle_x) && 
                        (right_axe_x >= left_circle_x);

            //render simple forms on the screen
            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, BROWN);

            //move the axe
            axe_y += direction;
            if( axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }

            //Mouvement circle 
            if(IsKeyDown(KEY_D) && right_circle_x < width)
            {
                circle_x += 10;
            }
            else if (IsKeyDown(KEY_A) && left_circle_x > 0)
            {
                circle_x -= 10;
            }

            //end game logic
        }

        EndDrawing();
    }                                   
}