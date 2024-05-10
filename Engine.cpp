#include "Engine.h"

using namespace std;

Engine::Engine()
{
    VideoMode customMode(1440, 1080);
    m_Window.create(customMode, "Particle");
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
        Time t = clock.restart();
        input();
        update(t.asSeconds());
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
            //Vector2f mouseClickPosition(event.mouseButton.x, event.mouseButton.y);

            for (int i = 0; i < 5; i++)
            {
                int num = rand() % 26 + 25;
                Particle particles(m_Window, num, { event.mouseButton.x, event.mouseButton.y});
                m_particles.push_back(particles);
            }
        }
    }
}

void Engine::update(float dtAsSeconds)
{
    
    {
        for(auto iter = m_particles.begin(); iter != m_particles.end();)
        {
            if(iter->getTTL() > 0.0)
            {
                update(dtAsSeconds);
                iter++;
            }
            else
            {
                iter = m_particles.erase(iter);
            }
        }
    }
}

void Engine::draw()
{
    m_Window.clear();

    for (const auto &part: m_particles)
    {
        m_Window.draw(part);
    }

    m_Window.display();
}