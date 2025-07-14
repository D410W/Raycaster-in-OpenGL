#include <SFML/Graphics.hpp>
#include <GL/gl.h>           // For core OpenGL functions

int main()
{
  // Create the SFML window
  sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL SFML Test");

  // Activate the window for OpenGL rendering
  window.setActive(true);

  // Set the clear color (dark blue in RGBA)
  // Values are between 0.0f and 1.0f
  glClearColor(0.1f, 0.1f, 0.3f, 1.0f); // R, G, B, Alpha

  // Main loop
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) window.close();
    }

    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Display the window content
    window.display();
  }

  return 0;
}
