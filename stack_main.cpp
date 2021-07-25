/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:48:53 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/01 15:36:56 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack/stack.hpp"
#include <stack>

int main()
{
    ft::stack<int> x;
    
    // empty
    std::cout << "-------------- empty --------------" << std::endl;
    std::cout << x.empty() << std::endl;

    // size
    std::cout << "-------------- size --------------" << std::endl;
    std::cout << x.size() << std::endl;

    // top
    std::cout << "-------------- top --------------" << std::endl;
    std::cout << x.top() << std::endl;

    // push
    std::cout << "-------------- push --------------" << std::endl;
    x.push(0);
    x.push(1);
    x.push(3);
    x.push(10);
    std::cout << "size:  " << x.size() << std::endl;
    std::cout << "top:  " << x.top() << std::endl;

    // pop
    std::cout << "-------------- pop --------------" << std::endl;
    x.pop(); // pop 10
    x.pop(); // pop 3
    std::cout << "size:  " << x.size() << std::endl;
    std::cout << "top:  " << x.top() << std::endl;

    // relational operators (stack)
    ft::stack<int> y;
    ft::stack<int> z;

    y.push(1);
    z.push(1);
    std::cout << "-------------- relational operators --------------" << std::endl;
    if (y == z)
        std::cout << "stack y and z are equal" << std::endl;
    y.push(2);
    if (y != z)
        std::cout << "stack y and z are not equal" << std::endl;
    if (y > z)
        std::cout << "stack y is bigger than z" << std::endl;
    if (y >= z)
        std::cout << "stack y is bigger or equal to z" << std::endl;
    y.pop();
    y.pop();
    if (y < z)
        std::cout << "stack y is less than z" << std::endl;
    if (y <= z)
        std::cout << "stack y is less or equal to z" << std::endl;
    return (0);
}