#include "../include/Menu.h"
#include "../include/Game.h"
#include "../include/Login.h"

/**
 * @brief Construct a new Menu:: Menu object
 * 
 */
Menu::Menu() : State(400, 600, (char *)"Menu")
{
    SetWindowSize((int)W_WIDTH, (int)W_HEIGHT);
    SetWindowTitle(W_TITLE);
}

/**
 * @brief Représentation du bouton de démarrage
 * 
 * @return Rectangle 
 */
Rectangle Menu::getStartBlock()
{
    Rectangle start = {((W_WIDTH / 2) - (W_WIDTH / 2) / 2), W_HEIGHT * (float)0.25, (W_WIDTH / 2), W_HEIGHT / 8};
    return start;
}

/**
 * @brief Représentation du bouton back
 * 
 * @return Rectangle 
 */
Rectangle Menu::getBackBlock()
{
    Rectangle back = {W_WIDTH * (float)0.02, W_HEIGHT * (float)0.02, W_WIDTH * (float)0.2, W_HEIGHT * (float)0.05};
    return back;
}

/**
 * @brief Vérifie les cliques de la souris
 * 
 */
void Menu::checkCollisionBlock()
{
    if (CheckCollisionPointRec(GetMousePosition(), getBackBlock()))
    {
        mouseOnBack = true;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            clickOnBack = true;
        }
    }
    else
        mouseOnBack = false;

    if (CheckCollisionPointRec(GetMousePosition(), getStartBlock()))
    {
        mouseOnStart = true;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            clicOnStart = true;
        }
    }
    else
        mouseOnStart = false;
}

/**
 * @brief Dessine un bouton Start
 * 
 */
void Menu::drawStartBlock()
{
    Rectangle start = getStartBlock();
    DrawRectangleRec(start, LIGHTGRAY);
    DrawText("Start", start.x + start.width * 0.22, start.y + start.height * 0.25, 40, GRAY);

    if (mouseOnStart)
        DrawRectangleLinesEx(start, 2, BLUE);

    else
        DrawRectangleLinesEx(start, 2, DARKGRAY);
}

/**
 * @brief Dessine un bouton back
 * 
 */
void Menu::drawBackBlock()
{
    Rectangle back = getBackBlock();
    DrawRectangleRounded(back, 0.5, 4, {255, 161, 0, 150});
    DrawText("Log out", back.x + back.width * 0.05, back.y + back.height * 0.27, 20, GRAY);

    if (mouseOnBack)
        DrawRectangleRoundedLines(back, 0.5, 4, 5, RED);

    else
        DrawRectangleRoundedLines(back, 0.5, 4, 5, ORANGE);
}

/**
 * @brief Opération possible dans le menu
 * 
 * @param app 
 */
void Menu::run(App *app)
{
    if (clicOnStart)
    {
        app->setState(new Game);
    }
    else if (clickOnBack)
    {
        app->setState(new Login);
    }
    checkCollisionBlock();
    drawStartBlock();
    drawBackBlock();
}