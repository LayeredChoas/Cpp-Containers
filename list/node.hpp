/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:49:17 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:04:13 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP
namespace ft
{
	template<typename T>
		class node
		{
			public:
				node(){};
				node(T const &a):value(a){};
				~node(){};
				T value;
				node *next;
				node *prev;
				bool operator!=(node const &a)const {return (this != &a);}
				bool operator==(node const &a)const {return ((value == a.value) && (next == a.next) && (prev == a.prev));}
		};
} // namespace ft
#endif
