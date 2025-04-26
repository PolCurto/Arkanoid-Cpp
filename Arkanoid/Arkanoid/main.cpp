#include "Application.h"

#include <iostream>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

Application* App = nullptr;

enum class MainState
{
	START,
	UPDATE,
	FINISH,
	EXIT
};

int main()
{
	App = new Application();
	sf::Clock clock;
	float deltaTime;
	MainState state = MainState::START;
	while (state != MainState::EXIT)
	{
		switch (state)
		{
		case MainState::START:
			if (App->Start()) 
			{
				state = MainState::UPDATE;
			}
			else 
			{
				state = MainState::EXIT;
				std::cout << "Error in application Start" << std::endl;
			}
			break;

		case MainState::UPDATE:
			deltaTime = clock.restart().asSeconds();
			switch (App->Update(deltaTime))
			{
			case Globals::UpdateState::Error:
				state = MainState::EXIT;
				std::cout << "Error in application Update" << std::endl;
				break;

			case Globals::UpdateState::Stop:
				state = MainState::FINISH;
				break;
			}
			break;

		case MainState::FINISH:
			if (!App->Close()) std::cout << "Error in application Close" << std::endl;
			state = MainState::EXIT;	
			break;
		}
	}

	delete App;

	return 0;
}


