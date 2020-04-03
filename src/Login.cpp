#include "../include/Login.h"
#include "../include/Menu.h"
#include <iostream>

int Login::framesCounterLogin = 0;
int Login::framesCounterPassword = 0;

/**
 * @brief Construct a new Login:: Login object
 * 
 */
Login::Login() : State(400, 600, (char *)"Login")
{
}

/**
 * @brief Champs de saisie pour l'id
 * 
 * @return Rectangle 
 */
Rectangle Login::getIdBlock()
{
    Rectangle id = {W_WIDTH / 2 - (225 / 2), 180, 225, 50};
    return id;
}

/**
 * @brief Champs de saisie pour le mot de passe
 * 
 * @return Rectangle 
 */
Rectangle Login::getPasswordBlock()
{
    Rectangle password = {W_WIDTH / 2 - (225 / 2), 300, 225, 50};
    return password;
}

/**
 * @brief Validation du login
 * 
 * @return Rectangle 
 */
Rectangle Login::getEnterBlock()
{
    Rectangle enter = {W_WIDTH / 2 - (100 / 2), 400, 100, 50};
    return enter;
}

/**
 * @brief Boutons Back
 * 
 * @return Rectangle 
 */
Rectangle Login::getBackBlock()
{
    Rectangle exit = {W_WIDTH * (float)0.02, W_HEIGHT * (float)0.02, W_WIDTH * (float)0.2, W_HEIGHT * (float)0.05};
    return exit;
}

/**
 * @brief Saisie
 * 
 */
void Login::checkCollisionBlock()
{
    std::string m_Log;
    std::string line;

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

    if (CheckCollisionPointRec(GetMousePosition(), getIdBlock()))
    {
        mouseOnId = true;

        int key = GetKeyPressed();

        if ((key >= 32) && (key <= 125) && (m_id.size() < MAX_INPUT_CHARS))
        {
            m_id.push_back((char)key);
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if (!m_id.empty())
            {
                m_id.pop_back();
            }
        }
    }

    else
        mouseOnId = false;

    if (CheckCollisionPointRec(GetMousePosition(), getPasswordBlock()))
    {
        mouseOnPassword = true;

        int key = GetKeyPressed();

        if ((key >= 32) && (key <= 125) && (m_pass.size() < MAX_INPUT_CHARS))
        {
            m_pass.push_back((char)key);
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if (!m_pass.empty())
            {
                m_pass.pop_back();
            }
        }
    }
    else
        mouseOnPassword = false;

    if (CheckCollisionPointRec(GetMousePosition(), getEnterBlock()) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        mouseOnEnter = true;
        std::ifstream bdd("userBDD.txt");

        if (bdd)
        {
            m_Log = m_id + " " + m_pass;

            while (getline(bdd, line))
            {
                if (m_Log.compare(line) == 0)
                {
                    clicOnEnter = true;
                }

                else
                {
                    connexion = false;
                }
            }
        }
    }
    else
        mouseOnEnter = false;

    if (mouseOnId)
        framesCounterLogin++;
    else
        framesCounterLogin = 0;

    if (mouseOnPassword)
        framesCounterPassword++;
    else
        framesCounterPassword = 0;
}

/**
 * @brief Information de l'user
 * 
 */
void Login::drawIdBlock()
{
    Rectangle id = getIdBlock();
    DrawText("ID", W_WIDTH / 2 - (225 / 2), 160, 20, GRAY);
    DrawRectangleRec(id, LIGHTGRAY);

    if (mouseOnId)
        DrawRectangleLines(id.x, id.y, id.width, id.height, BLUE);
    else
        DrawRectangleLines(id.x, id.y, id.width, id.height, DARKGRAY);

    DrawText(m_id.c_str(), id.x + 5, id.y + 8, 40, BLUE);

    if (mouseOnId)
    {
        if (m_id.size() < MAX_INPUT_CHARS)
        {
            if (((framesCounterLogin / 20) % 2) == 0)
                DrawText("_", id.x + 8 + MeasureText(m_id.c_str(), 40), id.y + 12, 40, BLUE);
        }
        else
            DrawText("Your name is too long", W_WIDTH / 2 - (225 / 2), 260, 15, GRAY);
    }
}

/**
 * @brief Affiche le mot de passe
 * 
 */
void Login::drawPasswordBlock()
{
    Rectangle password = getPasswordBlock();
    DrawText("PASSWORD", W_WIDTH / 2 - (225 / 2), 280, 20, GRAY);
    DrawRectangleRec(password, LIGHTGRAY);

    if (mouseOnPassword)
        DrawRectangleLines(password.x, password.y, password.width, password.height, BLUE);
    else
        DrawRectangleLines(password.x, password.y, password.width, password.height, DARKGRAY);

    DrawText(m_pass.c_str(), password.x + 5, password.y + 8, 40, BLUE);

    if (mouseOnPassword)
    {
        if (m_pass.size() < MAX_INPUT_CHARS)
        {
            if (((framesCounterPassword / 20) % 2) == 0)
                DrawText("_", password.x + 8 + MeasureText(m_pass.c_str(), 40), password.y + 12, 40, BLUE);
        }
        else
            DrawText("Your password is too long", W_WIDTH / 2 - (225 / 2), 360, 15, GRAY);
    }
}

/**
 * @brief Valide ou pas
 * 
 */
void Login::drawEnterBlock()
{
    Rectangle enter = getEnterBlock();
    DrawRectangleRec(enter, LIGHTGRAY);
    DrawText("Enter", enter.x + 30, enter.y + 20, 15, GRAY);

    if (CheckCollisionPointRec(GetMousePosition(), enter))
        DrawRectangleLines(enter.x, enter.y, enter.width, enter.height, BLUE);
    else
        DrawRectangleLines(enter.x, enter.y, enter.width, enter.height, DARKGRAY);

    if (!connexion)
    {
        DrawText("Error: Wrongs Logs", W_WIDTH / 2 - (225 / 2), 480, 20, RED);
    }
}

/**
 * @brief Dessine le bouton back
 * 
 */
void Login::drawBackBlock()
{
    Rectangle back = getBackBlock();
    DrawRectangleRounded(back, 0.5, 4, {255, 161, 0, 150});
    DrawText("Exit", back.x + back.width * 0.25, back.y + back.height * 0.27, 20, GRAY);

    if (mouseOnBack)
        DrawRectangleRoundedLines(back, 0.5, 4, 5, RED);

    else
        DrawRectangleRoundedLines(back, 0.5, 4, 5, ORANGE);
}

/**
 * @brief Run la fenetre de login
 * 
 * @param app 
 */
void Login::run(App *app)
{
    if (clicOnBack)
    {
        exit(0);
    }
    else if (clicOnEnter)
    {
        app->init(this->m_id);
        app->addHistory("Le moteur M1 etait alimenté");
        app->addHistory("Le moteur M2 etait alimenté");
        app->addHistory("Le moteur M3 etait alimenté");
        app->printHistory();
        app->setState(new Menu);
    }
    checkCollisionBlock();

    drawIdBlock();
    drawPasswordBlock();
    drawEnterBlock();
    drawBackBlock();
}