using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ExampleProject
{
    public class Example
    {
        public static int EntryPoint(string pwzArgument)
        {
            string processName = Process.GetCurrentProcess().ProcessName;
            MessageBox.Show(processName);
            return 0;
        }
    }
}
