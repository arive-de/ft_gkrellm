/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShellUIClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:56:37 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/20 17:45:48 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELLUICLASS_HPP
# define SHELLUICLASS_HPP

# include "IMonitorDisplayClass.hpp"
# include <iostream>
# include <ncurses.h>

class ShellUI: public IMonitorDisplay
{

public: 

    ShellUI(void); 
    ShellUI(ShellUI const & src); 
    virtual ~ShellUI(void); 

	ShellUI &		operator=(ShellUI const & rhs);

    void    refresh(void);
    void    render(void);

    void   init_display(void);
    void   run_shellUI(void);
    bool   duration(void);


private:

    WINDOW *_winTitle;
    WINDOW *_winInfos;
    std::clock_t _start;

};

#endif
