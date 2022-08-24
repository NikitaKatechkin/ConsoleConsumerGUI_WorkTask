#include "ConsoleMenu.h"

Menu::Menu():
    m_state(ConsumerGUIState::Initial_State),
    m_stateHandler(new InitialState()),
    m_isExitInitiated(false)
{
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

void Menu::showStateServiceInfo()
{
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~SERVICE INFO~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << std::endl;

    switch (m_state)
    {
    case ConsumerGUIState::Initial_State:
    {
        std::cout << "<NO SERVICE DATA AVAILABLE>" << std::endl;

        break;
    }
    case ConsumerGUIState::Updated_State:
    {
        std::cout << "Interfaces list: " << "<NO INTERFACE AVAILABLE>" << std::endl;

        break;
    }
    case ConsumerGUIState::Connected_State:
    {
        std::cout << "Active interface: " << "<DEFAULT INTERACE>" << std::endl;
        std::cout << "Devices list: " << "<NO DEVICE AVAILABLE>" << std::endl;

        break;
    }
    case ConsumerGUIState::Subscribed_State:
    {
        std::cout << "Subscribed device: " << "<DEFAULT DEVICE>" << std::endl;
        std::cout << "Device data: " << "<NO DATA RECIEVED>" << std::endl;

        break;
    }
    case ConsumerGUIState::Exit_State:
    {
        std::cout << "<NO SERVICE DATA AVAILABLE>" << std::endl;

        break;
    }
    default:
    {
        std::cout << "<NO SERVICE DATA AVAILABLE>" << std::endl;

        break;
    }
    }

    std::cout << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
}

unsigned int Menu::processUserInput()
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
            clearConsoleScreen();

            showCurrentStateOptions();

            std::cout << "Input index of command (bad input or index out of bounds was provided):";
        }
    }

    return userInput;
}

void Menu::clearConsoleScreen()
{
    std::cout << std::flush;
    system("CLS");
}

void Menu::Update(const unsigned int option)
{
    m_state = m_stateHandler->Update(option);

    if (m_stateHandler != nullptr)
    {
        delete m_stateHandler;
    }

    switch (m_state)
    {
    case ConsumerGUIState::Initial_State:
    {   
        m_stateHandler = new InitialState();

        break;
    }
    case ConsumerGUIState::Updated_State:
    {
        m_stateHandler = new UpdatedState();

        break;
    }
    case ConsumerGUIState::Connected_State:
    {
        m_stateHandler = new ConnectedState();

        break;
    }
    case ConsumerGUIState::Subscribed_State:
    {
        m_stateHandler = new SubscribedState();

        break;
    }
    case ConsumerGUIState::Exit_State:
    {
        m_stateHandler = new InitialState();
        m_isExitInitiated = true;

        break;
    }
    default:
    {
        break;
    }
    }
}

bool Menu::isExitInitiated()
{
    return m_isExitInitiated;
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
    std::cout << "~~~~~~~~~~~~~~~~~~~~AVAILABLE OPTIONS~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << std::endl;

    for (size_t optionIndex = 0; optionIndex < m_optionsForStates[state].size(); optionIndex++)
    {
        std::cout << optionIndex << ") " << m_optionsForStates[state][optionIndex] << std::endl;
    }

    std::cout << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
}
