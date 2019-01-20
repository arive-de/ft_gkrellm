/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:56 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 19:52:43 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_MODULE_HPP
# define NETWORK_MODULE_HPP

# include "IMonitorModuleClass.hpp"
# define BUFFER_LEN 1000

class NetworkModule : public IMonitorModule {

public:

        NetworkModule(void);
        NetworkModule(NetworkModule const & src);
        virtual ~NetworkModule(void);

        NetworkModule & operator=(NetworkModule const & rhs);

        std::string    getInfos(void);
        std::string    getStdOut(std::string cmd);


private:

        std::string     _network;
        char            _buffer[BUFFER_LEN];
        size_t          _bufferlen;
};

#endif
