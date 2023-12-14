# SharpNeedle

A project for properly injecting C# dlls into other processes.

Note: SharpNeedle currently only supports 32-bit processes. You are welcome to create a pull request which adds 64-bit support.

## Rationale

While merely loading your custom dll injected into a target process' memory
space is fun, that is only half of the story. Most dll injection tutorials will
describe in detail the first half, but then leave you to run your code from
within DllMain, a dangerous and limited proposition. For more information about
why you should avoid doing anything interesting in your DllMain, read
[this thread](https://devblogs.microsoft.com/oldnewthing/20040127-00/?p=40873)
by Raymond Chen.

This project aims to change that dearth of good dll-injection info, providing an
open-source way of not only injecting a dll, but also walking the export address
table and calling a method on your dll.

This project is specifically geared towards injecting managed code into another
process. We will first inject the "Bootstrapper" module, then tell it to load
the CLR and start our example managed project.

## Usage

Developed in Visual Studio Community 2015 on Windows 10.

In src\Launcher\Launcher.cpp, specify the process name to inject into.
In src\ExampleProject\Example.cs, customize EntryPoint() to do as you like.
Ensure the process you are injecting into is running.
Compile and run with appropriate permission levels. I use an unelevated Visual Studio, then run output from an Administrator command prompt.

## Developers

The most interesting file is src\Launcher\Injection.cpp, which deals with walking DLL export tables and creating remote threads.


## License

The entirety of my work on this project is released under the 2-clause BSD license.

'src\Launcher\HCommonEnsureCleanup.h' was provided courtesy of [GameDeception.net](http://www.gamedeception.net/forums/184-Windows-Internals) and its license is unclear.
