#include <iostream>
#include <ctime>

class Blend 
{
public:
    void blendJuice() 
    {
        std::cout << "Blending juice..." << std::endl;
        int start = std::time(0);
        while (std::time(0) - start < 5) {}
    }
};

class Grind 
{
public:
    void grindJuice() 
    {
        std::cout << "Grinding juice..." << std::endl;
        int start = std::time(0);
        while (std::time(0) - start < 5) {}
    }
};

class JuiceMaker 
{
public:
    void blendJuice() 
    {
        b.blendJuice();
    }
    void grindJuice() 
    {
        g.grindJuice();
    }
private:
    Blend b;
    Grind g;
};

int main() 
{
    JuiceMaker jm;
    jm.blendJuice();
    jm.grindJuice();
    return 0;
}
