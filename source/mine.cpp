#include "field.hpp"
#include "buffer.hpp"
#include "setup.hpp"
#include "colour.hpp"
#include "display.hpp"

int main()
{
#ifdef _WIN32
    system("chcp 65001");
#endif
    clearScreen();
    setGameMode();
    getQuickClearSettings();

    Field field;

    while (true)
    {
        clearScreen();

        dispBanner();
        field.drawField();
        dispFlagCounter();
        
        if (gameState != RUNNING)
            dispVictoryOrDefeat();
        else
            dispControls();

        writeBuf.disp();
        writeBuf.clear();

        if (gameState == RUNNING)
            field.getMove();
        else
            break;
    }

    std::cout << endl
              << reset;

    return 0;
}