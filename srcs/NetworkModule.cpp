/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:57 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 17:24:45 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"

NetworkModule::NetworkModule(void) {
    this->_bufferlen = BUFFER_LEN;
    this->_network = getStdOut("sysctl -n kern.Network");
}

NetworkModule::NetworkModule(NetworkModule const & src) {

    *this = src;
}

NetworkModule::~NetworkModule(void) {


}

NetworkModule & NetworkModule::operator=(NetworkModule const & rhs) {

    this->_network = rhs._network;
    return *this;
}

std::string                NetworkModule::getInfos(void)
{
    return this->_network;
}

std::string           NetworkModule::getStdOut(std::string cmd)
{
    std::string data;
    FILE * stream;

    cmd.append(" 2>&1");


    stream = popen(cmd.c_str(), "r");
    if (stream)
    {
        while (!feof(stream))
            if (fgets(this->_buffer, this->_bufferlen, stream) != NULL) data.append(this->_buffer);
              pclose(stream);
    }
    memset(this->_buffer, 0, sizeof(this->_buffer));
    data = data.substr(0, data.size() - 1);
    return data;
}
