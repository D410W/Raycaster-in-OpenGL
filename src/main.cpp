#include <SFML/Graphics.hpp>
#include <GL/gl.h>           // For core OpenGL functions
#include <cmath>
#include <iostream>

float timeMultiplier = 1.0f;
float getElapsedTime(sf::Clock clock){
  float time = clock.getElapsedTime().asSeconds() * timeMultiplier;
  return (1.0f + std::sin(time * 3.141592f))*0.5;
}

int main()
{
  // Create the SFML window
  sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL SFML Test");
  // Activate the window for OpenGL rendering
  window.setActive(true);
  window.setVerticalSyncEnabled(true);

  sf::Clock clock;
  timeMultiplier = 0.5f;
  // std::cin >> timeMultiplier;
  
  // Main loop
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) window.close();
    }

    glClearColor(getElapsedTime(clock), 1 - getElapsedTime(clock), getElapsedTime(clock), 1.0f);
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Display the window content
    window.display();
  }

  return 0;
}
