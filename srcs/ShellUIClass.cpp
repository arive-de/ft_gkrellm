/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShellUIClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:56:47 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/20 20:22:54 by arive-de         ###   ########.fr       */
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
    this->_modules.push_back(new NetworkModule());
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
    this->_winInfos = subwin(stdscr, 25, COLS - 2, 5, 0);
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

    mvwprintw(this->_winInfos, 3, 5, (this->_modules.at(0)->getInfos().c_str()));
    mvwprintw(this->_winInfos, 6, 5, (this->_modules.at(1)->getInfos().c_str()));
    mvwprintw(this->_winInfos, 9, 5, (this->_modules.at(2)->getInfos().c_str()));
    mvwprintw(this->_winInfos, 12, 5, (this->_modules.at(3)->getInfos().c_str()));
    mvwprintw(this->_winInfos, 15, 5, (this->_modules.at(4)->getInfos().c_str()));
    mvwprintw(this->_winInfos, 18, 5, (this->_modules.at(5)->getInfos().c_str()));
    mvwprintw(this->_winInfos, 21, 5, (this->_modules.at(6)->getInfos().c_str()));

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
    }
    endwin();
}
