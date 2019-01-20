/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UsernameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:50 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 20:04:53 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UsernameModule.hpp"

UsernameModule::UsernameModule(void) {

    this->_username += "Username: ";
    this->_username += getenv("USER");
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
