#include "ConsoleMenu.h"

Menu::Menu()
{
	m_state = ConsumerGUIState::Initial_State;

    ExtractOptionsForStates();
}

void Menu::showOptionsForAllStates()
{
    for (size_t state = 0; state < NUMBER_OF_STATES; state++)
    {
        ConsumerGUIState tmpState = ConsumerGUIState(state);

        ShowOptionsForState(tmpState);
    }
}

void Menu::showCurrentStateOptions()
{
    ShowOptionsForState(m_state);
}

void Menu::processUserInput()
{
    std::cout << "Input index of command: ";

    bool isInputValid = false;

    unsigned int userInput = 0;
    while (isInputValid == false)
    {
        std::cin >> userInput;

        isInputValid = ((std::cin.fail() == false) && 
                        ((userInput >= 0) && (userInput < m_optionsForStates[m_state].size())));

        if (isInputValid == false)
        {
            system("CLS");

            showCurrentStateOptions();

            std::cout << "Input index of command (wrong index or index out of bounds was provided):";
        }
    }
}

void Menu::ExtractOptionsForStates()
{
    std::string allStateOptions;
    std::ifstream optionsConfigFile("OptionsConfig.txt");

    if (optionsConfigFile.is_open())
    {
        for (size_t state = 0; state < NUMBER_OF_STATES; state++)
        {
            if (!(std::getline(optionsConfigFile, allStateOptions)))
            {
                std::cerr << "Not enough options were provided in OptionsConfig.txt" << std::endl;
                break;
            }

            std::vector<std::string> options;

            std::string option = "";
            for (size_t charIndex = 0; charIndex < allStateOptions.size(); charIndex++)
            {
                if (allStateOptions[charIndex] == '|')
                {
                    option.pop_back();

                    options.push_back(option);

                    option = "";

                    charIndex++;
                }
                else
                {
                    option.push_back(allStateOptions[charIndex]);
                }
            }
            options.push_back(option);

            m_optionsForStates.insert({ static_cast<ConsumerGUIState>(state), options });
        }

        optionsConfigFile.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
}

void Menu::ShowOptionsForState(const ConsumerGUIState& state)
{
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << std::endl;

    std::cout << "Available options: (input index of command to execute it)" << std::endl;
    std::cout << std::endl;

    for (size_t optionIndex = 0; optionIndex < m_optionsForStates[state].size(); optionIndex++)
    {
        std::cout << optionIndex << ") " << m_optionsForStates[state][optionIndex] << std::endl;
    }

    std::cout << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
}
