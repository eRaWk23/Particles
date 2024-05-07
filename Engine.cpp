#include "Engine.h"

using namespace std;

Engine::Engine()
{
    RenderWindow m_Window;
    VideoMode::getDesktopMode();
}

void Engine::run()
{
    Clock clock;
    cout << "Starting Particle unit test....." << endl;
    Particle p(m_Window, 4, { (int)m_Window.getSize().x/2, (int)m_Window.getSize().y/2});
    p.unitTests();
    cout << "Unit test complete. Starting engine..." << endl;

    while(m_Window.isOpen())
    {
        clock.restart();
        input();
        update();
        draw();
    }
}

void Engine::input()
{
    Event event;

    while(m_Window.pollEvent(event))
    {
        if(event.KeyPressed == Keyboard::Escape)
        {
            m_Window.close();
        }
        else if (event.mouseButton.button ==  Mouse::Left)
        {
            
        }
    }
}

void Engine::update(float dtAsSeconds)
{
    
    {

    }
}

void Engine::draw()
{
    m_Window.clear();
}