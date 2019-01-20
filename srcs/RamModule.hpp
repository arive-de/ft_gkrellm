/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:56 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 19:21:25 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

# include "IMonitorModuleClass.hpp"
# define BUFFER_LEN 1000

class RamModule : public IMonitorModule {

public:

        RamModule(void);
        RamModule(RamModule const & src);
        virtual ~RamModule(void);

        RamModule & operator=(RamModule const & rhs);

        std::string    getInfos(void);
        std::string    getStdOut(std::string cmd);


private:

        std::string     _ram;
        char            _buffer[BUFFER_LEN];
        size_t          _bufferlen;
};

#endif
