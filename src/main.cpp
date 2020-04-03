#include "../include/App.h"
#include <time.h>

/**
 * @brief Main Application
 * 
 * @return int 
 */
int main()
{
   // Seed
   srand(time(NULL));

   App app;

   app.run();

   return 0;
}
