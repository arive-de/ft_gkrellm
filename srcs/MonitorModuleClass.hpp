/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModuleClass.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:04:13 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 12:10:28 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORMODULECLASS_HPP
# define MONITORMODULECLASS_HPP

# include "IMonitorModuleClass.hpp"
# include <iostream>
#include <stdlib.h>

class MonitorModule : public IMonitorModule {

public: 

    typedef MonitorModule	t;
    MonitorModule(void); 
    MonitorModule(MonitorModule const & src); 
    ~MonitorModule(void); 
    
	MonitorModule &		operator=(MonitorModule const & rhs);

    int            getFlag() const;
    bool           getStart() const;

private:
    bool    _start;
    int     _flag;

};

#endif
