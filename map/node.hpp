/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:50:36 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:05:08 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
namespace ft
{
	template<typename T>
		class node
		{
			public:
				node(/* args */){};
				node(const T &a):_value(a){};
				node(node<T> &a):_value(a._value),next(a.next),prev(a.prev){
				};
				~node(){};
				T	_value;
				node<T> *next;
				node<T> *prev;
		};
} // namespace name
