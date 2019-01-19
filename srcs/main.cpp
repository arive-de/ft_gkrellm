/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:40:25 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/19 11:56:44 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>

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

    while (1)
    {
        if (duration(&c_start))
        {
            wclear(win);
            box(win, 0, 0);
            start_color();			/* Start color 			*/
            init_pair(1, COLOR_RED, COLOR_BLACK);
            attron(COLOR_PAIR(1));
            mvwprintw(win, 0, 2, " date: ");
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