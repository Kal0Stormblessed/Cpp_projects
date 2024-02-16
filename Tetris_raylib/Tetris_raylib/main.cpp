#include "raylib.h"
#include "Game.h"
 
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

    Game game{ screenWidth, screenHeight, 60 , "Tetris raylib" };

    while (!game.GameShouldClose())
    {
        game.Tick();
    }
    
    return 0;
}