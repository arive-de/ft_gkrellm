/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:40:25 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/19 12:35:19 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include <stdarg.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

bool duration(std::clock_t *_start)
{
    std::clock_t duration = (std::clock() - *_start);

    if (duration > 60000)
    {
        *_start = std::clock();
        return true;
    }
    return false;
}

int     main( void ) {

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    
    int keycode;

    WINDOW *win = newwin(40, 150, 0, 0);

    keypad(win, TRUE);
    nodelay(win, TRUE);

    std::clock_t c_start = std::clock();

    time_t ctt = time(0);

    std::string str;
    while (1)
    {
        if (duration(&c_start))
        {
            ctt = time(0);
            wclear(win);
            box(win, 0, 0);
            start_color();
            init_pair(1, COLOR_RED, COLOR_BLACK);
            attron(COLOR_PAIR(1));
            str = asctime(localtime(&ctt));
            str = str.substr(0, str.size() - 1);
            mvwprintw(win, 1, 2, str.c_str());
            wrefresh(win);
        }
        if ((keycode = wgetch(win)) == ERR)
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
    return 0;
}