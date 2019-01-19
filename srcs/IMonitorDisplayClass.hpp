/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplayClass.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:11:49 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 14:31:38 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAYCLASS_HPP
# define IMONITORDISPLAYCLASS_HPP

#include <ncurses.h>
#include <iostream>
#include <sys/types.h>
#include <stdio.h>

class IMonitorDisplay {

public: 

    IMonitorDisplay(void); 
    IMonitorDisplay(IMonitorDisplay const & src); 
    ~IMonitorDisplay(void); 

	IMonitorDisplay &		operator=(IMonitorDisplay const & rhs);

    bool            getDisplayMode(void) const;
    void            init_display(void);
    bool            duration(void);
    std::clock_t    getStart(void);
    void            refreshTime(void);

private:

    bool         _displayMode;
    std::clock_t _start;
    WINDOW       *_win;
    time_t       _ctt;
    std::string  _cttStr;
};

#endif
