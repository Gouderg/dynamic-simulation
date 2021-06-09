#include "../header/Pendule.hpp"

#include <vector>

int main(int argc, char const *argv[])
{   

	Pendule pendule = Pendule(200,170);

    sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "Pendule Simple", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {							// Attente d'évènement.
			if(event.type == sf::Event::Closed) window.close();		// Fermeture de la fenetre.
		}
		// On nettoie notre écran.
		window.clear(sf::Color(25,25,100,80));
		
		// On affiche la position du pendule.
		pendule.draw(&window);
		pendule.update();

		window.display();

	}

    return 0;
}
