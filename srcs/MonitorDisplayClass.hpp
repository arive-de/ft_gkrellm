/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorDisplayClass.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:11:49 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 15:14:27 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORDISPLAYCLASS_HPP
# define MONITORDISPLAYCLASS_HPP

#include <ncurses.h>
#include <iostream>
#include <sys/types.h>
#include <stdio.h>
# include "IMonitorDisplayClass.hpp"

class MonitorDisplay : public IMonitorDisplay {

public: 

    MonitorDisplay(void); 
    MonitorDisplay(MonitorDisplay const & src); 
    ~MonitorDisplay(void); 

	MonitorDisplay &		operator=(MonitorDisplay const & rhs);

    bool            getDisplayMode(void) const;
    void            init_display(void);
    bool            duration(void);
    std::clock_t    getStart(void);
    time_t          getCtt(void);
    WINDOW          *getWin(void);
    std::string     getCttStr(void);
    void            refreshTime(void);

protected:

    bool         _displayMode;
    std::clock_t _start;
    WINDOW       *_win;
    time_t       _ctt;
    std::string  _cttStr;
};

#endif
