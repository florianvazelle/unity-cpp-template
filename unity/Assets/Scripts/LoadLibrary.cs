using System;
using System.Runtime.InteropServices;

public class LoadLibrary
{
    [DllImport("example")]
    public static extern int GetRandom();

    [DllImport("example")]
    public static extern int PreAllocTest(IntPtr pArrayOfDouble);

    [DllImport("example")]
    public static extern int AllocInTest(IntPtr pArrayOfDouble);

    [DllImport("example")]
    public static extern void MyFree(IntPtr pArrayOfDouble);

    [DllImport("example")]
    public static extern void Write();
}