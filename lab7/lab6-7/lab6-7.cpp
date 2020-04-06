#include <iostream>
#include "Repo.h"
#include "UI.h"
#include "Tests.h"
using namespace std;

int main()
{

    tests();
    UI ui;
    ui.run();
    return 0;
}
