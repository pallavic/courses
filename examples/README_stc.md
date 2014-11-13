Object-Oriented Software Design for Financial Libraries
=======================================================

Software Requirements
---------------------

 - Visual Studio Express 2008 or greater.
 - CMake v2.6 or greater.

How to build the projects
-------------------------

With Visual Studio:

1. Run CMake GUI from Start menu.
2. Click "Browse Source" button to select the folder containing al projects ("stc" folder)
3. Click "Browse Build" button to select an empty folder
4. Click "Configure" button (a building wizard appears).
5. Select your version of Visual Studio and select "Use default native compilers". Click "Finish" button and wait for configuration completes.
6. Click "Generate" button.
7. You can open the Visual Studio solution "stc.sln", you can find in the empty folder specified on step 3, and build project "ALL_BUILD".

With MinGW (or any POSIX platform):

1. Enter the directory containing al projects ("stc" folder) and create a new directory: $> mkdir build-msys
2. Enter such new directory: $> cd build-msys
3. Generate all makefiles (if the command fails repeat againg once more time): $> cmake ../stc -G'MSYS Makefiles'
4. Compile all the projects with G++: $> make

