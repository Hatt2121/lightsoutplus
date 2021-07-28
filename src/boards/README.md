The Board Folder
===================

This is a folder containing some of the static resources for the game. Specifically, it contains the boards that the game will select from.

## Planning and Approach

Because I plan on this project being more open than just an 8x8 board, I decided it 
would be fun if I formatted my own file type to process all the boards the program can choose from. And again, I'm making this harder on myself just so I can have fun with 
lower level concepts like this.

Reading a file in C shouldn't be that hard... right?


    boards
    |
    |/core_boards                #I am going to make this one.
    |   |
    |   | 3x3.boa
    |   | 5x5.boa
    |   | 4x4.boa
    |   | etc.
    |
    |/more_boards               #A folder that someone could easily copy.
    |   |
    |   | 3x3.boa
    |   | 15x15.boa
    |   | etc.

Inside folders that are inside this directory are going to contain .boa files (that's
what I am going to be calling them for the time being) that are just going to have a
bunch of boards within them.

They don't need to have the same size of boards in them, but I am setting that
standard just to make it easier for programming... so far. I will change this file
in accordance to what I think is going to be best. These files aren't going to be 
compiled into the program... but I think it will be fun to figure out how. Probably
it will be easy to have an include statement or something I guess. 

Having them separate from the program might help out with plug-and-playability. I 
think it could be easy for a kid to change the names of the files and put them in the
right place, and maybe I can make an application that could make and translate boards
for those not familiar or comfortable with hex editing.

## Formatting

C bit strings are weird. I don't know how an operating system detects whether files 
exist or not... Do files have a signifier that tells the beginning and end of files?
