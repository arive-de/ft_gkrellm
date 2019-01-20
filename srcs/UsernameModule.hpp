/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UsernameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:47 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 17:42:34 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERNAME_MODULE_HPP
# define USERNAME_MODULE_HPP

# include "IMonitorModuleClass.hpp"
# define BUFFER_LEN 1000

class UsernameModule : public IMonitorModule {

public:

        UsernameModule(void);
        UsernameModule(UsernameModule const & src);
        ~UsernameModule(void);

        UsernameModule & operator=(UsernameModule const & rhs);

        std::string    getInfos(void);

private:

        std::string     _username;

};

#endif
