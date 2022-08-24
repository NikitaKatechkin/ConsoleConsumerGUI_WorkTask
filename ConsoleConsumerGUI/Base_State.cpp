#include "Base_State.h"

#include <iostream>
#include <fstream>

ConsumerGUIState BaseState::Exit()
{
    return ConsumerGUIState::Exit_State;
}

void BaseState::ShowOptions()
{
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~AVAILABLE OPTIONS~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << std::endl;

    for (size_t optionIndex = 0; optionIndex < m_optionsList.size(); optionIndex++)
    {
        std::cout << optionIndex << ") " << m_optionsList[optionIndex] << std::endl;
    }

    if (m_optionsList.empty() == true)
    {
        std::cout << "<NO OPTIONS AVAILABLE>";
    }

    std::cout << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
}

void BaseState::LoadOptions()
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

            m_optionsList.clear();
            m_optionsList.shrink_to_fit();

            std::string option = "";
            for (size_t charIndex = 0; charIndex < allStateOptions.size(); charIndex++)
            {
                if (allStateOptions[charIndex] == '|')
                {
                    option.pop_back();

                    m_optionsList.push_back(option);

                    option = "";

                    charIndex++;
                }
                else
                {
                    option.push_back(allStateOptions[charIndex]);
                }
            }
            m_optionsList.push_back(option);
        }

        optionsConfigFile.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
}
