Object-Oriented Software Design for Financial Libraries
=======================================================

course:  Corso Alta Formazione Finanza Quantitativa, Milano 2016-17
teacher: Andrea Pallavicini, a.pallavicini@imperial.ac.uk

Content
-------

This directory contains the code for the "Monte Carlo" example presented in the slides.

Project                               Slides

naive                                 89
clike                                 89
oo_first                              93

Software Requirements
---------------------

Windows platform:

 - Visual Studio Express 2005 version 8 or greater.
 - CMake v2.6 or greater.
 
How to build the projects
-------------------------

Windows platform:

1. Run CMake GUI from Start menu.
2. Click "Browse Source" button to select the folder containing al projects ("mc" folder)
3. Click "Browse Build" button to select an empty folder
4. Click "Configure" button (a building wizard appears).
5. Select your version of Visual Studio and select "Use default native compilers". Click "Finish" button and wait for configuration completes.
6. Click "Generate" button.
7. You can open the Visual Studio solution "mc.sln", you can find in the empty folder specified on step 3, and build project "ALL_BUILD".
