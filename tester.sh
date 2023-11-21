#!/bin/bash

#make re
cat loro.text
./push_swap "$@" | ./checker_Mac "$@"
