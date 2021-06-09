#include "../header/Double.hpp"

int main(int argc, char const *argv[])
{   
	std::vector<Double> double_pendule;
	for (int i = 0; i < NB_DOUBLE; i++) {
		Double t = Double(-110,150+i);
		double_pendule.push_back(t);
	}

    
    sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "Pendule Double", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {							// Attente d'évènement.
			if(event.type == sf::Event::Closed) window.close();		// Fermeture de la fenetre.
		}
		// On nettoie notre écran.
		window.clear(sf::Color(25,25,100,80));
		
		// On parcours chaque double pendule.
		for (auto doublet : double_pendule) {
			// On calcule les nouvelles accélérations du doublet
			doublet.update();

			// On affiche les 2 pendules du doublets
			for (auto elt : doublet.getPendules()) {
				elt->draw(&window);
			}
		}
		window.display();

	}

    return 0;
}
