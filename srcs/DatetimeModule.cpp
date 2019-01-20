/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DatetimeModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:25:00 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 20:04:15 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DatetimeModule.hpp"

DatetimeModule::DatetimeModule(void) {

    time_t ctt = time(0);

    this->_datetime = asctime(localtime(&ctt));
    this->_datetime += "Date & Time: ";
    this->_datetime += this->_datetime.substr(0, this->_datetime.size() - 1);
}

DatetimeModule::DatetimeModule(DatetimeModule const & src) {

    *this = src;
}

DatetimeModule::~DatetimeModule(void) {

}


DatetimeModule & DatetimeModule::operator=(DatetimeModule const & rhs) {

    this->_datetime = rhs._datetime;
    return *this;
}

std::string       DatetimeModule::getInfos(void)
{
    time_t ctt = time(0);

    this->_datetime = asctime(localtime(&ctt));
    this->_datetime = this->_datetime.substr(0, this->_datetime.size() - 1);
    return this->_datetime;
}