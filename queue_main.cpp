// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:37:31 by ayennoui          #+#    #+#             */
/*   Updated: 2021/03/01 15:47:35 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue/queue.hpp"
#include <queue>
int main()
{   
    ft::queue<int> x;

    // empty
    std::cout << "-------------- empty --------------" << std::endl;
    std::cout << x.empty() << std::endl;

    // size
    std::cout << "-------------- size --------------" << std::endl;
    std::cout << x.size() << std::endl;

    // push
    std::cout << "-------------- push --------------" << std::endl;
    x.push(1);
    x.push(2);
    x.push(3);
    x.push(4);
    std::cout << "size: " << x.size() << std::endl;

    // front and back
    std::cout << "-------------- front and back --------------" << std::endl;
    std::cout << "front: " << x.front() << std::endl;
    std::cout << "back: " << x.back() << std::endl;

    // pop
    std::cout << "-------------- pop --------------" << std::endl;
    x.pop(); // pop 1
    x.pop(); // pop 2
    std::cout << "front: " << x.front() << std::endl;
    std::cout << "back: " << x.back() << std::endl;
    std::cout << "size: " << x.size() << std::endl;


    // relational operators (queue)
    ft::queue<int> y;
    ft::queue<int> z;

    y.push(1);
    z.push(1);
    std::cout << "-------------- relational operators --------------" << std::endl;
    if (y == z)
        std::cout << "queue y and z are equal" << std::endl;
    y.push(2);
    if (y != z)
        std::cout << "queue y and z are not equal" << std::endl;
    if (y > z)
        std::cout << "queue y is bigger than z" << std::endl;
    if (y >= z)
        std::cout << "queue y is bigger or equal to z" << std::endl;
    y.pop();
    y.pop();
    if (y < z)
        std::cout << "queue y is less than z" << std::endl;
    if (y <= z)
        std::cout << "queue y is less or equal to z" << std::endl;
    return (0);
}