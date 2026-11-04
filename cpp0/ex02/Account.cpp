#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <ctime>
#include <cstdio>
#include "Account.hpp"

// to compare 2 files (only 2nd column): 
// ./account > mine.log
// diff <(cut -d' ' -f2 mine.log) <(cut -d' ' -f2 test.log)

// set static vars to start value before constructor
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// constructor
Account::Account(int initial_deposit)
{
    this->_accountIndex = Account::_nbAccounts++; // this line adds nbaccounts to accountIndex AND increments nbAccounts by 1 afterwards
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

// deconstructor
Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

// need to declare function with Account:: because this is a class function
int	Account::getNbAccounts( void )
{
    return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
   Account::_displayTimestamp();
   std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}


void	Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
    << ";p_amount:" << this->_amount
    << ";deposit:" << deposit << ";amount:" 
    << this->_amount+deposit << ";nb_deposits:" 
    << this->_nbDeposits+1 << std::endl;

    this->_amount+= deposit;
    this->_nbDeposits++;

    Account::_totalAmount+= deposit;
    Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (withdrawal > this->_amount)
    {
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex
        << ";p_amount:" << this->_amount
        << ";withdrawal:refused" << std::endl;
        return false;
    }
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
        << ";p_amount:" << this->_amount
        << ";withdrawal:" << withdrawal << ";amount:" 
        << this->_amount-withdrawal << ";nb_withdrawals:" 
        << this->_nbWithdrawals+1 << std::endl;


    this->_amount -= withdrawal;
    this->_nbWithdrawals++;

    Account::_totalAmount-=withdrawal;
    Account::_totalNbWithdrawals++;
    return true;
}

// this functions exists so i can check the amount outside of the class function 
// like so:
// Account a(100);
// int amount = a.checkAmount();
int		Account::checkAmount( void ) const
{
    return this->_amount;
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    char buffer[80];
    std::time_t raw;
    std::time(&raw);
    std::tm* local = std::localtime(&raw);
    std::strftime(buffer, 80, "%Y%m%d_%H%M%S", local);
    std::cout << "[" << buffer << "] ";
}


