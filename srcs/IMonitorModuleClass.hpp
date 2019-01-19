/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModuleClass.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:04:13 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 12:10:28 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULECLASS_HPP
# define IMONITORMODULECLASS_HPP

# include <iostream>

class IMonitorModule {

public: 

    typedef IMonitorModule	t;
    IMonitorModule(void); 
    IMonitorModule(IMonitorModule const & src); 
    ~IMonitorModule(void); 
    
	IMonitorModule &		operator=(IMonitorModule const & rhs);

    int            getFlag() const;
    bool           getStart() const;

private:
    bool    _start;
    int     _flag;

};

#endif
