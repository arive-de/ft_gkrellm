/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShellUIClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:56:47 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/20 20:06:52 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShellUIClass.hpp"
#include <iostream>

ShellUI::ShellUI(void)
{
	this->_modules.push_back(new HostnameModule());
	this->_modules.push_back(new UsernameModule());
	this->_modules.push_back(new DatetimeModule());
	this->_modules.push_back(new CpuModule());
    this->_modules.push_back(new OsInfosModule());
    this->_modules.push_back(new RamModule());
    return;
}

ShellUI::ShellUI(ShellUI const & src) 
{
    *this = src;
    return;
}

ShellUI::~ShellUI(void)
{
    return;
}

ShellUI &	ShellUI::operator=(ShellUI const & rhs)
{
    if (this != &rhs)
    {
        this->_winTitle = rhs._winTitle;
    }
    return *this;
}

void    ShellUI::render(void) {

}

void    ShellUI::refresh(void) {

}

// void    ShellUI::refreshCpuUsage( void )
// {
//     if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, reinterpret_cast<host_info_t>(&this->_cpuinfo), &this->_count) == KERN_SUCCESS)
// 	{
// 		this->_userTicks = this->_cpuinfo.cpu_ticks[0] - this->_prevUserTicks;
// 		this->_cpuTicks = this->_cpuinfo.cpu_ticks[1] - this->_prevCpuTicks;
// 		this->_idleTicks = this->_cpuinfo.cpu_ticks[2] - this->_prevIdleTicks;
// 		this->_prevUserTicks = this->_cpuinfo.cpu_ticks[0];
// 		this->_prevCpuTicks = this->_cpuinfo.cpu_ticks[1];
// 		this->_prevIdleTicks = this->_cpuinfo.cpu_ticks[2];

// 		mvwprintw(stdscr, 1, 2, "User : %.2f%%", static_cast<float>(this->_userTicks) / atoi(this->_coreCount.c_str()));
// 		mvwprintw(stdscr, 2, 2, "Sys  : %.2f%%", static_cast<float>(this->_cpuTicks) / atoi(this->_coreCount.c_str()));
// 		mvwprintw(stdscr, 3, 2, "Idle : %.2f%%", static_cast<float>(this->_idleTicks) / atoi(this->_coreCount.c_str()));
// 	}

// }

// std::clock_t    IMonitorDisplay::getStart(void)
// {
//     return this->_start;
// }

void    ShellUI::init_display(void) {

    initscr();
    start_color();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);

    this->_winTitle = subwin(stdscr, 5, COLS - 2, 0, 0);
    this->_winInfos = subwin(stdscr, 50, COLS - 2, 5, 0);
    box(this->_winTitle, ACS_VLINE, ACS_HLINE);
    box(this->_winInfos, ACS_VLINE, ACS_HLINE);

    attron(COLOR_PAIR(2));
    mvwprintw(stdscr, 2, COLS / 2 - 20.5, "FT_GKRELLM crafted by arive-de & jgourdin");

    run_shellUI();

}

bool    ShellUI::duration()
{
    std::clock_t duration = (std::clock() - this->_start);

    if (duration > 60000)
    {
        this->_start = std::clock();
        return true;
    }
    return false;
}

void    ShellUI::printModules(void) {

    for (int i=0; i<6; i++)
    {
        mvwprintw(this->_winInfos, i + 3, 5, (this->_modules.at(i)->getInfos().c_str()));
    }
}


void    ShellUI::run_shellUI(void) {

    int keycode;

    while (1)
    {
        if (duration())
        {
            printModules();
            wrefresh(this->_winInfos);
        }
        if ((keycode = getch()) == ERR)
            continue;
        else if (keycode == 'p')
        {
            std::cout << "previous" << std::endl;
        }
        else if (keycode == 'n')
        {
            std::cout << "next" << std::endl;           
        }
    }
    endwin();
}
