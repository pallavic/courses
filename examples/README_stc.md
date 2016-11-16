Object-Oriented Software Design for Financial Libraries
=======================================================

course:  Corso Alta Formazione Finanza Quantitativa, Milano 2016-17
teacher: Andrea Pallavicini, a.pallavicini@imperial.ac.uk

Content
-------

This directory contains the code for the "square-the-circle" example presented in the slides.

Project                               Slides

prototype                              9
procedural                            17-18
procedural_with_objects               21-22
oo_first                              24-26
oo_second                             30-32
oo_third                              33-34
quick_and_dirty                       45-47
semantics                             50-54
ds_in_practice                        60-66
singleton                             78-80

The "library" project is added only to show how to split the "singleton" project into an executable and a static library.

Software Requirements
---------------------

Windows platform:

 - Visual Studio Express 2005 version 8 or greater.
 - CMake v2.6 or greater.

How to build the projects
-------------------------

Windows platform:

1. Run CMake GUI from Start menu.
2. Click "Browse Source" button to select the folder containing al projects ("stc" folder)
3. Click "Browse Build" button to select an empty folder
4. Click "Configure" button (a building wizard appears).
5. Select your version of Visual Studio and select "Use default native compilers". Click "Finish" button and wait for configuration completes.
6. Click "Generate" button.
7. You can open the Visual Studio solution "stc.sln", you can find in the empty folder specified on step 3, and build project "ALL_BUILD".
