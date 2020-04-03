#include "../include/State.h"

/**
 * @brief Construct a new State:: State object
 * 
 * @param whidth 
 * @param height 
 * @param title 
 */
State::State(float whidth, float height, char *title) : W_WIDTH(whidth), W_HEIGHT(height), W_TITLE(title)
{
}

/**
 * @brief Destroy the State:: State object
 * 
 */
State::~State()
{
}