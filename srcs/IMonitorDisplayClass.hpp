/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplayClass.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:11:49 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 12:13:58 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAYCLASS_HPP
# define IMONITORDISPLAYCLASS_HPP

# include <iostream>

class IMonitorDisplay {

public: 

    IMonitorDisplay(void); 
    IMonitorDisplay(IMonitorDisplay const & src); 
    ~IMonitorDisplay(void); 

	IMonitorDisplay &		operator=(IMonitorDisplay const & rhs);

    bool    getDisplayMode(void) const;


private:
    bool    _displayMode;

};

#endif
