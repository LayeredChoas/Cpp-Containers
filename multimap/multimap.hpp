/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multimap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:54:19 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:53:18 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>
#include "../map/node.hpp"
#include "multimap_iter.hpp"
namespace ft
{
	template <class T1, class T2> struct pair{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;
		pair():first(),second(){};
		template<class U, class V> pair (const pair<U,V>& pr):first(pr.first),second(pr.second){
		};
		pair (const first_type& a, const second_type& b):first(a),second(b){
		};
		pair& operator= (const pair& pr){
			first = pr.first;
			second = pr.second;
			return (*this);
		};
	};
	template <class T1, class T2>
		pair<T1,T2> make_pair (T1 x, T2 y)
		{
			return ( pair<T1,T2>(x,y) );
		}
	template <class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return ((lhs.first == rhs.first) && (lhs.second == rhs.second));};

	template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return ((lhs.first != rhs.first) || (lhs.second != rhs.second));};

	template <class T1, class T2>
		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			if (lhs.first < rhs.first)
				return true;
			if (lhs.first > rhs.first)
				return false;
			return (lhs.second < rhs.second);
		};

	template <class T1, class T2>
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return !(lhs > rhs);};

	template <class T1, class T2>
		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			if (lhs.first > rhs.first)
				return true;
			if (lhs.first < rhs.first)
				return false;
			return (lhs.second > rhs.second);
		}

	template <class T1, class T2>
		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){return !(lhs < rhs);};
	template < class Key,                                     // multimap::key_type
			 class T,                                       // multimap::mapped_type
			 class Compare = std::less<Key>,                     // multimap::key_compare
			 class Alloc = std::allocator<ft::pair<const Key,T> >    // multimap::allocator_type
				 > class multimap
				 {
					 public:
						 typedef Key											key_type;
						 typedef T											mapped_type;
						 typedef ft::pair<const Key, T>						value_type;
						 typedef Compare										key_compare;
						 typedef  Alloc										allocator_type;
						 typedef value_type&									reference;
						 typedef const value_type&							const_reference;
						 typedef value_type*									pointer;
						 typedef const value_type*							const_pointer;
						 typedef ptrdiff_t									difference_type;
						 typedef size_t										size_type;
						 typedef ft::multimap_iter<value_type, value_type*, value_type&>						iterator;
						 typedef ft::multimap_iter< value_type, const value_type*, const value_type&>						const_iterator;
						 typedef ft::multimap_rev_iter<value_type, value_type*, value_type&>						reverse_iterator;
						 typedef ft::multimap_rev_iter< value_type, const value_type*, const value_type&>						const_reverse_iterator;
						 explicit multimap (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):c(comp),alloc(alloc){
							 _size = 0;
							 _head = new node<value_type>; 
							 _tail = new node<value_type>;
							 _head->next = _tail;
							 _tail->prev = _head;
							 _tail->next = NULL;							 
						 };
						 template <class InputIterator>
							 multimap (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):c(comp),alloc(alloc){
								 _size = 0;
								 _head = new node<value_type>; 
								 _tail = new node<value_type>;
								 _head->next = _tail;
								 _tail->prev = _head;
								 _tail->next = NULL;
								 while (first != last)
								 {
									 this->insert(ft::make_pair(first->first, first->second));
									 first++;
								 }
							 };
						 multimap (const multimap& x){
							 _size = 0;
							 _head = new node<value_type>; 
							 _tail = new node<value_type>;
							 _head->next = _tail;
							 _tail->prev = _head;
							 _tail->next = NULL;
							 c = x.c;
							 alloc = x.alloc;
							 this->insert(x.cbegin(), x.cend());						 
						 };
						 ~multimap(){
							 this->clear();
							 delete _head;
							 delete _tail;
							 _head = NULL;
							 _tail = NULL;
						 };
						 multimap& operator= (const multimap& x){
							 if (this != &x)
								 *this = x;			 
						 };
						 class value_compare
						 {   
							 friend class multimap;
							 protected:
							 Compare comp;
							 value_compare (Compare c) : comp(c) {}
							 public:
							 typedef bool result_type;
							 typedef value_type first_argument_type;
							 typedef value_type second_argument_type;
							 bool operator() (const value_type& x, const value_type& y) const
							 {
								 return comp(x.first, y.first);
							 }
						 };
						 // ITER
						 iterator begin() {return (iterator(_head->next));};
						 iterator end() {return (iterator(_tail));};

						 const_iterator cbegin() const {return (const_iterator(_head->next));};
						 const_iterator cend() const {return (const_iterator(_tail));};

						 reverse_iterator rbegin() {return (reverse_iterator(_tail->prev));};
						 reverse_iterator rend() {return (reverse_iterator(_head));};

						 const_reverse_iterator crbegin() const{return (const_reverse_iterator(_head->next));};
						 const_reverse_iterator crend() const{return (const_reverse_iterator(_tail));};

						 // Capacity
						 bool empty() const{return (_size == 0);};
						 size_type size() const{return (_size);};
						 size_type max_size() const{return (461168601842738790);};

						 // Element access:
						 mapped_type& operator[] (const key_type& k){
							 return(insert(ft::make_pair(k, mapped_type())).first->second);
						 };

						 // Modifiers:
						 bool comp_fun(key_type a, key_type b, key_compare u = Compare())
						 {
							 return (u(a, b));
						 }
						 ft::pair<iterator,bool> insert (const value_type& val){

							 node<value_type> *cpy = _head->next;
							 node<value_type> *ret = new node<value_type>(val);
							 if (_size != 0)
							 {
								 cpy = _head->next;
								 while (cpy->next != NULL)
								 {
									 if (comp_fun(val.first, cpy->_value.first))
									 {
										 ret->next = cpy;
										 ret->prev = cpy->prev;
										 cpy->prev->next = ret;
										 cpy->prev = ret;
										 _size++;
										 return (ft::pair<iterator,bool>(iterator(ret),true));
									 }
									 cpy = cpy->next;
								 }
							 }
							 ret->next = _tail;
							 ret->prev = _tail->prev;
							 _tail->prev->next = ret;
							 _tail->prev = ret;
							 _size++;
							 return (ft::pair<iterator,bool>(iterator(ret),true));
						 };
						 iterator insert (iterator position, const value_type& val){
							 (void)position;
							 return (insert(val).first);
						 };
						 template <class InputIterator>
							 void insert (InputIterator first, InputIterator last){
								 while (first != last)
								 {
									 insert(ft::make_pair(first->first, first->second));
									 first++;
								 }
							 };
						 void erase (iterator position){
							 node<value_type> *cpy;

							 if (position == this->end())
								 return ;
							 cpy = _head->next;
							 while (cpy->_value.first != position->first)
								 cpy = cpy->next;
							 cpy->prev->next = cpy->next;
							 cpy->next->prev = cpy->prev;
							 delete cpy;
							 _size--;
						 };
						 size_type erase (const key_type& k){
							 node<value_type> *cpy;
							 size_type count = 0;

							 cpy = _head->next;
							 while (cpy->next != NULL)
							 {
								 if (cpy->_value.first == k)
								 {
									 cpy->prev->next = cpy->next;
									 cpy->next->prev = cpy->prev;
									 delete cpy;
									 _size--;
									 return (count);
								 }
								 count++;
								 cpy = cpy->next;
							 }
							 return (0);
						 };
						 void erase (iterator first, iterator last){
							 while (first != last)
							 {
								 erase(first->first);
								 first++;
							 }
						 };
						 void swap (multimap& x){
							 node<value_type> *tmp_head;
							 node<value_type> *tmp_tail;
							 size_type tmp_size;

							 tmp_head = x._head;
							 tmp_tail = x._tail;
							 tmp_size = x._size;

							 x._head = _head;
							 x._tail = _tail;
							 x._size = _size;

							 _head = tmp_head;
							 _tail = tmp_tail;
							 _size = tmp_size;

						 };
						 void clear(){
							 node<value_type> *cpy;

							 cpy = _head->next;
							 while (cpy->next != NULL)
							 {
								 delete cpy;
								 cpy = cpy->next;
							 }
							 _head->next = _tail;
							 _tail->prev = _head;
							 _tail->next = NULL;
							 _size = 0;
						 };
						 key_compare key_comp() const{
							 return (Compare());
						 };
						 value_compare value_comp() const{
							 return (value_compare(Compare()));
						 };
						 iterator find (const key_type& k){
							 iterator it = this->begin();
							 iterator it_e = this->end();

							 while (it != it_e)
							 {
								 if (k == it->first)
									 return (it);
								 it++;
							 }
							 return (this->end());
						 };
						 const_iterator find (const key_type& k) const{
							 iterator it = this->begin();
							 iterator it_e = this->end();

							 while (it != it_e)
							 {
								 if (k == it->first)
									 return ((const_iterator)it);
								 it++;
							 }
							 return ((const_iterator)this->end());
						 };
						 size_type count (const key_type& k) const{
							 node<value_type> *cpy;
							 size_type ret = 0;

							 cpy = _head->next;
							 while (cpy->next != NULL)
							 {
								 if (k == cpy->_value.first)
									 ret++;
								 cpy = cpy->next;
							 }
							 return (ret);
						 };
						 iterator lower_bound (const key_type& k){
							 iterator it = this->begin();
							 iterator it_e = this->end();
							 while (it != it_e)
							 {
								 if (it->first == k)
									 return (it);
								 it++;
							 }
							 return (this->end());
						 };
						 const_iterator lower_bound (const key_type& k) const
						 {
							 const_iterator it = this->begin();
							 const_iterator it_e = this->end();
							 while (it != it_e)
							 {
								 if (it->first == k)
									 return (it);
								 it++;
							 }
							 return (this->end());
						 };
						 iterator upper_bound (const key_type& k){
							 iterator it = this->begin();
							 iterator it_e = this->end();
							 while (it != it_e)
							 {
								 if (it->first == k)
								 {
									 it++;
									 return (it);
								 }
								 it++;
							 }
							 return (this->end());
						 };
						 const_iterator upper_bound (const key_type& k) const{
							 const_iterator it = this->cbegin();
							 const_iterator it_e = this->cend();
							 while (it != it_e)
							 {
								 if (it->first == k)
								 {
									 it++;
									 return (it);
								 }
								 it++;
							 }
							 return (this->cend());
						 };
						 ft::pair<iterator,iterator>             equal_range (const key_type& k){
							 iterator it = this->lower_bound(k);
							 while (it->first == k && it != this->end())
								 it++;
							 return (ft::make_pair(lower_bound(k), it));
						 };
						 ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
							 const_iterator it = this->lower_bound(k);
							 while (it->first == k && it != this->end())
								 it++;
							 return (ft::make_pair(lower_bound(k), it));
						 };

						 template <class Key1, class T1, class Compare1, class Alloc1>
							 friend bool operator== ( const multimap<Key1,T1,Compare1,Alloc1>& lhs,
									 const multimap<Key1,T1,Compare1,Alloc1>& rhs ){
								 const_iterator it = lhs.cbegin();
								 const_iterator it1 = rhs.cbegin();
								 while (it != lhs.cend())
								 {
									 if (it1 == rhs.cend())
										 return (false);
									 if (*it != *it1)
										 return false;
									 it++;
									 it1++;
								 }
								 return ((*it == *it1));
							 };

						 template <class Key1, class T1, class Compare1, class Alloc1>
							 friend bool operator!= ( const multimap<Key1,T1,Compare1,Alloc1>& lhs,
									 const multimap<Key1,T1,Compare1,Alloc1>& rhs ){return !(lhs == rhs);};

						 template <class Key1, class T1, class Compare1, class Alloc1>
							 friend bool operator<  ( const multimap<Key1,T1,Compare1,Alloc1>& lhs,
									 const multimap<Key1,T1,Compare1,Alloc1>& rhs ){
								 const_iterator it = lhs.cbegin();
								 const_iterator it1 = rhs.cbegin();
								 while (it != lhs.cend())
								 {
									 if (*it < *it1)
										 return true;
									 if (it1 == rhs.cend() || *it > *it1)
										 return (false);
									 if (*it == *it1)
										 return false;
									 it++;
									 it1++;
								 }
								 return ((*it < *it1));
							 };
						 template <class Key1, class T3, class Compare1, class Alloc1>
							 friend bool operator<= ( const multimap<Key1,T3,Compare1,Alloc1>& lhs,
									 const multimap<Key1,T3,Compare1,Alloc1>& rhs ){return !(rhs < lhs);};

						 template <class Key1, class T3, class Compare1, class Alloc1>
							 friend bool operator>  ( const multimap<Key1,T3,Compare1,Alloc1>& lhs,
									 const multimap<Key1,T3,Compare1,Alloc1>& rhs ){return ((rhs < lhs) && !(rhs == lhs));};

						 template <class Key1, class T3, class Compare1, class Alloc1>
							 friend bool operator>= ( const multimap<Key1,T3,Compare1,Alloc1>& lhs,
									 const multimap<Key1,T3,Compare1,Alloc1>& rhs ){return !(lhs < rhs);};
					 private:
						 node<value_type> *_head;
						 node<value_type> *_tail;
						 size_type _size;
						 key_compare c;
						 Alloc alloc;
				 };

} // namespace ft
