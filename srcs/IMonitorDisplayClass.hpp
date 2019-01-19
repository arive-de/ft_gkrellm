/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplayClass.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:11:49 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 15:04:54 by jgourdin         ###   ########.fr       */
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
    time_t          getCtt(void);
    WINDOW          *getWin(void);
    std::clock_t    getStart(void);
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
