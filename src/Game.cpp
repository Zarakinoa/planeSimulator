#include "../include/Game.h"
#include "../include/Pipe.h"
#include "../include/Menu.h"

/**
 * @brief Construct a new Game:: Game object
 * 
 */
Game::Game() : State(800, 700, (char *)"Game"), m_fs(), m_db()
{
    SetWindowSize(W_WIDTH, W_HEIGHT);
    SetWindowTitle(W_TITLE);
};

/**
 * @brief Retourne une représentation Graphique
 * 
 * @return Rectangle 
 */
Rectangle Game::getBackBlock()
{
    Rectangle back = {W_WIDTH * (float)0.01, W_HEIGHT * (float)0.01, W_WIDTH * (float)0.07, W_HEIGHT * (float)0.03};
    return back;
}

/**
 * @brief Vérifie les cliques de la souris
 * 
 */
void Game::checkCollisionBlock()
{
    if (CheckCollisionPointRec(GetMousePosition(), getBackBlock()))
    {
        mouseOnBack = true;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            clicOnBack = true;
        }
    }
    else
        mouseOnBack = false;
}

/**
 * @brief Dessine un block
 * 
 */
void Game::drawBackBlock()
{
    Rectangle back = getBackBlock();
    DrawRectangleRounded(back, 0.5, 4, {255, 161, 0, 150});
    DrawText("Back", back.x + back.width * 0.20, back.y + back.height * 0.2, 14, GRAY);

    if (mouseOnBack)
        DrawRectangleRoundedLines(back, 0.5, 4, 5, RED);

    else
        DrawRectangleRoundedLines(back, 0.5, 4, 5, ORANGE);
}

/**
 * @brief Lance l'exercice de simulation
 * 
 * @param app 
 */
void Game::run(App *app)
{
    if (clicOnBack)
    {
        app->setState(new Menu);
    }

    checkCollisionBlock();
    drawBackBlock();

    if (!m_fs.allTanksEmpty())
    {

        m_db.run(&m_fs, app);
        m_fs.run(app);
    }
    else
        DrawText("Game Over", W_WIDTH * 0.15, W_HEIGHT * 0.4, 100, RED);
}