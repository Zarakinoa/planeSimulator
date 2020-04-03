#ifndef APP_H
#define APP_H
#include <boost/shared_ptr.hpp>
#include <raylib.h>
#include <iostream>
#include "State.h"

#include <nlohmann/json.hpp>
using json = nlohmann::json;
#include <string>
#include <fstream>
#include <ctime>

class App
{
private:
    std::string m_id;
    json j;
    int number;
    int rate;
    boost::shared_ptr<State> currentState;

public:
    void initWindow();
    App();
    void setState(State *newState);
    void run();

    void init(std::string id);
    void printHistory();
    void checkRating();

    void zero();
    void addRating(int rate);
    void addDate();
    void addHistory(std::string str);
    void printJson();
};

#endif