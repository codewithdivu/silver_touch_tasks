#include <iostream>
#include <cstdlib>
#include <time.h>

double random01()
{
    return rand() / static_cast<double>(RAND_MAX);
}

int random06()
{
    while (true)
    {

        double randomValue = random01();

        int result = static_cast<int>(randomValue * 7);

        if (result <= 6)
        {
            return result;
        }
    }
}

int main()
{

    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < 10; ++i)
    {
        std::cout << random06() << " ";
    }

    return 0;
}
