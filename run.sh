#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 19:32:07 by besellem          #+#    #+#              #
#    Updated: 2022/11/14 19:32:08 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clang++ -Wall -Wextra -Werror -Wpedantic --std=c++11 -fsanitize=address -g3 main.cpp && ./a.out

# clang++ -Wall -Wextra -Werror -Wpedantic --std=c++11 main.cpp && leaks -q --atExit -- ./a.out

rm -rf a.out a.out.dSYM
