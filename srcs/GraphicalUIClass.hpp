/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicalUIClass.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:55:34 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 14:56:27 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICALUICLASS_HPP
# define GRAPHICALUICLASS_HPP

# include <iostream>
# include "IMonitorDisplayClass.hpp"

class GraphicalUI : public IMonitorDisplay
{

public: 

    typedef GraphicalUI	t;
    GraphicalUI(void); 
    GraphicalUI(GraphicalUI const & src); 
    ~GraphicalUI(void); 

	GraphicalUI &		operator=(GraphicalUI const & rhs);


private:

};

#endif
