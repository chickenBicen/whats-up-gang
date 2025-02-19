#include <SFML/Graphics.hpp>
#include <iostream>
#include "Student.h"

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Student Display");

    // Create a button
    sf::RectangleShape button(sf::Vector2f(200, 50));
    button.setFillColor(sf::Color::Green);
    button.setPosition(300, 275);

    // Create a text to display on the button
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }
    sf::Text buttonText("Create Student", font, 20);
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setPosition(320, 290);

    // Create a text to display student details
    sf::Text studentText("", font, 20);
    studentText.setFillColor(sf::Color::Black);
    studentText.setPosition(50, 50);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    // Create a student object
                    Student student("Alice", "85 90 78");
                    studentText.setString("Student: " + student.getName() + "\nGrades: " + student.toString());
                }
            }
        }

        // Clear the window
        window.clear(sf::Color::White);

        // Draw the button and text
        window.draw(button);
        window.draw(buttonText);
        window.draw(studentText);

        // Update the window
        window.display();
    }

    return 0;
}
