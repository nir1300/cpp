#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info( void )
{
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n" << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ ERRROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain( std::string level )
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*actions[4])() = {&Harl::debug, &Harl::info,  &Harl::warning, &Harl::error};
    int i;
    for (i = 0; i < 4; i++)
    {
        if (level == levels[i])
            break;
    }
    switch (i)
    {
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
        case 0:
            (this->*actions[0])();
            /* FALLTHROUGH */
        case 1:
            (this->*actions[1])();
            /* FALLTHROUGH */
        case 2:
            (this->*actions[2])();
            /* FALLTHROUGH */
        case 3:
            (this->*actions[3])();
            break;
    }
}