#include "Application.h"

#include <iostream>

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
			switch (App->Update())
			{
			case UPDATE_ERROR:
				state = MainState::EXIT;
				std::cout << "Error in application Update" << std::endl;
				break;

			case UPDATE_STOP:
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


