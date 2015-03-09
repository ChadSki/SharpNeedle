# SharpNeedle

A project for properly injecting C# dlls into other processes.

## Rationale

While merely loading your custom dll injected into a target process' memory
space is fun, that is only half of the story. Most dll injection tutorials will
describe in detail the first half, but then leave you to run your code from
within DllMain, a dangerous and limited proposition. For more information about
why you should avoid doing anything interesting in your DllMain, read
[this thread](http://blogs.msdn.com/b/oldnewthing/archive/2004/01/27/63401.aspx)
by Raymond Chen.

This project aims to change that dearth of good dll-injection info, providing an
open-source way of not only injecting a dll, but also walking the export address
table and calling a method on your dll.

This project is specifically geared towards injecting managed code into another
process. We will first inject the "Bootstrapper" module, then tell it to load
the CLR and start our example managed project.

## Usage

Developed in Visual Studio 2012 on Windows 8, and compiled with the default MS compilers.

In src\Launcher\Launcher.cpp, specify the process name to inject into.
In src\ExampleProject\Example.cs, customize EntryPoint() to do as you like.
Ensure the process you are injecting into is running.
Compile and run with appropriate permission levels.

## Developers

The most interesting file is src\Launcher\Injection.cpp, which deals with walking DLL export tables and creating remote threads.


## License

The entirety of my work on this project is released under the 2-clause BSD license.

'src\Launcher\HCommonEnsureCleanup.h' was provided courtesy of [GameDeception.net](http://www.gamedeception.net/forums/184-Windows-Internals) and its license is unclear.
