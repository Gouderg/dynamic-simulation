#include "../header/Flock.hpp"
#include "../header/Pvector.hpp"


int main(int argc, char const *argv[])
{
    srand(time(NULL));

    // Création du nuage d'oiseau.
    Flock flock = Flock();

    sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Simulation de nuee d'oiseau", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {							// Attente d'évènement.
			if(event.type == sf::Event::Closed) window.close();		// Fermeture de la fenetre.
		}
		// On nettoie notre écran.
		window.clear(sf::Color(25,25,100,80));

        flock.update(&window);

		window.display();

	}
    return 0;
}
