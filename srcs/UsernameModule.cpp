/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UsernameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:50 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 17:38:31 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UsernameModule.hpp"

UsernameModule::UsernameModule(void) {

    this->_username = getenv("USER");
}

UsernameModule::UsernameModule(UsernameModule const & src) {

    *this = src;
}

UsernameModule::~UsernameModule(void) {

}


UsernameModule & UsernameModule::operator=(UsernameModule const & rhs) {

    this->_username = rhs._username;
    return *this;
}

std::string       UsernameModule::getInfos(void)
{
    return this->_username;
}
