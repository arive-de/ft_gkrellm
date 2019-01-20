/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShellUIClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:56:37 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/20 19:51:31 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELLUICLASS_HPP
# define SHELLUICLASS_HPP

# include "IMonitorDisplayClass.hpp"
# include "IMonitorModuleClass.hpp"
# include <iostream>
# include <vector>
# include <ncurses.h>
# include "OsInfosModule.hpp"
# include "DatetimeModule.hpp"
# include "HostnameModule.hpp"
# include "CpuModule.hpp"
# include "UsernameModule.hpp"
# include "RamModule.hpp"

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
    void   printModules(void);


private:

    std::vector<IMonitorModule*>	_modules;
    WINDOW *_winTitle;
    WINDOW *_winInfos;
    std::clock_t _start;

};

#endif
