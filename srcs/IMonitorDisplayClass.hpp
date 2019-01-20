/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplayClass.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:11:49 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/20 16:38:21 by jgourdin         ###   ########.fr       */
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
    virtual ~IMonitorDisplay(void); 

    virtual void		refresh(void) = 0;
	virtual void		render(void) = 0;

private:
	IMonitorDisplay &		operator=(IMonitorDisplay const & rhs);
    IMonitorDisplay(IMonitorDisplay const &src);
};

#endif
