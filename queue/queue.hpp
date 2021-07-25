/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:22:09 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:05:23 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../list/list.hpp"
namespace ft
{
	template <class T, class Container = list<T> > class queue
	{
		public:

			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;	
		private:
			Container _data;
		public:
			explicit queue (const container_type& ctnr = container_type()):_data(ctnr){};
			~queue(){};
			bool empty() {return (_data.empty());};
			size_type size() const{return (_data.size());};
			value_type& front(){return (_data.front());};
			const value_type& front() const{return (_data.front());};
			value_type& back(){return (_data.back());};
			const value_type& back() const{return (_data.back());};
			void push (const value_type& val){_data.push_back(val);};
			void pop(){_data.pop_front();};
			template <class T1, class Container1>
				friend bool operator== (const queue<T1,Container1>& lhs, const queue<T1,Container1>& rhs){return (lhs._data == rhs._data);};

			template <class T1, class Container1>
				friend bool operator!= (const queue<T1,Container1>& lhs, const queue<T1,Container1>& rhs){return (lhs._data != rhs._data);};

			template <class T1, class Container1>
				friend bool operator<  (const queue<T1,Container1>& lhs, const queue<T1,Container1>& rhs){return (lhs._data < rhs._data);};

			template <class T1, class Container1>
				friend bool operator<= (const queue<T1,Container1>& lhs, const queue<T1,Container1>& rhs){return (lhs._data <= rhs._data);};

			template <class T1, class Container1>
				friend bool operator>  (const queue<T1,Container1>& lhs, const queue<T1,Container1>& rhs){return (lhs._data > rhs._data);};

			template <class T1, class Container1>
				friend bool operator>= (const queue<T1,Container1>& lhs, const queue<T1,Container1>& rhs){return (lhs._data >= rhs._data);};
	};


}
