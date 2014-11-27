# Project Structure

### Launcher.exe (native)

This injects Bootstrapper.dll into the specified process, then invokes one if its functions.

### Bootstrapper.dll (native)

This is the first dll to be injected. When invoked, this attaches to the CLR (v4.0), loads
ExampleProject.dll using it, and lastly invokes the main method of ExampleProject.

### ExampleProject.dll (managed)

This is the managed project, which is injected second. You must preserve the signature of the
entry method, but this project can otherwise modified to do whatever you wish. Since it is in
the target process' memory space, pointers can be used to access the target's data structures.
(Either via P/Invoke or unsafe code blocks.)
