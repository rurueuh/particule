#include "Game.hpp"

int main(void)
{
    #ifndef DEBUG
        HWND hwnd = GetConsoleWindow(); 
        ShowWindow(hwnd, SW_HIDE);
    #endif
    
    Game game;
    game.run();
    
    return 0;
}