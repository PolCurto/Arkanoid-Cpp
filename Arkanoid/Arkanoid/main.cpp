#include "Application.h"

#include <iostream>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

Application* App = nullptr;

enum class MainState
{
	Start,
	Update,
	Finish,
	Exit
};

int main()
{
	App = new Application();
	sf::Clock clock;
	float deltaTime;
	MainState state = MainState::Start;
	while (state != MainState::Exit)
	{
		switch (state)
		{
		case MainState::Start:
			if (App->Start()) 
			{
				state = MainState::Update;
			}
			else 
			{
				state = MainState::Exit;
				std::cout << "Error in application Start" << std::endl;
			}
			break;

		case MainState::Update:
			deltaTime = clock.restart().asSeconds();
			switch (App->Update(deltaTime))
			{
			case Globals::UpdateState::Error:
				state = MainState::Exit;
				std::cout << "Error in application Update" << std::endl;
				break;

			case Globals::UpdateState::Stop:
				state = MainState::Finish;
				break;
			}
			break;

		case MainState::Finish:
			if (!App->Close()) std::cout << "Error in application Close" << std::endl;
			state = MainState::Exit;	
			break;
		}
	}

	delete App;

	return 0;
}


