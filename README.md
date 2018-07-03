# RandomBitmapGenerator

This project is a C++, Qt-based application to test different settings provided to the Linear Congruential Generator, 
a pseudo-random number generator wildly used. Using this application, you can visualize the output of this generator on a bitmap to assess the quality of the randomness by identifying patterns.

You can input your own settings to the LCG, including the seed, modulo, multiplier, increment, and the number of bit to shift.
You can select parameters from various languages and compilers provided here :  
https://en.wikipedia.org/wiki/Linear_congruential_generator#Parameters_in_common_use.  
It is also possible to choose among 4 colors to display on the bitmap.

Different variations of the LCG can be selected :

- linearCongruentialBasic : generates the bitmap according to your settings using the LCG
- linearCongruentialConst : same except without changing the seed every round (static seed)
- linearCongruentialTimestamp : same except it only changes the seed once every second
- linearCongruentialMillistamp : same except it changes the seed once every millisecond
- C++ generator : uses the generator from the CPP language, ignoring your settings, you can use it for comparison

# Download the project

This project was compiled with MinGW 32 bits using Qt Creator. It uses the Qt library and is available under the MIT licence.
A precompiled version is available at: https://sourceforge.net/projects/randombitmapgenerator/


# Screenshots

Once generated, the bitmap will appear on the right of the GUI:

Bitmap generated with apropriate settings, no visible patterns, good randomness.

![alt text](https://i.imgur.com/DIza5Mu.png)

Bitmap generated with inapropriate settings, clearly a pattern is visible.

![alt text](https://i.imgur.com/SY5ng1O.png)


# Building it yourself

If you want to compile the project on your own, you'll need Qt with QMake, and a C++ compiler.
Your best option is to open the BitmapGenerator.pro using Qt Creator. It will auto-configure the project using QMake, asking you only to setup a compiler. You'll be able to edit the code and the GUI using the UI designer integrated in Qt Creator.
To ship it, you'll need a few DLL from the Qt library. Your best choice here would be to use the windeployqt tool provided with Qt for it to copy automatically all the needed DLL without you having to find them one by one.
