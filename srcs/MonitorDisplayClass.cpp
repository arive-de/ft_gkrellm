/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorDisplayClass.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:11:58 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 15:15:29 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonitorDisplayClass.hpp"

MonitorDisplay::MonitorDisplay(void)
{
    
    this->_start = std::clock();

    // this->_ctt = time(0);
    return;
}

MonitorDisplay::MonitorDisplay(MonitorDisplay const & src) 
{
    *this = src;
    return;
}

MonitorDisplay::~MonitorDisplay(void)
{
    return;
}

bool            MonitorDisplay::getDisplayMode(void) const
{
    return this->_displayMode;
}

WINDOW          *MonitorDisplay::getWin(void)
{
    return this->_win;
}

std::clock_t    MonitorDisplay::getStart(void)
{
    return this->_start;
}

MonitorDisplay &	MonitorDisplay::operator=(MonitorDisplay const & rhs)
{
    if (&rhs != this)
    {
        this->_displayMode = rhs.getDisplayMode();
        this->_start = rhs._start;
    }
    return *this;
}


bool    MonitorDisplay::duration(void)
{
    std::clock_t duration = (std::clock() - this->_start);

    if (duration > 60000)
    {
        this->_start = std::clock();
        return true;
    }
    return false;
}

// void    MonitorDisplay::cpuModule( void )
// {
//     // this->_ctt = time(0);
//     // this->_cttStr = asctime(localtime(&this->_ctt));
//     // this->_cttStr = this->_cttStr.substr(0, this->_cttStr.size() - 1);
//     // attron(COLOR_PAIR(1));
//     // mvwprintw(stdscr, 1, 2, this->_cttStr.c_str());

//     // if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, reinterpret_cast<host_info_t>(&this->_cpuinfo), &this->_count) == KERN_SUCCESS)
// 	// {
// 		// this->_userTicks = this->_cpuinfo.cpu_ticks[0] - this->_prevUserTicks;
// 		// this->_cpuTicks = this->_cpuinfo.cpu_ticks[1] - this->_prevCpuTicks;
// 		// this->_idleTicks = this->_cpuinfo.cpu_ticks[2] - this->_prevIdleTicks;
// 		// this->_prevUserTicks = this->_cpuinfo.cpu_ticks[0];
// 		// this->_prevCpuTicks = this->_cpuinfo.cpu_ticks[1];
// 		// this->_prevIdleTicks = this->_cpuinfo.cpu_ticks[2];

// 		// mvwprintw(stdscr, 1, 2, "User : %.2f%%", static_cast<float>(this->_userTicks) / atoi(this->_coreCount.c_str()));
// 		// mvwprintw(stdscr, 2, 2, "Sys  : %.2f%%", static_cast<float>(this->_cpuTicks) / atoi(this->_coreCount.c_str()));
// 		// mvwprintw(stdscr, 3, 2, "Idle : %.2f%%", static_cast<float>(this->_idleTicks) / atoi(this->_coreCount.c_str()));
// 	// }

// }

void    MonitorDisplay::init_display(void) {

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
