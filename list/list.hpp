/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:58:36 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/02 18:03:37 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef list_HPP
#define list_HPP
#include <iostream>
#include "list_iter.hpp"

namespace ft
{
	template <class R, class L>
		bool equal(R start, R end, L start1, L end1)
		{
			while (start != end)
			{
				if (start1 == end1 || *start != *start1 )
					return false;
				start++;
				start1++;
			}
			return true;
		}
	template <class R, class L>
		bool less_then(R start, R end, L start1, L end1)
		{
			while (start != end)
			{
				if (start1 == end1 || *start > *start1)
					return false;
				else if (*start < *start1)
					return true;
				start++;
				start1++;
			}
			return (*start1 != *end1);
		}
	template < class T, class Alloc = std::allocator<T> >
		class list 
		{

			public:
				typedef  T																	value_type;
				typedef  Alloc																allocator_type;
				typedef value_type&															reference;
				typedef const value_type&													const_reference;
				typedef value_type*															pointer;
				typedef const value_type*													const_pointer;
				typedef ptrdiff_t															difference_type;
				typedef size_t																size_type;
				typedef list_iter<value_type, value_type*, value_type&>						iterator;
				typedef list_iter<value_type, const value_type*, const value_type&>			const_iterator;
				typedef rev_list_iter<value_type, value_type*, value_type&>					reverse_iterator;
				typedef rev_list_iter<value_type, const value_type*, const value_type&>		const_reverse_iterator;

				// Member functions
				explicit list (const allocator_type& alloc = allocator_type()):alloc(alloc), _size(0){
					this->_data = new node<T>();
					this->_tail = new node<T>();
					this->_data->next = this->_tail;
					this->_tail->prev = this->_data;
					this->_tail->next = NULL;
				};
				explicit list (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()):alloc(alloc){
					_data = new node<T>;
					_tail = new node<T>;
					_data->next = _tail;
					_data->prev = NULL;
					_tail->next = NULL;
					_tail->prev = _data;
					_size = 0;
					this->assign(n, val);
				};
				template <class InputIterator>
					list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):alloc(alloc){
						_data = new node<T>;
						_tail = new node<T>;
						_data->next = _tail;
						_data->prev = NULL;
						_tail->next = NULL;
						_tail->prev = _data;

						_size = 0;
						this->assign(first, last);
					};
				list (const list& x){
					_data = new node<T>;
					_tail = new node<T>;
					_data->next = _tail;
					_data->prev = NULL;
					_tail->next = NULL;
					_tail->prev = _data;
					_size = 0;
					this->assign(x.begin(), x.end());
				};
				~list(){
					delete _data;
					delete _tail;
				};
				list& operator= (const list& x){
					this->_data = x._data;
					this->_size = x._size;
					this->_tail = x._tail;
					return (*this);
				};

				// Iterators	
				iterator begin() const {return iterator(_data->next);}
				iterator end() const  {return iterator(_tail);}
				const_iterator cbegin() const {return const_iterator(_data->next);}
				const_iterator cend() const {return const_iterator(_tail);}
				reverse_iterator rbegin() {return reverse_iterator(_data->next);}
				reverse_iterator rend() {return reverse_iterator(_tail);}
				const_reverse_iterator crbegin(){return const_reverse_iterator(_data->next);}
				const_reverse_iterator crend() {return const_reverse_iterator(_tail);}

				//Capacity
				bool empty() {return (_size == 0);}
				size_type size() const {return (this->_size);}
				size_type max_size() {return (std::numeric_limits<size_type>::max() / sizeof(node<value_type>));}

				// Element access
				reference front() {return (_data->next->value);}
				const_reference front() const {return (_data->next->value);}
				reference back() {return (_tail->prev->value);}
				const_reference back() const {return (_tail->prev->value);}


				// Modifiers
				void assign (size_type n, const value_type& val){
					this->clear();
					for (size_type i = 0; i < n; i++)
						this->push_back(val);
				};
				void assign (int n, const T& val){
					this->clear();
					for (int i = 0; i < n; i++)
						this->push_back(val);
				};
				template <class InputIterator>
					void assign (InputIterator first, InputIterator last){
						this->clear();
						while (first != last)
						{
							this->push_back(*first);
							first++;
						}
					};
				void push_front(const T& value)
				{
					node<T> *_new = new node<T>;

					_new->value = value;
					_new->next = _data->next;
					_new->prev = _data;
					_data->next->prev = _new;
					_data->next = _new;
					_size++;
				}
				void pop_front()
				{
					node<T> *ret;

					ret = _data->next;
					_data->next = _data->next->next;
					_data->next->prev = _data;
					_size--;
					delete ret;
				}
				void push_back(const T& value)
				{
					node<T> *ptr = new node<T>(value);

					ptr->next = this->_tail;
					ptr->prev = this->_tail->prev;
					this->_tail->prev->next = ptr;
					this->_tail->prev = ptr;
					this->_size++;
				}
				void pop_back()
				{
					if (this->_size)
					{
						node<T> *tmp = this->_tail->prev->prev;
						tmp->next = this->_tail;
						delete this->_tail->prev;
						this->_tail->prev = tmp;
						this->_tail->next = NULL;
						this->_size--;
					}
				}
				void clear(){
					while (_size > 0)
						this->pop_back();
					_data->next = _tail;
					_tail->prev = _data;
				}
				iterator insert (iterator position, const T& val){
					node<T> *insertion = new node<T>(val);
					insertion->prev = position.ptr()->prev;
					insertion->next = position.ptr();
					insertion->prev->next = insertion;
					insertion->next->prev = insertion;
					this->_size++;
					return iterator(insertion);
				}
				void insert (iterator position, size_type n, const value_type& val){
					for (size_t i = 0; i < n; i++)
						this->insert(position, val);
				}
				void insert (iterator position, int n, const value_type& val){
					for (size_t i = 0; i < n; i++)
						this->insert(position, val);
				}
				template <class InputIterator>
					void insert (iterator position, InputIterator first, InputIterator last){
						while (first != last)
						{
							this->insert(position, *first);
							first++;
						}
					}

				iterator erase (iterator position){
					node<T> *ret;

					if (position.current->next == NULL)
						return (position);
					ret = position.ptr();
					ret->prev->next = ret->next;
					ret->next->prev = ret->prev;
					position++;
					delete ret;
					_size--;
					return (position);
				}
				iterator erase (iterator first, iterator last){
					while (first != last && first.next_ptr() != NULL)
					{
						this->erase(first);
						first++;
					}
					return ((iterator)first.prev_ptr());
				}
				void swap (list& a){
					node<T> *d = _data;
					node<T> *t = _tail;
					size_type num = _size;

					_data = a._data;
					_tail = a._tail;
					_size = a._size;

					a._data = d;
					a._tail = t;
					a._size = num;
				};
				void resize (size_type n, value_type val = value_type()){				
					int diff = 0;

					if (n > _size)
					{
						diff = n - _size;
						for (int i = 0; i < diff; i++)
							push_back(val);
					}
					if (_size > n)
					{
						diff = _size - n;
						for (int i = 0; i < diff; i++)
							pop_back();
					}
				};


				// Operations
				void splice (iterator position, list& x, iterator first, iterator last)
				{
					iterator it = x.begin();
					it = first;

					while (first != last)
					{
						it = first;
						first++;
						this->splice(position, x, it);
					}
				}
				void splice (iterator position, list& x, iterator i)
				{
					iterator it = x.begin();
					(void)*it;

					i.next_ptr()->prev = i.prev_ptr();
					i.prev_ptr()->next = i.next_ptr();

					i.current->next = position.current;
					i.current->prev = position.current->prev;

					position.current->prev->next = i.current;
					position.current->prev = i.current;
					x._size--;
				}
				void splice (iterator position, list& x){
					splice(position, x, x.begin(), x.end());
				}

				void remove (const T& val){
					iterator it = this->begin();

					while (it != this->end())
					{
						if (*it == val)
							this->erase(it);
						it++;
					}
				};
				template <class Predicate>
					void remove_if (Predicate pred){

						iterator it = this->begin();

						while (it != this->end())
						{
							if (pred(*it))
								this->erase(it);
							it++;
						}
					};
				void unique()
				{
					iterator it = this->begin();
					it++;
					while (it != this->end())
					{
						if (*it == it.prev_ptr()->value)
							it = this->erase(it);
						else
							++it;
					}
				}
				template <class BinaryPredicate>
					void unique (BinaryPredicate binary_pred){
						iterator it = this->begin();
						it++;
						while (it != this->end())
						{
							if (binary_pred(*it, it.prev_ptr()->value))
								it = this->erase(it);
							else
								++it;
						}
					};

				void merge (list& a)
				{
					list *ret = new list<T>;
					iterator it = this->begin();
					iterator it1 = a.begin();

					if (&a == this)
						return ;
					while (it != this->end() || it1 != a.end())
					{
						if (it == this->end())
						{
							while (it1 != a.end())
							{
								ret->push_back(*it1);
								it1++;
							}
							a.clear();
							this->clear();
							this->_data = ret->_data;
							this->_tail = ret->_tail;
							this->_size = ret->_size;
							return ;
						}
						if (it1 == a.end())
						{
							while (it != this->end())
							{
								ret->push_back(*it);
								it++;
							}
							a.clear();
							this->clear();
							this->_data = ret->_data;
							this->_tail = ret->_tail;
							this->_size = ret->_size;
							return ;
						}
						if (*it < *it1)
						{
							ret->push_back(*it);
							it++;
						}
						else
						{
							ret->push_back(*it1);
							it1++;
						}
					}
					a.clear();
					this->clear();
					this->_data = ret->_data;
					this->_tail = ret->_tail;
					this->_size = ret->_size;
				};
				template <class Compare>
					void merge (list& x, Compare comp){
						list *ret = new list<T>;

						iterator it = x.begin();
						iterator it1 = this->begin();

						while (it != x.end() || it1 != this->end())
						{
							if (it == x.end())
							{
								ret->insert(ret->end(), it1, this->end());
								this->clear();
								x.clear();
								delete _data;
								delete _tail;
								this->_data = ret->_data;
								this->_size = ret->_size;
								this->_tail = ret->_tail;
								return ;
							}
							if (it1 == this->end())
							{
								ret->insert(--ret->end(), it, x.end());
								this->clear();
								x.clear();
								delete _data;
								delete _tail;
								this->_data = ret->_data;
								this->_size = ret->_size;
								this->_tail = ret->_tail;
								return ;
							}
							if (comp(*it, *it1))
							{
								ret->push_back(*it);
								it++;
							}
							else
							{
								ret->push_back(*it1);
								it1++;
							}
						}
						x.clear();
						this->_data = ret->_data;
						this->_size = ret->_size;
						this->_tail = ret->_tail;
					};

				void sort(){
					if (_size == 0 || _size == 1)
						return ;
					node<T> *current = _data->next, *index = NULL;
					T temp;
					while(current->next != NULL) {  
						index = current->next;
						while(index->next != NULL) {  
							if(current->value > index->value) {  
								temp = current->value;  
								current->value = index->value;  
								index->value = temp;  
							}
							index = index->next;  
						}  
						current = current->next;  
					}      
				};
				template <class Compare>
					void sort (Compare comp){
						if (_size == 0 || _size == 1)
							return ;
						node<T> *current = _data->next, *index = NULL;
						T temp;
						while(current->next != NULL) {  
							index = current->next;
							while(index->next != NULL) {  
								if(!comp(current->value, index->value)) {  
									temp = current->value;  
									current->value = index->value;  
									index->value = temp;  
								}
								index = index->next;  
							}  
							current = current->next;  
						}   
					};
				void reverse(){
					node<T> *ret = NULL;
					if (_size == 0 || _size == 1)
						return ;
					list *_new = new list<T>;
					while (_data->next->next != NULL)
					{
						_new->push_front(_data->next->value);
						ret = _data->next;
						_data->next = _data->next->next;
						delete ret;
					}
					delete _data;
					delete _tail;
					this->_data = _new->_data;
					this->_tail = _new->_tail;
					this->_size = _new->_size;
				};
				void remove_without(T val, int index)
				{
					node<T> *ret;
					node<T> *last;
					node<T> *back;
					int count = 0;
					int size = _size;

					ret = _data;
					while (ret->next != NULL)
					{
						if (ret->value == val && index != count)
						{
							back = ret->next;
							delete ret;
							last->next = back;
							ret = last;
							_size--;
						}
						last = ret;
						if (size == _size)
							ret = ret->next;
						else
							size = _size;
						count++;
					}
				};
				// Non-member functions
				template <class R, class All>
					void swap (list<R,All>& x, list<R,All>& y)
					{
						x.swap(y);  
					};

			private:
				node<T> *_data;
				node<T> *_tail;
				Alloc alloc;
				unsigned int _size;
				bool equal(iterator start, iterator end, iterator start1)
				{
					while (start != end)
					{
						if (*start != *start1)
							return false;
						start++;
						start1++;
					}
					return true;
				}
				int no_exist(T value)
				{
					node<T> *ret;

					if (_size == 0)
						return (0);
					ret = _data;
					while (ret->next != NULL)
					{
						if (value == ret->value)
							return (1);
						ret = ret->next;
					}
					if (value == ret->value)
						return (1);
					return (0);
				}
				template <class T1, class Alloc1>
					friend bool operator== (const list<T1,Alloc1>& lhs, const list<T1,Alloc1>& rhs){
						return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
					};
				template <class T1, class Alloc1>
					friend bool operator!= (const list<T1,Alloc1>& lhs, const list<T1,Alloc1>& rhs){return (!(lhs == rhs));};
				template <class T1, class Alloc1>
					friend bool operator<  (const list<T1,Alloc1>& lhs, const list<T1,Alloc1>& rhs){return (less_then(lhs.begin(), lhs.end(), rhs.begin(),rhs.end()));};
				template <class T1, class Alloc1>
					friend bool operator<= (const list<T1,Alloc1>& lhs, const list<T1,Alloc1>& rhs){return (!(rhs < lhs));};
				template <class T1, class Alloc1>
					friend bool operator>  (const list<T1,Alloc1>& lhs, const list<T1,Alloc1>& rhs){
						return (rhs < lhs);};
				template <class T1, class Alloc1>
					friend bool operator>= (const list<T1,Alloc1>& lhs, const list<T1,Alloc1>& rhs){return !(lhs < rhs);};
		};
};

#endif
