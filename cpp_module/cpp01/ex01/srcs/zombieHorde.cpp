/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:20:44 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/07/03 01:45:43 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	Zombie	*zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombies[i].set_name(name);
		zombies[i].announce();
	}
	return (zombies);
}