/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:54:42 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:54:22 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "../vector/vector.hpp"

namespace ft
{

	template <class T, class Container = ft::vector<T> > class stack{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t 		size_type;
			explicit stack (const container_type& ctnr = container_type()):c(ctnr){
			};
			bool empty() const{return (this->_data.empty());};
			size_type size() const{return (this->_data.size());};
			value_type& top(){return (this->_data.back());};
			const value_type& top() const{return (this->_data.back());};
			void push (const value_type& val){this->_data.push_back(val);};
			void pop(){this->_data.pop_back();};

			friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return (lhs._data == rhs._data);
			};
			friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return (lhs._data != rhs._data);
			};
			friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return (lhs._data < rhs._data);
			};
			friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return (lhs._data <= rhs._data);
			};
			friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return (lhs._data > rhs._data);
			};
			friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
				return (lhs._data >= rhs._data);
			};
		private:
			Container _data;
			container_type c;
	};

}
