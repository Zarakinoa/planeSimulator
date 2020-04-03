#include <raylib.h>
#include "../include/App.h"
#include "../include/Login.h"

/**
 * @brief Initialisation de la fenêtre de connexion
 * 
 */
void App::initWindow()
{
    InitWindow(400, 600, "App");
}

/**
 * @brief Construct a new App:: App object
 * 
 */
App::App() : currentState(new Login)
{
    // this->rate = 0;
}

/**
 * @brief Actuellement connecté
 * 
 * @param newState 
 */
void App::setState(State *newState)
{
    currentState.reset(newState);
}

/**
 * @brief Initialise un historique
 *
 */
void App::init(std::string id)
{
    std::ifstream i("file.json");
    i >> this->j;

    this->m_id = id;

    this->number = this->j[this->m_id]["date"].size();
}

/**
 * @brief Affiche l'historique de l'utilisateur connecté
 *
 */
void App::printHistory()
{
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
    std::string str(buffer);
    std::cout << std::endl;
    std::cout << "We are the " << str << std::endl;
    std::cout << "History :" << std::endl;

    int size = this->number;

    if (size == 0)
    {
        std::cout << "No history" << std::endl;
        return;
    }

    while (size > 0)
    {
        size--;
        std::cout << "Date : " << this->j[this->m_id]["date"][size] << std::endl;
        std::cout << "Rating : " << this->j[this->m_id]["rating"][size] << std::endl;

        std::cout << "App : " << std::endl;
        int historySize = this->j[this->m_id]["history"][size].size();
        int i = 0;
        while (i < historySize)
        {
            std::cout << "\t" << i + 1 << " - " << this->j[this->m_id]["history"][size][i] << std::endl;
            i++;
        }
        std::cout << std::endl
                  << std::endl;
    }
}

/**
 * @brief Ajoute une note
 *
 * @param rate
 */
void App::addRating(int rate)
{
    this->rate = this->rate + rate;
}

/**
 * @brief Vérifie la note
 *
 */
void App::checkRating()
{
    int size = this->j[this->m_id]["rating"].size();
    // cond qui test si on a deja ajouter des point
    if (size == this->number)
    {
        this->rate = 0;
    }
}

/**
 * @brief Attribue un zéro
 *
 */
void App::zero()
{
    this->rate = rand() % 11 + 1;
}

/**
 * @brief Met à jour la date
 *
 */
void App::addDate()
{
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
    std::string str(buffer);
    this->j[this->m_id]["date"][this->number] = str;
}

/**
 * @brief Met à jour l'historique
 *
 * @param str
 */
void App::addHistory(std::string str)
{
    int size = this->j[this->m_id]["history"][this->number].size();
    this->j[this->m_id]["history"][this->number][size] = str;
}

/**
 * @brief Crée le Json
 *
 */
void App::printJson()
{
    this->j[this->m_id]["rating"][this->number] = this->rate;
    std::ofstream o("file.json");
    o << this->j;
}

/**
 * @brief Lancement de l'application
 * 
 */
void App::run()
{
    this->initWindow();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);
        currentState->run(this);
        EndDrawing();
    }

    CloseWindow();
}
