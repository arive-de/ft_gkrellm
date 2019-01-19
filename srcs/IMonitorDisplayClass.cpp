/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplayClass.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:11:58 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 15:13:31 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplayClass.hpp"

IMonitorDisplay::IMonitorDisplay(void)
{
    this->_start = std::clock();
    this->_ctt = time(0);
    return;
}

IMonitorDisplay::IMonitorDisplay(IMonitorDisplay const & src) 
{
    *this = src;
    return;
}

IMonitorDisplay::~IMonitorDisplay(void)
{
    return;
}

bool                IMonitorDisplay::getDisplayMode(void) const
{
    return this->_displayMode;
}

time_t          IMonitorDisplay::getCtt(void)
{
    return this->_ctt;
}

WINDOW          *IMonitorDisplay::getWin(void)
{
    return this->_win;
}

std::clock_t    IMonitorDisplay::getStart(void)
{
    return this->_start;
}

std::string     IMonitorDisplay::getCttStr(void)
{
    return this->_cttStr;
}

IMonitorDisplay &	IMonitorDisplay::operator=(IMonitorDisplay const & rhs)
{
    if (&rhs != this)
    {
        this->_displayMode = rhs.getDisplayMode();
        this->_start = rhs._start;
        this->_ctt = rhs._ctt;
        this->_win = rhs._win;
        this->_cttStr = rhs._cttStr;
    }
    return *this;
}


bool    IMonitorDisplay::duration(void)
{
    std::clock_t duration = (std::clock() - this->_start);

    if (duration > 60000)
    {
        this->_start = std::clock();
        return true;
    }
    return false;
}

void    IMonitorDisplay::refreshTime( void )
{
    this->_ctt = time(0);
    this->_cttStr = asctime(localtime(&this->_ctt));
    this->_cttStr = this->_cttStr.substr(0, this->_cttStr.size() - 1);
    attron(COLOR_PAIR(1));
    mvwprintw(stdscr, 1, 2, this->_cttStr.c_str());
}

std::clock_t    IMonitorDisplay::getStart(void)
{
    return this->_start;
}

void    IMonitorDisplay::init_display(void) {

    initscr();
    start_color();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    // timeout(50);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);

    this->_win = subwin(stdscr, LINES, 150, 0, 0);
    box(this->_win, ACS_VLINE, ACS_HLINE);

}
