# Project Structure

## Launcher.exe (native)

This generates the exe file. It will inject Bootstrapper.dll into the specified
process, then call a method on it.

## Bootstrapper.dll (native)

This is the dll to be injected. It knows how to attach to the CLR (v4.0) and load
a managed dll.

## ExampleProject.dll (managed)

This is the managed project which we will ultimately load. Feel free to replace this
with whatever you desire, but be sure to follow the entry point convention.
